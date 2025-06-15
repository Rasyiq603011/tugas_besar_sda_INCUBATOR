#include "view.h"

void gotoxy(int x, int y) 
{
  COORD Point;
  Point.X = x;
  Point.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point);
}

void display_menu(int opsi_terpilih, int jumlah_opsi, const char *options[jumlah_opsi], const char* header) 
{
    system("cls"); 
    gotoxy(30, 11); printf("=============================================================\n");
    gotoxy(30, 12); printf("|%*s%s%*s|\n", (60 - strlen(header)) / 2, "", header, (60 - strlen(header)) / 2, "");
    gotoxy(30, 13); printf("=============================================================\n");
    int urutan_pilihan;
    for(urutan_pilihan=0 ; urutan_pilihan<jumlah_opsi+2 ; urutan_pilihan++) 
    {
        gotoxy(30,14+urutan_pilihan);printf("|                                                           |");
    }
    gotoxy(30,16+jumlah_opsi);printf("=============================================================");
    for (urutan_pilihan = 0; urutan_pilihan < jumlah_opsi; urutan_pilihan++) 
    {
        if (urutan_pilihan == opsi_terpilih) 
        {
            gotoxy(50,15+urutan_pilihan);printf("\033[1;37;46m%-20s\033[0m ", options[urutan_pilihan]); // Highlighted option
        }
         else 
         {
            gotoxy(50,15+urutan_pilihan);printf("%s", options[urutan_pilihan]);
        }
    }
}

void scrollable_menu(int jumlah_item, void (*render)(int idx, int y_pos, int selected, void* pointer_head), int tinggi_blok, int max_tampil, void* pointer_head) 
{
    int idx_terpilih = 0, key;
    int start = 0;
	
    do {
        system("cls");

        if (idx_terpilih < start)
            start = idx_terpilih;
        else if (idx_terpilih >= start + max_tampil)
            start = idx_terpilih - max_tampil + 1;
		int i;
        for (i = 0; i < max_tampil; i++) {
            int idx = start + i;
            if (idx < jumlah_item) {
                int y_pos = ((41-(max_tampil*tinggi_blok))/2) + i * tinggi_blok;
                render(idx, y_pos, idx == idx_terpilih, pointer_head);
            }
        }

        key = getch();
        if (key == 224) {
            key = getch();
            if (key == 72 && idx_terpilih > 0) idx_terpilih--;             // Panah atas
            else if (key == 80 && idx_terpilih < jumlah_item - 1) idx_terpilih++;  // Panah bawah
        }
    } while (key != 13);
}

void clear_line(int y)
{
    int i;
    for ( i = 0; i < y; i++)
    {
        printf(" ");   
    }
}
