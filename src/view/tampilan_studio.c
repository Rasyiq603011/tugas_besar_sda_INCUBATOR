#include "tampilan_studio.h"

// Mendefinisikan lebar terminal dan kotak
#define TERMINAL_WIDTH 80
#define BOX_WIDTH 56

// Fungsi ini menampilkan judul/header
void tampilan_header_studio(int y) 
{
    const char* header = "PEMILIHAN STUDIO"; // Teks header
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

// Fungsi ini menampilkan detail satu studio
void tampilan_studio(int idx, int y, int selected, void* pointer_head)
{
    address current_node = (address)pointer_head;
    Studio* studio_data = current_node->info.studio;
    if (studio_data == NULL) return;

    // Get the list of schedules and count them
    List* jadwal_list = get_jadwal_studio(studio_data);
    int jadwal_tersedia = 0;
    if (jadwal_list != NULL) {
        jadwal_tersedia = count_list(*jadwal_list);
    }

    const char* nama = get_name_studio(studio_data);

    char buffer_nama[100]; // Buffer untuk baris nama studio
    char buffer_jadwal[100]; // Buffer untuk baris jadwal tersedia

    // Memformat string untuk baris pertama: Nama Studio
    snprintf(buffer_nama, sizeof(buffer_nama), "%s", nama);
    // Memformat string untuk baris kedua: Jadwal Tersedia
    snprintf(buffer_jadwal, sizeof(buffer_jadwal), "Jadwal Tersedia: %d", jadwal_tersedia);

    // Menghitung posisi kolom (horizontal) 
    int pos_x = (TERMINAL_WIDTH - BOX_WIDTH) / 2;

    // Cetak border atas item
    gotoxy(pos_x, y);
    printf("------------------------------------------------------------");

    // --- Cetak Baris Pertama (Nama Studio) ---
    gotoxy(pos_x, y + 1);
    if (selected) {
        printf("| \033[1;37;44m%-*s\033[0m |", BOX_WIDTH-4, buffer_nama);
    } else {
        printf("| %-*s |", BOX_WIDTH-4, buffer_nama);
    }

    // --- Cetak Baris Kedua (Jadwal Tersedia) ---
    gotoxy(pos_x, y + 2);
    if (selected) {
        printf("| \033[1;37;44m%-*s\033[0m |", BOX_WIDTH-4, buffer_jadwal);
    } else {
        printf("| %-*s |", BOX_WIDTH-4, buffer_jadwal);
    }

    // Cetak border bawah item
    gotoxy(pos_x, y + 3);
    printf("------------------------------------------------------------");
}

