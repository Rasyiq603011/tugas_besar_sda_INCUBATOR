#include "tampilan_bioskop.h"

// Mendefinisikan lebar terminal dan kotak
#define TERMINAL_WIDTH 80
#define BOX_WIDTH 56

// Fungsi ini menampilkan judul/header
void tampilan_header_bioskop(int y) 
{
    const char* header = "PEMILIHAN BIOSKOP"; // Teks header
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

// Fungsi ini menampilkan detail satu bioskop
void tampilan_bioskop(int idx, int y, int selected, void* pointer_head)
{
    address current_node = (address)pointer_head;
    Bioskop* bioskop_data = current_node->info.bioskop;

    // Menghitung jumlah studio (anak-anak dari node bioskop)
    address studio_node = current_node->first_son;
    int studio_count = 0;
    while (studio_node != NULL) {
        studio_count++;
        studio_node = studio_node->next_brother;
    }

    const char* nama = get_name_bioskop(bioskop_data);
    const char* alamat = get_alamat_bioskop(bioskop_data);

    char buffer_nama[100]; // Buffer untuk baris nama bioskop
    char buffer_alamat[100]; // Buffer untuk baris alamat

    // Memformat string untuk baris pertama: Nama (Jumlah Studio)
    snprintf(buffer_nama, sizeof(buffer_nama), "%s (%d Studio)", nama, studio_count);
    // Memformat string untuk baris kedua: Alamat
    snprintf(buffer_alamat, sizeof(buffer_alamat), "Alamat: %s", alamat);

    // Menghitung posisi kolom (horizontal)
    int pos_x = (TERMINAL_WIDTH - BOX_WIDTH) / 2;

    // Cetak border atas item
    gotoxy(pos_x, y);
    printf("------------------------------------------------------------");

    // --- Cetak Baris Pertama (Nama Bioskop) ---
    gotoxy(pos_x, y + 1);
    if (selected) {
        printf("| \033[1;37;44m%-*s\033[0m |", BOX_WIDTH-4, buffer_nama);
    } else {
        printf("| %-*s |", BOX_WIDTH-4, buffer_nama);
    }

    // --- Cetak Baris Kedua (Alamat Bioskop) ---
    gotoxy(pos_x, y + 2);
    if (selected) {
        printf("| \033[1;37;44m%-*s\033[0m |", BOX_WIDTH-4, buffer_alamat);
    } else {
        printf("| %-*s |", BOX_WIDTH-4, buffer_alamat);
    }

    // Cetak border bawah item
    gotoxy(pos_x, y + 3);
    printf("------------------------------------------------------------");
}