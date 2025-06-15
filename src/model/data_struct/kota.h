#ifndef KOTA_H
#define KOTA_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef char* String;

typedef struct DataKota Kota;

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Kota* constructor_kota(const String nama, int total_pendapatan, int jumlah_bioskop);

void create_kota(Kota** new_kota, const String nama, int total_pendapatan, int jumlah_bioskop);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name_kota(Kota* current_kota);

int get_pendapatan_kota(Kota* current_kota);

int get_jumlah_bioskop_kota(Kota* current_kota);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_kota(Kota* current_kota, const String nama);

void set_pendapatan_kota(Kota* current_kota, int pendapatan);

void set_jumlah_bioskop_kota(Kota* current_kota, int jumlah_bioskop);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_kota(Kota* current_kota);

int compare_kota_value(const Kota* kota_pertama, const Kota* kota_kedua);

#endif /*KOTA_H*/