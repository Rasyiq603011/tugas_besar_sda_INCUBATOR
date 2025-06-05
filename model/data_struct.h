#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#define MAX_CHAR
#include "boolean.h"
#include <stdbool.h>
#include <string.h>
#include "date.h"
#include "time.h"
#define MAX_ROW 10
#define MAX_COL 30

typedef enum{
    TYPE_BRONZE,
    TYPE_SILVER,
    TYPE_GOLD
}KursiType;

typedef char* String;

// ================================================
// ==================== NEGARA ====================
// ================================================

typedef struct DataNegara Negara;

Negara *get_negara();

void set_negara(Negara N);




// ================================================
// =================== PROVINSI ===================
// ================================================

typedef struct DataNegara Provinsi;






// ================================================
// ===================== KOTA =====================
// ================================================

typedef struct DataKota Kota;





// ===============================================
// =================== BIOSKOP ===================
// ===============================================

typedef struct DataBioskop Bioskop;

Bioskop* constructor_bioskop();

void create_bioskop(Bioskop* new_bioskop);

String get_name(Bioskop current_bioskop);

int get_pendapatan_bioskop(Bioskop current_bioskop);

String* get_film_terlaris(Bioskop current_bioskop);

void set_name(Bioskop* current_bioskop, String name);

void set_pendapatan(Bioskop* current_bioskop, int pendapatan);

void set_film_telaris(Bioskop* current_bioskop, String film_terlaris[3]);

// ================================================
// ===================== FILM =====================
// ================================================

typedef struct DataFilm Film;




// ================================================
// ==================== Jadwal ====================
// ================================================

typedef struct DataJadwal Jadwal;

Jadwal* constructor_jadwal();

void create_jadwal(Jadwal* new_jadwal);

Time get_time(Jadwal current_jadwal);

date get_date(Jadwal current_jadwal);

String get_studio_name(Jadwal current_jadwal);

Kursi** get_daftar_kursi(Jadwal current_jadwal);

void set_waktu(Jadwal* current_jadwal, Time new_time);

void set_tanggal(Jadwal* current_jadwal, date new_date);

void set_nama_studio(Jadwal* current_jadwal, String new_studio_name);

void set_daftar_kursi(Jadwal* current_jadwal, Kursi* new_kursi_list);

// ================================================
// ==================== Kursi =====================
// ================================================

typedef struct DataKursi Kursi;




#endif