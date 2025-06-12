#ifndef FILM_H
#define FILM_H

#include "../tree_data.h"
typedef char* String;

typedef struct DataFilm Film;

// ===================================================
// ================= ACCESSOR SECTION ================
// ===================================================

String get_judul_film(Film* film);
int get_jumlah_penonton_film(Film* film);
int get_jumlah_total_pendapatan_film(Film* film);

// ===================================================
// ================== MUTATOR SECTION ================
// ===================================================

void set_judul_film(Film* film, String judul);
void set_jumlah_penonton_film(Film* film, int jumlah_ditonton);
void update_jumlah_penonton_film(Film* film);
void set_total_pendapatan_film(Film* film, int total_pendapatan);
void update_pendapatan_film(Film* film, int harga_tiket);

// ===================================================
// ============== CONSTRUCTOR SECTION ================
// ===================================================

Film* create_film(String judul, int jumlah_ditonton, int total_pendapatan);

// ===================================================
// ============== DESTRUCTOR SECTION =================
// ===================================================

void destroy_film(Film* film);

// ===================================================
// ============== COMPARATOR SECTION =================
// ===================================================

int compare_film_value(Film* film_pertama, Film* film_kedua);

#endif
