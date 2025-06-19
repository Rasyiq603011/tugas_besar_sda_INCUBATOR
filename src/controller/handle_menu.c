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

void handle_menu_admin(Tree* bioskop, List* film)
{
    int pilihan;
    do
    {
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
        navigasi_tree_for_admin(*bioskop, TYPE_JADWAL);
        handle_saving_data(bioskop, &film);
        break;
    case 1:
        navigasi_tree_for_admin(*bioskop, TYPE_EVENT);
        handle_saving_data(bioskop, &film);
        break;
    case 2:
        return;
    default:
        break;
    }

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
    } while (pilihan != 2);
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
        "EVENT BIOSKOP",
        "RIWAYAT",
        "LOGOUT"
    };
    const char* header = "MENU UTAMA USER";
    pilihan = handle_display_menu(jumlah_opsi, options, header);
    do
    {
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
        handle_event_bioskop(T.root, user);
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
    } while (pilihan != 3);
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

void handle_event_bioskop(address root, User* user)
{
    if (!root || !user) return;

    List* data_event = get_all_event_from_tree_node(root);
    if (!data_event || ListEmpty(*data_event)) {
        printf("Tidak ada event yang tersedia.\n");
        Sleep(1000);
        return;
    }

    pnode selected_event_node = handle_pemilihan_event(*data_event);
    if (!selected_event_node) return;

    Event* event = info_event(selected_event_node);
    if (!event) return;

    char message[128];
    snprintf(message, sizeof(message), "Apakah Anda ingin mengikuti event \"%s\"?", get_name_event(event));
    const char* opsi[] = { "IKUTI EVENT", "BATALKAN" };
    int konfirmasi = display_konfirmasi_menu("KONFIRMASI EVENT", message, opsi, 2);

    if (konfirmasi == 0) {
        Queue* antrian = get_event_queue(event);
        if (!antrian) {
            printf("❌ Gagal mengakses antrian event.\n");
            Sleep(1000);
            return;
        }

        enqueuePriority(antrian, user);
        system("cls");
        gotoxy(40, 14); printf("✅ Anda berhasil mengikuti event \"%s\"\n", get_name_event(event));
    } else {
        system("cls");
        gotoxy(40, 14); printf("❎ Anda batal mengikuti event ini.\n");
    }

    Sleep(1500);
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
            if (is_username_available(username, USER_FILE)) 
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
    destroy_user(user);
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
            if (!is_username_available(username, USER_FILE)) {
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
            if (!is_password_correct(username, password, USER_FILE)){
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
    Tree tree_data;
    List film;
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
            if (!is_username_available(username, ADMIN_FILE)) {
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
            if (!is_password_correct(username, password, ADMIN_FILE)){
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
    handle_inisialisasi_data(&tree_data, &film);
    handle_menu_admin(&tree_data, &film);
}
