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
void set_tanggal_riwayat(Riwayat* riwayat, String tanggal);
void set_jam_riwayat(Riwayat* riwayat, String jam);
void set_harga_tiket_riwayat(Riwayat* riwayat, int harga_tiket);
void set_kursi_riwayat(Riwayat* riwayat, String kursi);
void set_next_riwayat(Riwayat* riwayat, Riwayat* new_riwayat);

// ================================
// ======= CONSTRUCTOR SECTION ====
// ================================

Riwayat* create_riwayat(String judul_film, String tanggal, String jam, int harga_tiket, String kursi);

// ================================
// ======= DESTRUCTOR SECTION =====
// ================================

void destroy_riwayat(Riwayat* riwayat);

// ================================
// ========== CONVERTER ===========
// ================================

int convert_riwayat_to_array(Riwayat* head, void*** out_array); 

#endif /* RIWAYAT_H */
