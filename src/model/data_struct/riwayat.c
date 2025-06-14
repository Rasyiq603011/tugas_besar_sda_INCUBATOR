#include "riwayat.h"

// ===============================================
// ========= STRUCT DEFINITIONS ==================
// ===============================================

// Struktur data untuk menyimpan riwayat pembelian tiket
struct DataRiwayat {
    String judul_film;
    char tanggal[11];
    char jam[6];
    int harga_tiket;
    String kursi;
};

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

// Mengembalikan judul film dari riwayat
String get_judul_film_riwayat(Riwayat* riwayat)
{
    return riwayat->judul_film;
}

// Mengembalikan tanggal dari riwayat
String get_tanggal_riwayat(Riwayat* riwayat)
{
    return riwayat->tanggal;
}

// Mengembalikan jam dari riwayat
String get_jam_riwayat(Riwayat* riwayat)
{
    return riwayat->jam;
}

// Mengembalikan harga tiket dari riwayat
int get_harga_tiket_riwayat(Riwayat* riwayat)
{
    return riwayat->harga_tiket;
}

// Mengembalikan kursi dari riwayat
String get_kursi_riwayat(Riwayat* riwayat)
{
    return riwayat->kursi;
}

// ===============================================
// ============== MUTATOR SECTION ================
// ===============================================

// Mengatur judul film dalam riwayat
void set_judul_film_riwayat(Riwayat* riwayat, String judul_film)
{
    riwayat->judul_film = judul_film;
}

// Mengatur tanggal dalam riwayat
void set_tanggal_riwayat(Riwayat* riwayat, char tanggal[10])
{
    strcpy(riwayat->tanggal, tanggal);
}

// Mengatur jam dalam riwayat
void set_jam_riwayat(Riwayat* riwayat, char jam[5])
{
    strcpy(riwayat->jam, jam);
}

// Mengatur harga tiket dalam riwayat
void set_harga_tiket_riwayat(Riwayat* riwayat, int harga_tiket)
{
    riwayat->harga_tiket = harga_tiket;
}

// Mengatur kursi dalam riwayat
void set_kursi_riwayat(Riwayat* riwayat, String kursi)
{
    riwayat->kursi = kursi;
}

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

// Membuat objek riwayat baru dengan nilai default (next = NULL)
Riwayat* create_riwayat(String judul_film, char tanggal[10], char jam[6], int harga_tiket, String kursi)
{
    Riwayat* new_node = (Riwayat*) malloc(sizeof(Riwayat));
    new_node->judul_film = judul_film;
    strcpy(new_node->tanggal, tanggal);
    strcpy(new_node->jam, jam);
    new_node->harga_tiket = harga_tiket;
    new_node->kursi = kursi;
    return new_node; 
}

// ===============================================
// ============= DESTRUCTOR SECTION ==============
// ===============================================

// Menghapus objek riwayat dan membebaskan memori yang digunakan
void destroy_riwayat(Riwayat* riwayat)
{
    if (riwayat != NULL)
    {
        free(riwayat->judul_film); // membebaskan memori string judul film
        free(riwayat->kursi);      // membebaskan memori string kursi
        free(riwayat);             // membebaskan memori objek riwayat
    }
}