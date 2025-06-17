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

int scrollable_menu(void** data_array, int jumlah_item, void (*render)(int idx, int y_pos, int selected, void* data), const char* header, int tinggi_blok, int max_tampil)
{
    if (jumlah_item == 0 || data_array == NULL) 
    {
        printf("Tidak ada data untuk ditampilkan.\n");
        return 0;
    }

    int idx_terpilih = 0, key;
    int start = 0;

    do {
        system("cls");
        gotoxy(30, 11); printf("=============================================================\n");
        gotoxy(30, 12); printf("|%*s%s%*s|\n", (60 - strlen(header)) / 2, "", header, (60 - strlen(header)) / 2, "");
        gotoxy(30, 13); printf("=============================================================\n");

        if (idx_terpilih < start)
            start = idx_terpilih;
        else if (idx_terpilih >= start + max_tampil)
            start = idx_terpilih - max_tampil + 1;

        for (int i = 0; i < max_tampil; i++)
         {
            int idx = start + i;
            if (idx < jumlah_item)
             {
                int y_pos = ((41 - (max_tampil * tinggi_blok)) / 2) + i * tinggi_blok;
                render(idx, y_pos, idx == idx_terpilih, data_array[idx]);
            }
        }

        key = getch();
        if (key == 224) 
        {
            key = getch();
            if (key == 72 && idx_terpilih > 0) idx_terpilih--;
            else if (key == 80 && idx_terpilih < jumlah_item - 1) idx_terpilih++;
        }
    } while (key != 13);

    return idx_terpilih;
}

void clear_line(int y)
{
    int i;
    for ( i = 0; i < y; i++)
    {
        printf(" ");   
    }
}

void center_print(const char* text)
{
    int len = strlen(text);
    int padding = (TERMINAL_WIDTH - len) / 2;
    for (int i = 0; i < padding; i++) printf(" ");
    printf("%s\n", text);
}

void show_splashscreen() {
    const char* title[] = {
        " ██████╗██╗███╗   ██╗███████╗███╗   ███╗ █████╗ ████████╗██╗ ██████╗ ██╗   ██╗███████╗",
        "██╔════╝██║████╗  ██║██╔════╝████╗ ████║██╔══██╗╚══██╔══╝██║██╔═══██╗██║   ██║██╔════╝",
        "██║     ██║██╔██╗ ██║█████╗  ██╔████╔██║███████║   ██║   ██║██║   ██║██║   ██║█████╗  ",
        "██║     ██║██║╚██╗██║██╔══╝  ██║╚██╔╝██║██╔══██║   ██║   ██║██║▄▄ ██║██║   ██║██╔══╝  ",
        "╚██████╗██║██║ ╚████║███████╗██║ ╚═╝ ██║██║  ██║   ██║   ██║╚██████╔╝╚██████╔╝███████╗",
        " ╚═════╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝     ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚══▀▀═╝  ╚═════╝ ╚══════╝",
        NULL
    };

    system("cls");
    
    // Menampilkan judul dengan efek animasi
    printf("\033[1;96m"); // Cyan terang
    for (int i = 0; title[i] != NULL; i++) {
        center_print(title[i]);
        Sleep(200);  // Delay untuk efek animasi
    }
    printf("\033[0m");
    
    printf("\n");
    center_print("============================================================");
    center_print("          SELAMAT DATANG DI BIOSKOP KITA (VERSI FIX)        ");
    center_print("============================================================");
    printf("\n");
    
    // Efek loading sederhana
    center_print("Loading");
    for (int i = 0; i < 3; i++) {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }
    printf("\n\n");
    
    printf("\033[1;33m");
    center_print("Tekan ENTER untuk melanjutkan...");
    printf("\033[0m");
    
    getchar();
    
    system("cls");
}