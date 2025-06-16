#include "tampilan_provinsi.h"

// Mendefinisikan lebar terminal dan kotak
#define TERMINAL_WIDTH 80
#define BOX_WIDTH 56

// Fungsi ini menampilkan judul/header
void tampilan_header_provinsi(int y)
{
    const char* header = "PEMILIHAN PROVINSI"; // Teks header
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

// Fungsi ini menampilkan detail satu provinsi
void tampilan_provinsi(int idx, int y, int selected, void* selected_node)
{
    address node = (address)selected_node;
    Provinsi* provinsi_data = node->info.provinsi;

    const char* nama = get_name_provinsi(provinsi_data);
    int jumlah_bioskop = get_jumlah_bioskop_provinsi(provinsi_data);

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