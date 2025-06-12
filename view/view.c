#include "view.h"

void gotoxy(int x, int y) 
{
  COORD Point;
  Point.X = x;
  Point.Y = y;
  SetConsoleCursorPosition(Out(), Point);
}

void display_menu(int opsi_terpilih, int jumlah_opsi, char *options[jumlah_opsi], char* header) 
{
    system("cls"); 
    gotoxy(30, 11); printf("============================================================\n");
    gotoxy(30, 12); printf("|%*s%s%*s|\n", (60 - strlen(header)) / 2, "", header, (60 - strlen(header)) / 2, "");
    gotoxy(30, 13); printf("============================================================\n");
    int urutan_pilihan;
    for(urutan_pilihan=0 ; urutan_pilihan<jumlah_opsi+2 ; urutan_pilihan++) 
    {
        gotoxy(30,14+urutan_pilihan);printf("|                                                          |");
    }
    gotoxy(30,16+jumlah_opsi);printf("============================================================");
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

void display_scorallable_menu(int opsi_terpilih, int jumlah_pilihan, char *options[jumlah_pilihan], int jumlah_maksimum)
{
    int urutan_opsi;
    static int start = 0;

    if (opsi_terpilih < start)
        start = opsi_terpilih;
    else if (opsi_terpilih >= start + jumlah_maksimum)
        start = opsi_terpilih - jumlah_maksimum + 1;

    gotoxy(30, 13);
    printf("============================================================");

    for (urutan_opsi = 0; urutan_opsi < jumlah_maksimum + 2; urutan_opsi++) {
        gotoxy(30, 14 + urutan_opsi);
        printf("|                                                          |");
    }

    gotoxy(30, 16 + jumlah_maksimum);
    printf("============================================================");

    // Menampilkan opsi sesuai jendela
    for (urutan_opsi = 0; urutan_opsi < jumlah_maksimum; urutan_opsi++) {
        int optionIndex = start + urutan_opsi;
        gotoxy(50, 15 + urutan_opsi);

        if (optionIndex < jumlah_pilihan) {
            if (optionIndex == opsi_terpilih) {
                printf("\033[1;37;46m%-20s\033[0m", options[optionIndex]); // Highlight
            } else {
                printf("%-20s", options[optionIndex]); // Biasa
            }
        } else {
            printf("                    "); // Bersihkan jika lewat jumlah opsi
        }
    }
}

void clear_line(int y)
{
    int i;
    for ( i = 0; i < y; i++)
    {
        printf(" ");   
    }
}
