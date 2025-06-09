#ifndef JADWAL_H
#define JADWAL_H

typedef char* String;

// ================================================
// ==================== Jadwal ====================
// ================================================

typedef struct DataJadwal Jadwal;

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Jadwal* constructor_jadwal();

void create_jadwal(Jadwal* new_jadwal);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

Time get_time(Jadwal* current_jadwal);

date get_date(Jadwal* current_jadwal);

Film* get_film(Jadwal* current_jadwal);

String get_film_name(Jadwal* current_jadwal);

int get_harga_tiket(Jadwal* current_jadwal);

Kursi** get_daftar_kursi(Jadwal* current_jadwal);

Kursi* get_kursi_value_by_index(Jadwal* current_jadwal, int row, int col);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_waktu(Jadwal* current_jadwal, Time new_time);

void set_tanggal(Jadwal* current_jadwal, date new_date);

void set_nama_studio(Jadwal* current_jadwal, String new_studio_name);

void set_daftar_kursi(Jadwal* current_jadwal, Kursi* new_kursi_list);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Jadwal* current_jadwal);

#endif /*JADWAL_H*/