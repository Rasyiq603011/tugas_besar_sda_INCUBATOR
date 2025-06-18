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

Jadwal* constructor_jadwal(Time waktu_start, Time Waktu_end, date tanggal, int harga_tiket, String film, int jumlah_kursi);

void create_jadwal(Jadwal** new_jadwal, Time waktu_start, Time waktu_end, date tanggal,int harga_tiket, String film, int jumlah_kursi);

boolean is_jadwal_linked(Jadwal* current_jadwal);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

Time get_waktu_start(Jadwal* current_jadwal);

Time get_waktu_end(Jadwal* current_jadwal);

date get_tanggal_tayang(Jadwal* current_jadwal);

Film* get_film(Jadwal* jadwal);

String get_film_name(Jadwal* jadwal);

int get_harga_tiket(Jadwal* current_jadwal);

int get_jumlah_tiket(Jadwal* current_jadwal);

Kursi** get_daftar_kursi(Jadwal* current_jadwal);

Kursi* get_kursi_value_by_index(Jadwal* current_jadwal, int index);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_waktu_start(Jadwal* current_jadwal, Time new_time);

void set_waktu_end(Jadwal* current_jadwal, Time new_time);

void set_tanggal_tayang(Jadwal* current_jadwal, date new_date);

void set_film_object(Jadwal* jadwal, Film* film_obj);

void set_film_title(Jadwal* jadwal, const char* title);

void set_daftar_kursi(Jadwal* current_jadwal, Kursi** new_kursi_list, int jumlah_kursi);

void set_kursi_by_index(Jadwal* current_jadwal, int index, Kursi* new_value);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_jadwal(Jadwal* current_jadwal);

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

int compare_daftar_kursi(Kursi** kursi_pertama, Kursi** kursi_kedua, int jumlah);

int compare_jadwal_value(const Jadwal* jadwal_pertama, const Jadwal* jadwal_kedua);

void reset_film(Jadwal* jadwal);

Jadwal* deep_copy_jadwal(const Jadwal* source);

#endif /*JADWAL_H*/
