#include "handle_menu.h"

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

void handle_menu_admin()
{
    int pilihan;
    const int jumlah_opsi = 5;
    const char* options[] = {
        "TAMBAH JADWAL FILM",
        "HAPUS JADWAL FILM",
        "ATUR EVENT",
        "LOGOUT",
        "QUIT"
    };
    const char* header = "MENU UTAMA ADMIN";
    pilihan = handle_display_menu(jumlah_opsi, options, header);

    switch (pilihan)
    {
    case 0:
        /* code */
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        return; 
    case 4:
        return;
    default:
        break;
    }

}

// ===============================================
// ============== MENU USER SECTION ==============
// ===============================================

void handle_menu_user()
{
    int pilihan;
    const int jumlah_opsi = 5;
    const char* options[] = {
        "PEMBELIAN TIKET",
        "INFORMASI EVENT",
        "RIWAYAT",
        "LOGOUT",
        "QUIT"
    };
    const char* header = "MENU UTAMA USER";
    pilihan = handle_display_menu(jumlah_opsi, options, header);

    switch (pilihan)
    {
    case 0:
        /* code */
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        return; 
    case 4:
        return;
    default:
        break;
    }

}

// ===============================================
// ============== MENU AWAL SECTION ==============
// ===============================================

void handle_menu_awal()
{
    int pilihan;
    const int jumlah_opsi = 3;
    const char* options[] = {
        "MASUK SEBAGAI ADMIN",
        "MASUK SEBAGAI USER",
        "QUIT"
    };
    const char* header = "MENU SEBAGAI?";
    pilihan = handle_display_menu(jumlah_opsi, options, header);

    switch (pilihan)
    {
    case 0:
        handle_menu_admin();
        break;
    case 1:
        handle_menu_user();
        break;
    case 2:
        return; 
    default:
        break;
    }

}
