#include "../data_struct.h"

struct DataFilm
{
    String judul;
    int harga_tiket;
    int jumlah_ditonton;
    int total_pendapatan;
    Jadwal* jadwal;
};

// Fungsi untuk mendapatkan judul film
String get_judul_film(Film* film)
{

    return film->judul;

}

// Fungsi untuk mendapatkan harga tiket
String get_harga_tiket_film(Film* film)
{

    return film->harga_tiket;

}


int get_jumlah_penonton_film(Film* film)
{

    return film->jumlah_ditonton;

}

int get_jumlah_total_pendapatan_film(Film* film)
{

    return film->total_pendapatan;

}

void set_judul_film(Film* film, String judul)
{

    film->judul = judul;

}

void set_harga_tiket_film(Film* film, int harga_tiket)
{

    film->harga_tiket = harga_tiket;

}

void set_jumlah_penonton_film(Film* film, int jumlah_ditonton)
{

    film->jumlah_ditonton = jumlah_ditonton;

}

void set_total_pendapatan_film(Film* film, int total_pendapatan)
{

    film->total_pendapatan = total_pendapatan;

}

void update_total_pendapatan_film(Film* film)
{

    film->total_pendapatan += film->harga_tiket;

}

void jumlah_ditonton(Film* film)
{

    film->jumlah_ditonton += 1;

}


Film* create_film()
{

    Film* film = (Film*) malloc(sizeof(Film));
    film->jadwal = NULL;

}



void tambah_jadwal_film(Film* film)
{

    if (film->jadwal == NULL)
    {
        film->jadwal = // Constructor struct jadwal
        return;
    }

    Jadwal* temp = film->jadwal;
    while (temp != NULL)
    {
        
    }

}