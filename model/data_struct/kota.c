#include "kota.h"

struct DataKota{
    String nama;
    int total_pendapatan;
    String film_terlaris[3];
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Kota* constructor_kota()
{
    Kota* new_kota;

    return new_kota;
}

void create_kota(Kota* new_kota)
{
    new_kota = constructor_kota();
}
// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name_kota(Kota current_kota)
{
    return current_kota.nama;
}

int get_pendapatan_kota(Kota current_kota)
{
    return current_kota.total_pendapatan;
}

String* get_film_terlaris_kota(Kota current_kota)
{
    return current_kota.film_terlaris;
}


// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_kota(Kota* current_kota, String name)
{
    current_kota->nama = name;
}

void set_pendapatan_kota(Kota* current_kota, int pendapatan)
{
    current_kota->total_pendapatan = pendapatan;
}

void set_film_terlaris_kota(Kota* current_kota, String film_terlaris[3])
{
    current_kota->film_terlaris[0] = film_terlaris[0];
    current_kota->film_terlaris[1] = film_terlaris[1];
    current_kota->film_terlaris[2] = film_terlaris[2];
}
// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================
