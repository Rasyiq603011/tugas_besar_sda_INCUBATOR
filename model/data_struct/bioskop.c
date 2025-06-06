#include "bioskop.h"

struct DataBioskop{
    String nama;
    int total_pendapatan;
    String film_terlaris[3];
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Bioskop* constructor_bioskop()
{
    Bioskop* new_bioskop;

    return new_bioskop;
}

void create_bioskop(Bioskop* new_bioskop)
{
    new_bioskop = constructor_bioskop();
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name(Bioskop current_bioskop)
{
    return current_bioskop.nama;
}

int get_pendapatan_bioskop(Bioskop current_bioskop)
{
    return current_bioskop.total_pendapatan;
}

String* get_film_terlaris(Bioskop current_bioskop)
{
    return current_bioskop.film_terlaris;
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

void set_film_telaris(Bioskop* current_bioskop, String film_terlaris[3])
{
    current_bioskop->film_terlaris[0] = film_terlaris[0];
    current_bioskop->film_terlaris[1] = film_terlaris[1];
    current_bioskop->film_terlaris[2] = film_terlaris[2];
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================