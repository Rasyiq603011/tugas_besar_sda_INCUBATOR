#ifndef PROVINSI_H
#define PROVINSI_H
#include <stdlib.h>
#include <string.h>

typedef char* String;

typedef struct DataProvinsi Provinsi;

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Provinsi* constructor(const String nama, int total_pendapatan, int jumlah_bioskop);

void create_provinsi(Provinsi** new_provinsi, const String nama, int total_pendapatan, int jumlah_bioskop);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name_provinsi(Provinsi* current_provinsi);

int get_pendapatan_provinsi(Provinsi* current_provinsi);

int get_jumlah_bioskop_provinsi(Provinsi* current_provinsi);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_provinsi(Provinsi* current_provinsi, const String name);

void set_pendapatan_provinsi(Provinsi* current_provinsi, int pendapatan);

void set_jumlah_bioskop_provinsi(Provinsi* current_provinsi, int jumlah_bioskop);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_provinsi(Provinsi* current_provinsi);

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

int compare_provinsi_value(const Provinsi* provinsi_pertama, const Provinsi* provinsi_kedua);

#endif /*PROVINSI_H*/