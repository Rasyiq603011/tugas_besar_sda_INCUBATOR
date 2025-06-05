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

Provinsi* constructor_provinsi();

void create_provinsi(Provinsi* new_provinsi);

String get_name_provinsi(Provinsi provinsi);

int get_pendapatan_provinsi(Provinsi current_provinsi);

String* get_film_terlaris_provinsi(Provinsi current_provinsi);

void set_name_provinsi(Provinsi* current_provinsi, String name);

void set_pendapatan_provinsi(Provinsi* current_provinsi, int pendapatan);

void set_film_terlaris_provinsi(Provinsi* current_provinsi, String film_terlaris[3]);




// ================================================
// ===================== KOTA =====================
// ================================================

typedef struct DataKota Kota;

Kota* constructor_kota();

void create_kota(Kota* new_kota);

String get_name_kota(Kota current_kota);

int get_pendapatan_kota(Kota current_kota);

String* get_film_terlaris_kota(Kota current_kota);

void set_name_kota(Kota* current_kota, String name);

void set_pendapatan_kota(Kota* current_kota, int pendapatan);

void set_film_terlaris_kota(Kota* current_kota, String film_terlaris[3]);



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


// ================================================
// ==================== User ======================
// ================================================

typedef struct DataUser User;

String get_username_user(User* user);
String get_password_user(User* user);
int get_saldo_user(User* user);
void set_username_user(User* user, String username);
void set_password_user(User* user, String password);
void set_saldo_user(User* user, int saldo);

// ================================================
// =================== Riwayat ====================
// ================================================

typedef struct DataRiwayat Riwayat;

#endif