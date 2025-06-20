#include "controller/handle_menu.h"
#include "controller/handle_crud_tree.h"
#include "test/testing.h"

int main(int argc, char *argv[])
{
    int pilihan;
    do{
        const int jumlah_opsi = 3;
        const char* options[] = {
            "MASUK SEBAGAI ADMIN",
            "MASUK SEBAGAI USER",
            "KELUAR"
        };
        const char* header = "MASUK SEBAGAI?";
        pilihan = handle_display_menu(jumlah_opsi, options, header);

        // LOAD DATA USER

        switch (pilihan)
        {
        case 0:
            handle_login_admin();
            break;
        case 1:
            handle_menu_masuk_user();
            break;
        default:
            break;
        }
    } while (pilihan != 2);
    testing_pemilihan_kursi();
	return 0;
}


