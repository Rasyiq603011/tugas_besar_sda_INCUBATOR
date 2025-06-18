#include "tampilan_data_struct.h"

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

// Fungsi ini menampilkan detail satu provinsi
void tampilan_provinsi(int idx, int y, int selected, void* selected_node)
{
    address node = (address)selected_node;
    Provinsi* provinsi_data = node->info.provinsi;
    if (provinsi_data == NULL) return;

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

// Fungsi ini menampilkan detail satu bioskop
void tampilan_bioskop(int idx, int y, int selected, void* selected_node)
{   
    address node = (address)selected_node;
    Bioskop* bioskop_data = node->info.bioskop;
    if (bioskop_data == NULL) return;
    
    // Menghitung jumlah studio (anak-anak dari node bioskop)
    address studio_node = node->first_son;
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

#define WIDTH 60
#define X_POS (140 - WIDTH) / 2

void tampilan_jadwal(int idx, int y, int selected, void* selected_node)
{
    Jadwal* j = (Jadwal*) selected_node;
    if (j == NULL) return;

    const char *highlight_start = selected ? "\033[1;37;44m" : "";
    const char *highlight_end = selected ? "\033[0m" : "";

    char buffer[WIDTH + 1];
    char kiri[30], kanan[30];

    char*  waktu = time_to_string(get_waktu_start(j));
    char* tanggal = date_to_string(get_tanggal_tayang(j));

    if (waktu == NULL || tanggal == NULL)
    {
        if (waktu) free(waktu);
        if (tanggal) free(tanggal);
        return;
    }

    // Baris 1: Judul (kiri) & Waktu (kanan)
    gotoxy(X_POS, y);
    snprintf(kiri, sizeof(kiri), "Judul: %s", get_film_name(j));
    snprintf(kanan, sizeof(kanan), "Waktu: %s", waktu);
    snprintf(buffer, WIDTH + 1, "%-30s%-30s", kiri, kanan);
    printf("%s%-*s%s", highlight_start, WIDTH, buffer, highlight_end);

    // Baris 2: Harga Tiket (kiri) & Tanggal (kanan)
    gotoxy(X_POS, y + 1);
    snprintf(kiri, sizeof(kiri), "Harga Tiket: %d", get_harga_tiket(j));
    snprintf(kanan, sizeof(kanan), "Tanggal: %s", tanggal);
    snprintf(buffer, WIDTH + 1, "%-30s%-30s", kiri, kanan);
    printf("%s%-*s%s", highlight_start, WIDTH, buffer, highlight_end);

    free(waktu);
    free(tanggal);
}

