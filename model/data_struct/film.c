#include "film.h"

// ===================================================
// ============= STRUCT DEFINITIONS ==================
// ===================================================

// Struktur data untuk menyimpan informasi film
struct DataFilm
{
    String judul;
    int jumlah_ditonton;
    int total_pendapatan;
};

// ===================================================
// ================= ACCESSOR SECTION ================
// ===================================================

// Mengembalikan judul film
String get_judul_film(Film* film)
{
    return film->judul;
}

// Mengembalikan jumlah penonton film
int get_jumlah_penonton_film(Film* film)
{
    return film->jumlah_ditonton;
}

// Mengembalikan total pendapatan dari film
int get_jumlah_total_pendapatan_film(Film* film)
{
    return film->total_pendapatan;
}

// ===================================================
// ================== MUTATOR SECTION ================
// ===================================================

// Mengatur judul film
void set_judul_film(Film* film, String judul)
{
    film->judul = judul;
}

// Mengatur jumlah penonton film
void set_jumlah_penonton_film(Film* film, int jumlah_ditonton)
{
    film->jumlah_ditonton = jumlah_ditonton;
}

// Mengatur total pendapatan film
void set_total_pendapatan_film(Film* film, int total_pendapatan)
{
    film->total_pendapatan = total_pendapatan;
}

// Menambahkan pendapatan berdasarkan harga tiket
void update_pendapatan_film(Film* film, int harga_tiket)
{
    film->total_pendapatan += harga_tiket;
}

// ===================================================
// ============== CONSTRUCTOR SECTION ================
// ===================================================

// Membuat objek film baru dengan judul, jumlah penonton, dan pendapatan awal
Film* create_film(String judul, int jumlah_ditonton, int total_pendapatan)
{
    Film* new_film = (Film*) malloc(sizeof(Film));
    new_film->judul = judul;
    new_film->jumlah_ditonton = jumlah_ditonton;
    new_film->total_pendapatan = total_pendapatan;
    return new_film;
}

// ===================================================
// ============== DESTRUCTOR SECTION =================
// ===================================================

void destroy_film(Film* film)
{
    if (film != NULL)
    {
        free(film->judul);
        free(film);
    }
}