#include "handle_menu.h"

// ===============================================
// ============= OPTION SECTION ==================
// ===============================================

void handle_option_menu(int key, int* opsi_terpilih, int jumlah_opsi)
{
    if (key == 72) 
        {  // Panah atas
            *opsi_terpilih = (*opsi_terpilih - 1 + jumlah_opsi) % jumlah_opsi;
            Beep(1200,100);
        } 
    else if (key == 80) 
        {  // Panah bawah
            *opsi_terpilih = (*opsi_terpilih + 1) % jumlah_opsi;
            Beep(1200,100);	                
        }
}

// ===============================================
// ============= DISPLAY SECTION =================
// ===============================================

int handle_display_menu(int jumlah_opsi, const char* options[], const char* header)
{
    int key, opsi_terpilih = 0;
    while (1)
    {
	    display_menu(opsi_terpilih, jumlah_opsi, options, header);
	    key = getch();
        if (key == 0 || key == 224) 
            {
	            key = getch();
                handle_option_menu(key, &opsi_terpilih, jumlah_opsi);
	        } 
        else if (key == 13) 
            { 
	            Beep(600,100);
	            break;
	        }
    }
    return opsi_terpilih;
}

// ===============================================
// ============= MENU ADMIN SECTION ==============
// ===============================================

void handle_menu_admin(Tree bioskop)
{
    int pilihan;
    const int jumlah_opsi = 3;
    const char* options[] = {
        "MANAGEMENT JADWAL",
        "MANAGEMENT EVENT",
        "LOGOUT"
    };
    const char* header = "MENU UTAMA ADMIN";
    pilihan = handle_display_menu(jumlah_opsi, options, header);

    switch (pilihan)
    {
    case 0:
        navigasi_tree_for_admin(bioskop, TYPE_JADWAL);
        break;
    case 1:
        navigasi_tree_for_admin(bioskop, TYPE_EVENT);
        break;
    case 2:
        destroy_admin();
        return;
    default:
        break;
    }

}

// ===============================================
// ============== MENU USER SECTION ==============
// ===============================================

void handle_menu_user(User* user, Tree T)
{
    int pilihan;
    const int jumlah_opsi = 4;
    const char* options[] = {
        "PEMBELIAN TIKET",
        "INFORMASI EVENT",
        "RIWAYAT",
        "LOGOUT"
    };
    const char* header = "MENU UTAMA USER";
    pilihan = handle_display_menu(jumlah_opsi, options, header);

    switch (pilihan)
    {
    case 0:
        handle_pemilihan_provinsi(T.root, user);
        break;
    case 1:
        /* code */
        break;
    case 2:
        handle_tampilan_riwayat(user);
        break;
    case 3:
        destroy_user(user);
        delete_tree(&T);
        return; 
    default:
        break;
    }

}

void handle_menu_masuk_user()
{
    int pilihan;
    do{
        const int jumlah_opsi = 3;
        const char* options[] = {
            "LOG IN",
            "SIGN UP",
            "KEMBALI"
        };
        const char* header = "MENU UTAMA USER";
        pilihan = handle_display_menu(jumlah_opsi, options, header);

        switch (pilihan)
        {
        case 0:
            handle_login_user();
            break;
        case 1:
            handle_signup_user();
            break;
        default:
            break;
        }
    } while (pilihan != 2);

}

// ===============================================
// =============== SIGN IN/LOG IN ================
// ===============================================

void handle_signup_user()
{   
    char username[46], password[46];
    int pos, ch;
    
start_input:
    tampilan_login_signup("SIGN UP");

    // === Input Username ===
    pos = 0;
    gotoxy(43, 14);
    while (1) 
    {
        ch = getch();

        if (ch == 27) 
        { // ESC
            return;
        } 
        else if (ch == 13) 
        { 
            username[pos] = '\0';
            if (is_username_available(username, "../assets/users.json")) 
            {
            	system("cls");
                gotoxy(30, 20);
                printf("Username sudah dipakai. Masukkan username lain!");
                Sleep(1000); // windows: Sleep(ms)
                system("cls");
				tampilan_login_signup("SIGN UP");
				gotoxy(43, 14);
				pos = 0;
            } else {
                break; // lanjut ke input password
            }
        } 
        else if (ch == 8) 
        { // BACKSPACE
            if (pos > 0) {
                pos--;
                gotoxy(43 + pos, 14);
                printf(" ");
                gotoxy(43 + pos, 14);
            }
        } 
        else if (ch >= 32 && ch <= 126 && pos < 45) 
        {
            username[pos++] = ch;
            printf("%c", ch);
        }
    }

    // === Input Password ===
    pos = 0;
    gotoxy(43, 16);
    while (1) 
    {
        ch = getch();

        if (ch == 27) 
        { // ESC saat input password
            // Bersihkan password dari layar
            int i;
            for (i = 0; i < pos; i++) 
            {
                gotoxy(43 + i, 16);
                printf(" ");
            }
            gotoxy(43, 16); // reset kursor ke awal password
            // Kembali ke input username
            goto start_input;
        } 
        else if (ch == 13) 
        { // ENTER selesai
            password[pos] = '\0';
            break;
        } 
        else if (ch == 8) 
        { // BACKSPACE
            if (pos > 0) 
            {
                pos--;
                gotoxy(43 + pos, 16);
                printf(" ");
                gotoxy(43 + pos, 16);
            }
        } 
        else if (ch >= 32 && ch <= 126 && pos < 45) 
        {
            password[pos++] = ch;
            printf("*");
        }
    }

    system("cls");
    User* user = create_user(username, password, REGULER, 1000000);
    save_user_to_json(user);
    destroy_user(&user);
    gotoxy(30, 20); printf("Pendaftaran berhasil!");
    Sleep(500);
    system("cls");
    return;
}

void handle_login_user()
{
    Tree T;
    char username[46], password[46];
    int pos, ch;
    
start_input:
    tampilan_login_signup("LOG IN");

    // === Input Username ===
    pos = 0;
    gotoxy(43, 14);
    while (1) 
    {
        ch = getch();

        if (ch == 27) 
        { // ESC
            return;
        } 
        else if (ch == 13) 
        { 
            username[pos] = '\0';
            if (!is_username_available(username, "../assets/users.json")) {
            	system("cls");
                gotoxy(30, 20);
                printf("Username tidak ditemukan! Masukkan ulang username dengan benar");
                Sleep(1000); // windows: Sleep(ms)
                system("cls");
				tampilan_login_signup("LOG IN");
				gotoxy(43, 14);
				pos = 0;
            } else {
                break; // lanjut ke input password
            }
        } 
        else if (ch == 8) 
        { // BACKSPACE
            if (pos > 0) {
                pos--;
                gotoxy(43 + pos, 14);
                printf(" ");
                gotoxy(43 + pos, 14);
            }
        } 
        else if (ch >= 32 && ch <= 126 && pos < 45) 
        {
            username[pos++] = ch;
            printf("%c", ch);
        }
    }

    // === Input Password ===
    pos = 0;
    gotoxy(43, 16);
    while (1) 
    {
        ch = getch();

        if (ch == 27) 
        { // ESC saat input password
            // Bersihkan password dari layar
            int i;
            for (i = 0; i < pos; i++) 
            {
                gotoxy(43 + i, 16);
                printf(" ");
            }
            gotoxy(43, 16); // reset kursor ke awal password
            // Kembali ke input username
            goto start_input;
        } 
        else if (ch == 13) 
        { // ENTER selesai
            password[pos] = '\0';
            if (!is_password_correct(username, password, "../assets/users.json")){
            	system("cls");
            	gotoxy(30, 20); printf("Password salah! Mohon masukkan ulang password dengan benar");
                Sleep(1000); // windows: Sleep(ms)
                system("cls");
				tampilan_login_signup("LOG IN");
				gotoxy(43, 14); printf("%s", username);
				gotoxy(43, 16);
				pos = 0; 	
			}else{
				break;
			}
        } 
        else if (ch == 8) 
        { // BACKSPACE
            if (pos > 0) 
            {
                pos--;
                gotoxy(43 + pos, 16);
                printf(" ");
                gotoxy(43 + pos, 16);
            }
        } 
        else if (ch >= 32 && ch <= 126 && pos < 45) 
        {
            password[pos++] = ch;
            printf("*");
        }
    }
    // T.root = load_tree_from_file()
    User* user = load_user_from_json(username);
    handle_menu_user(user, T);
}

void handle_login_admin()
{
    Tree T;
    char username[46], password[46];
    int pos, ch;
    
start_input:
    tampilan_login_signup("LOG IN");

    // === Input Username ===
    pos = 0;
    gotoxy(43, 14);
    while (1) 
    {
        ch = getch();

        if (ch == 27) 
        { // ESC
            return;
        } 
        else if (ch == 13) 
        { 
            username[pos] = '\0';
            if (!is_username_available(username, "../assets/admin.json")) {
            	system("cls");
                gotoxy(30, 20);
                printf("Username tidak ditemukan! Masukkan ulang username dengan benar");
                Sleep(1000); // windows: Sleep(ms)
                system("cls");
				tampilan_login_signup("LOG IN");
				gotoxy(43, 14);
				pos = 0;
            } else {
                break; // lanjut ke input password
            }
        } 
        else if (ch == 8) 
        { // BACKSPACE
            if (pos > 0) {
                pos--;
                gotoxy(43 + pos, 14);
                printf(" ");
                gotoxy(43 + pos, 14);
            }
        } 
        else if (ch >= 32 && ch <= 126 && pos < 45) 
        {
            username[pos++] = ch;
            printf("%c", ch);
        }
    }

    // === Input Password ===
    pos = 0;
    gotoxy(43, 16);
    while (1) 
    {
        ch = getch();

        if (ch == 27) 
        { // ESC saat input password
            // Bersihkan password dari layar
            int i;
            for (i = 0; i < pos; i++) 
            {
                gotoxy(43 + i, 16);
                printf(" ");
            }
            gotoxy(43, 16); // reset kursor ke awal password
            // Kembali ke input username
            goto start_input;
        } 
        else if (ch == 13) 
        { // ENTER selesai
            password[pos] = '\0';
            if (!is_password_correct(username, password, "../assets/admin.json")){
            	system("cls");
            	gotoxy(30, 20); printf("Password salah! Mohon masukkan ulang password dengan benar");
                Sleep(1000); // windows: Sleep(ms)
                system("cls");
				tampilan_login_signup("LOG IN");
				gotoxy(43, 14); printf("%s", username);
				gotoxy(43, 16);
				pos = 0; 	
			}else{
				break;
			}
        } 
        else if (ch == 8) 
        { // BACKSPACE
            if (pos > 0) 
            {
                pos--;
                gotoxy(43 + pos, 16);
                printf(" ");
                gotoxy(43 + pos, 16);
            }
        } 
        else if (ch >= 32 && ch <= 126 && pos < 45) 
        {
            password[pos++] = ch;
            printf("*");
        }
    }
    // T.root = load_tree_from_file()
    /*Panggil Menu Utama Admin*/ 
}