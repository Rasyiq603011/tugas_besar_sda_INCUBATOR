#include "tampilan_kota.h"

// Mendefinisikan lebar terminal dan kotak
#define TERMINAL_WIDTH 160
#define BOX_WIDTH 60

// Fungsi ini menampilkan detail satu kota
void tampilan_kota(int idx, int y, int selected, void* selected_node)
{
    address node = (address)selected_node;
    Kota* kota_data = node->info.kota;
    if (kota_data == NULL) return;

    const char* nama = get_name_kota(kota_data);
    int jumlah_bioskop = get_jumlah_bioskop_kota(kota_data);

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
