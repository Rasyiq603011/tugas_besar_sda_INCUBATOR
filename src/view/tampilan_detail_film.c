#include "tampilan_detail_film.h"

#define TERMINAL_WIDTH 160
#define BOX_WIDTH 60

// Fungsi ini menampilkan detail satu jadwal film
void tampilan_detail_film(int idx, int y, int selected, void* selected_node)
{
    Jadwal* jadwal_data = (Jadwal*)selected_node;
    if (jadwal_data == NULL) return;

    const char* judul_film = get_film_name(jadwal_data);
    Time waktu_start = get_waktu_start(jadwal_data);
    Time waktu_end = get_waktu_end(jadwal_data);
    date tanggal_tayang = get_tanggal_tayang(jadwal_data);
    int harga_tiket = get_harga_tiket(jadwal_data);

    char buffer_waktu[50];
    char buffer_tanggal[50];
    char buffer_harga[50];

    // Format waktu (contoh: 11.00 - 13.00)
    snprintf(buffer_waktu, sizeof(buffer_waktu), "Waktu: %02d.%02d - %02d.%02d", 
             waktu_start.hour, waktu_start.minute, waktu_end.hour, waktu_end.minute);

    // Format tanggal (contoh: 2 Maret 2026)
    char hari_str[5];
    char bulan_str[20];
    get_day_name(tanggal_tayang.dayOfWeek, hari_str);
    get_month_name(tanggal_tayang.month, bulan_str);
    snprintf(buffer_tanggal, sizeof(buffer_tanggal), "Tanggal: %d %s %d", 
             tanggal_tayang.day, bulan_str, tanggal_tayang.year);
    
    // Format harga tiket
    snprintf(buffer_harga, sizeof(buffer_harga), "Harga Tiket: %d", harga_tiket);

    // Menghitung posisi kolom (horizontal)
    int pos_x = (TERMINAL_WIDTH - BOX_WIDTH) / 2;

    // Cetak border atas item
    gotoxy(pos_x, y);
    printf("----------------------------------------------------------------------");

    // --- Cetak Baris Pertama (Judul Film) ---
    gotoxy(pos_x, y + 1);
    if (selected) {
        printf("| \033[1;37;44mJudul: %-*s\033[0m |", BOX_WIDTH - 15, judul_film);
    } else {
        printf("| Judul: %-*s |", BOX_WIDTH - 15, judul_film);
    }

    // --- Cetak Baris Kedua (Usia) ---
    gotoxy(pos_x, y + 2);
    // Asumsi: tidak ada data usia di struct Film/Jadwal. Menampilkan placeholder.
    if (selected) {
        printf("| \033[1;37;44mUsia: %-*s\033[0m |", BOX_WIDTH - 12, "Informasi Usia Tidak Tersedia");
    } else {
        printf("| Usia: %-*s |", BOX_WIDTH - 12, "Informasi Usia Tidak Tersedia");
    }

    // --- Cetak Baris Ketiga (Harga Tiket dan Waktu) ---
    gotoxy(pos_x, y + 3);
    if (selected) {
        printf("| \033[1;37;44m%-*s%-*s\033[0m |", (BOX_WIDTH - 4) / 2, buffer_harga, (BOX_WIDTH - 4) / 2, buffer_waktu);
    } else {
        printf("| %-*s%-*s |", (BOX_WIDTH - 4) / 2, buffer_harga, (BOX_WIDTH - 4) / 2, buffer_waktu);
    }

    // --- Cetak Baris Keempat (Tanggal) ---
    gotoxy(pos_x, y + 4);
    if (selected) {
        printf("| \033[1;37;44m%-*s\033[0m |", BOX_WIDTH - 4, buffer_tanggal);
    } else {
        printf("| %-*s |", BOX_WIDTH - 4, buffer_tanggal);
    }

    // Cetak border bawah item
    gotoxy(pos_x, y + 5);
    printf("----------------------------------------------------------------------");
}

