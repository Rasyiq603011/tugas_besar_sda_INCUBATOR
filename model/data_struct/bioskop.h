#ifndef BIOSKOP_H
#define BIOSKOP_H

typedef char* String;

typedef struct DataBioskop Bioskop;

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Bioskop* constructor(String nama, int total_pendapatan, String alamat);

void create_bioskop(Bioskop* new_bioskop, String nama, int total_pendapatan, String alamat);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name(Bioskop* current_bioskop);

int get_pendapatan_bioskop(Bioskop* current_bioskop);

String* get_alamat(Bioskop* current_bioskop);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name(Bioskop* current_bioskop, String name);

void set_pendapatan(Bioskop* current_bioskop, int pendapatan);

void set_alamat(Bioskop* current_bioskop, String alamat);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Bioskop* current_bioskop);

#endif /*BIOSKOP_H*/