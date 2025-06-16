#include "tampilan_kota.h"

// Mendefinisikan lebar terminal dan kotak
#define TERMINAL_WIDTH 80
#define BOX_WIDTH 56

// Fungsi ini menampilkan judul/header
void tampilan_header_kota(int y) 
{
    const char* header = "PEMILIHAN KOTA"; // Teks header
    int header_len = strlen(header); // Panjang teks header
    int pos_x = (TERMINAL_WIDTH - BOX_WIDTH) / 2;
    
    // Cetak border atas
    gotoxy(pos_x, y);
    printf("============================================================");
    
    // Cetak header
    gotoxy(pos_x + (BOX_WIDTH - header_len) / 2, y + 1);
    printf("| %s |", header);
    
    // Cetak border bawah header
    gotoxy(pos_x, y + 2);
    printf("============================================================");
}

// Fungsi ini menampilkan detail satu kota
void tampilan_kota(int idx, int y, int selected, void* pointer_head)
{
    address current_node = (address)pointer_head;
    Kota* kota_data = current_node->info.kota;

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
