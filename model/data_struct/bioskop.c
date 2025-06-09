#include "bioskop.h"

struct DataBioskop{
    String nama;
    int total_pendapatan;
    String alamat;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Bioskop* constructor(String nama, int total_pendapatan, String alamat)
{
    Bioskop* new_bioskop = (Bioskop*) malloc(sizeof(Bioskop));
    new_bioskop->nama = strdup(nama);
    new_bioskop->total_pendapatan = total_pendapatan;
    new_bioskop->alamat = strdup(alamat);
    return new_bioskop;
}

void create_bioskop(Bioskop* new_bioskop, String nama, int total_pendapatan, String alamat)
{
    new_bioskop = constructor_bioskop(nama, total_pendapatan, alamat);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name(Bioskop* current_bioskop)
{
    return current_bioskop->nama;
}

int get_pendapatan_bioskop(Bioskop* current_bioskop)
{
    return current_bioskop->total_pendapatan;
}

String* get_alamat(Bioskop* current_bioskop)
{
    return current_bioskop->alamat;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name(Bioskop* current_bioskop, String name)
{
    current_bioskop->nama = name;
}

void set_pendapatan(Bioskop* current_bioskop, int pendapatan)
{
    current_bioskop->total_pendapatan;
}

void set_alamat(Bioskop* current_bioskop, String alamat)
{
    current_bioskop->alamat = alamat;
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Bioskop* current_bioskop)
{
    free(current_bioskop->nama);
    free(current_bioskop->total_pendapatan);
    free(current_bioskop->alamat);
}