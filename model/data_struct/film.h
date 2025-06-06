#ifndef FILM_H
#define FILM_H

typedef char* String;

typedef struct DataFilm Film;

String get_judul_film(Film* film);
// Fungsi untuk mendapatkan harga tiket
String get_harga_tiket_film(Film* film);

int get_jumlah_penonton_film(Film* film);

int get_jumlah_total_pendapatan_film(Film* film);

void set_judul_film(Film* film, String judul);

void set_harga_tiket_film(Film* film, int harga_tiket);

void set_jumlah_penonton_film(Film* film, int jumlah_ditonton);

void set_total_pendapatan_film(Film* film, int total_pendapatan);

void update_total_pendapatan_film(Film* film);

void jumlah_ditonton(Film* film);

Film* create_film();

void tambah_jadwal_film(Film* film);

#endif
