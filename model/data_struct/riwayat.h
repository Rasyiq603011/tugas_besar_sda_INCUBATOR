#ifndef RIWAYAT_H
#define RIWAYAT_H

#include <stdlib.h>
#include <string.h>

typedef char* String;

// ================================
// ======= STRUCT DECLARATION =====
// ================================

typedef struct DataRiwayat Riwayat;

// ================================
// ======= ACCESSOR SECTION =======
// ================================

String get_judul_film_riwayat(Riwayat* riwayat);
String get_tanggal_riwayat(Riwayat* riwayat);
String get_jam_riwayat(Riwayat* riwayat);
int get_harga_tiket_riwayat(Riwayat* riwayat);
String get_kursi_riwayat(Riwayat* riwayat);
Riwayat* get_next_riwayat(Riwayat* riwayat);

// ================================
// ======== MUTATOR SECTION =======
// ================================

void set_judul_film_riwayat(Riwayat* riwayat, String judul_film);
void set_tanggal_riwayat(Riwayat* riwayat, char tanggal[10]);
void set_jam_riwayat(Riwayat* riwayat, char jam[5]);
void set_harga_tiket_riwayat(Riwayat* riwayat, int harga_tiket);
void set_kursi_riwayat(Riwayat* riwayat, String kursi);
void set_next_riwayat(Riwayat* riwayat);
void add_riwayat(Riwayat** riwayat, Riwayat* new_riwayat);

// ================================
// ======= CONSTRUCTOR SECTION ====
// ================================

Riwayat* create_riwayat(String judul_film, char tanggal[10], char jam[6], int harga_tiket, String kursi);

// ================================
// ======= DESTRUCTOR SECTION =====
// ================================

void destroy_riwayat(Riwayat* riwayat);

#endif /* RIWAYAT_H */
