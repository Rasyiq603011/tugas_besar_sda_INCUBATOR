#ifndef BIOSKOP_H
#define BIOSKOP_H
#include <stdlib.h>
#include <string.h>

typedef char* String;

typedef struct DataBioskop Bioskop;

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Bioskop* constructor_bioskop(const String nama, int total_pendapatan, const String alamat);

void create_bioskop(Bioskop** new_bioskop, const String nama, int total_pendapatan, const String alamat);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

const String get_name_bioskop(const Bioskop* bioskop);

int get_pendapatan_bioskop(const Bioskop* bioskop);

const String get_alamat_bioskop(const Bioskop* bioskop);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_bioskop(Bioskop* bioskop, const String name);

void set_pendapatan_bioskop(Bioskop* bioskop, int pendapatan);

void set_alamat_bioskop(Bioskop* bioskop, const String alamat);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_bioskop(Bioskop* bioskop);

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

int compare_pendapatan_bioskop(Bioskop* bioskop_pertama, Bioskop* bioskop_kedua);

int compare_value_bioskop(Bioskop* bioskop_pertama, Bioskop* bioskop_kedua);

#endif /*BIOSKOP_H*/