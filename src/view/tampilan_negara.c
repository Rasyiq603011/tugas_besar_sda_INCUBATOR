#include "tampilan_negara.h"

// Mendefinisikan lebar terminal dan kotak
#define TERMINAL_WIDTH 160
#define BOX_WIDTH 60

// Fungsi ini menampilkan detail satu negara
void tampilan_negara(int idx, int y, int selected, void* selected_node)
{   
    address node = (address)selected_node;
    Negara* negara_data = node->info.negara;
    if (negara_data == NULL) return;
    
    const char* nama = get_name_negara(negara_data);
    int jumlah_bioskop = get_jumlah_bioskop_negara(negara_data);

    char buffer[100];
    snprintf(buffer, sizeof(buffer), "%s Jumlah Bioskop: %d", nama, jumlah_bioskop);

    // Menghitung posisi kolom (horizontal) 
    int pos_x = (TERMINAL_WIDTH - BOX_WIDTH) / 2;

    // Cetak border atas item
    gotoxy(pos_x, y);
    printf("------------------------------------------------------------");

    // Cetak konten item
    gotoxy(pos_x, y + 1);
    if (selected) 
    {
        printf("| \033[1;37;44m%-*s\033[0m |", BOX_WIDTH-4, buffer);
    } else 
    {
        printf("| %-*s |", BOX_WIDTH-4, buffer);
    }

    // Cetak border bawah item
    gotoxy(pos_x, y + 2);
    printf("------------------------------------------------------------");
}