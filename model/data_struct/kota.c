#include "kota.h"

struct DataKota {
    String nama;
    int total_pendapatan;
    int jumlah_bioskop;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Kota* constructor(String nama, int total_pendapatan, int jumlah_bioskop)
{
    Kota* new_kota = (Kota*) malloc(sizeof(Kota));
    new_kota->nama = strdup(nama);
    new_kota->total_pendapatan = total_pendapatan;
    new_kota->jumlah_bioskop = jumlah_bioskop;
    return new_kota;
}

void create_kota(Kota* new_kota, String nama, int total_pendapatan, int jumlah_bioskop)
{
    new_kota = constructor(nama, total_pendapatan, jumlah_bioskop);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name(Kota* current_kota)
{
    return current_kota->nama;
}

int get_pendapatan_kota(Kota* current_kota)
{
    return current_kota->total_pendapatan;
}

int get_jumlah_bioskop(Kota* current_kota)
{
    return current_kota->jumlah_bioskop;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name(Kota* current_kota, String name)
{
    current_kota->nama = name;
}

void set_pendapatan(Kota* current_kota, int pendapatan)
{
    current_kota->total_pendapatan = pendapatan;
}

void set_jumlah_bioskop(Kota* current_kota, int jumlah_bioskop)
{
    current_kota->jumlah_bioskop = jumlah_bioskop;
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Kota* current_kota)
{
    free(current_kota->nama);
    free(current_kota);
}
