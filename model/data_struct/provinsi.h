#ifndef PROVINSI_H
#define PROVINSI_H

typedef char* String;

typedef struct DataProvinsi Provinsi;

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Provinsi* constructor(String nama, int total_pendapatan, int jumlah_bioskop);

void create_provinsi(Provinsi* new_provinsi, String nama, int total_pendapatan, int jumlah_bioskop);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name(Provinsi* current_provinsi);

int get_pendapatan_provinsi(Provinsi* current_provinsi);

int get_jumlah_bioskop(Provinsi* current_provinsi);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name(Provinsi* current_provinsi, String name);

void set_pendapatan(Provinsi* current_provinsi, int pendapatan);

void set_jumlah_bioskop(Provinsi* current_provinsi, int jumlah_bioskop);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Provinsi* current_provinsi);

#endif /*PROVINSI_H*/