#ifndef JADWAL_H
#define JADWAL_H
#include "kursi.h"
#include "film.h"
#include "../date.h"
#include "../time_adt.h"

typedef char* String;

typedef struct DataJadwal Jadwal;


// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Jadwal* constructor_jadwal(Time waktu, date tanggal,int harga_tiket, Film* film, int jumlah_kursi);

void create_jadwal(Jadwal** new_jadwal, Time waktu, date tanggal,int harga_tiket, Film* film, int jumlah_kursi);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

Time get_waktu_tayang(Jadwal* current_jadwal);

date get_tanggal_tayang(Jadwal* current_jadwal);

Film* get_film(Jadwal* current_jadwal);

String get_film_name(Jadwal* current_jadwal);

int get_harga_tiket(Jadwal* current_jadwal);

int get_jumlah_tiket(Jadwal* current_jadwal);

Kursi** get_daftar_kursi(Jadwal* current_jadwal);

Kursi* get_kursi_value_by_index(Jadwal* current_jadwal, int index);
// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_waktu_tayang(Jadwal* current_jadwal, Time new_time);

void set_tanggal_tayang(Jadwal* current_jadwal, date new_date);

void set_film(Jadwal* current_jadwal, Film* new_film);

void set_daftar_kursi(Jadwal* current_jadwal, Kursi** new_kursi_list, int jumlah_kursi);

void set_kursi_by_index(Jadwal* current_jadwal, int index, Kursi* new_value);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_jadwal(Jadwal* current_jadwal);

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

int compare_time(const Time* t1, const Time* t2);

int compare_date(const date* d1, const date* d2);

int compare_daftar_kursi(Kursi** kursi_pertama, Kursi** kursi_kedua, int jumlah);

int compare_jadwal_value(const Jadwal* jadwal_pertama, const Jadwal* jadwal_kedua);

#endif /*JADWAL_H*/