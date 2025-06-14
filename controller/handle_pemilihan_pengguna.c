#include <handle_pemilihan_pengguna.h>

void handle_pemilihan_pengguna()
{
    int key;
    int jumlah_opsi = 2;
    const char *options[] = {"User", "Admin", "Keluar"};
    int opsi_terpilih = 0;
    
	do{
		system("cls");
		display_menu(opsi_terpilih, jumlah_opsi, options, "Cinematique");
		
		key = getch();
		if (key == 224) {
	    	key = getch();
		    if (key == 72) { // panah atas
		        opsi_terpilih = (opsi_terpilih - 1 + jumlah_opsi) % jumlah_opsi;
		    }
		    else if (key == 80) { // panah bawah
		        opsi_terpilih = (opsi_terpilih + 1) % jumlah_opsi;
		    }
		}
		
	}while (key != 13);	

    switch (opsi_terpilih)
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
    default:
        break;
    }
}