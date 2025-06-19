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
    if (film == NULL) return "";
    return film->judul ? film->judul : "";
}

// Mengembalikan jumlah penonton film
int get_jumlah_penonton_film(Film* film)
{
    if (film == NULL) return 0;
    return film->jumlah_ditonton;
}

// Mengembalikan total pendapatan dari film
int get_jumlah_total_pendapatan_film(Film* film)
{
    if (film == NULL) return 0;
    return film->total_pendapatan;
}

// ===================================================
// ================== MUTATOR SECTION ================
// ===================================================

// Mengatur judul film
void set_judul_film(Film* film, String judul)
{
    if (film == NULL || judul == NULL) return;
    if (film->judul != NULL) free(film->judul);
    film->judul = strdup(judul);
}


// Mengatur jumlah penonton film
void set_jumlah_penonton_film(Film* film, int jumlah_ditonton)
{
    if (film == NULL || jumlah_ditonton < 0) return;
    film->jumlah_ditonton = jumlah_ditonton;
}

void update_jumlah_penonton_film(Film* film)
{
    if (film == NULL) return;
    film->jumlah_ditonton++;
}

// Mengatur total pendapatan film
void set_total_pendapatan_film(Film* film, int total_pendapatan)
{
    film->total_pendapatan = total_pendapatan;
}

// Menambahkan pendapatan berdasarkan harga tiket
void update_pendapatan_film(Film* film, int harga_tiket)
{
    if (film == NULL || harga_tiket < 0) return;
    film->total_pendapatan += harga_tiket;
}

// ===================================================
// ============== CONSTRUCTOR SECTION ================
// ===================================================

// Membuat objek film baru dengan judul, jumlah penonton, dan pendapatan awal
Film* create_film(String judul, int jumlah_ditonton, int total_pendapatan)
{
    if (judul == NULL || jumlah_ditonton < 0) return NULL;

    Film* new_film = (Film*)malloc(sizeof(Film));
    if (new_film == NULL) return NULL;

    new_film->judul = strdup(judul); 
    if (new_film->judul == NULL) {
        free(new_film);
        return NULL;
    }
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
    	printf("free 1");
        free(film->judul);
        printf("free 2");
		film->judul = NULL;
		printf("free 3");
        free(film);
    }
}

// ===================================================
// ============== COMPARATOR SECTION =================
// ===================================================

int compare_film_value(Film* film_pertama, Film* film_kedua)
{
    return (strcmp(film_pertama->judul, film_kedua->judul) == 0);
}

// ===================================================
// ================== COPY SECTION ===================
// ===================================================

// Melakukan deep copy pada objek Film
Film* deep_copy_film(Film* source)
{
    if (source == NULL) return NULL;

    Film* copy = (Film*)malloc(sizeof(Film));
    if (copy == NULL) return NULL;

    copy->judul = strdup(source->judul);
    if (copy->judul == NULL) {
        free(copy);
        return NULL;
    }

    copy->jumlah_ditonton = source->jumlah_ditonton;
    copy->total_pendapatan = source->total_pendapatan;

    return copy;
}
