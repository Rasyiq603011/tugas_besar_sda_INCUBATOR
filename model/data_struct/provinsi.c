#include "provinsi.h"


struct DataProvinsi {
    String nama;
    int total_pendapatan;
    int jumlah_bioskop;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Provinsi* constructor(String nama, int total_pendapatan, int jumlah_bioskop)
{
    Provinsi* new_provinsi = (Provinsi*) malloc(sizeof(Provinsi));
    new_provinsi->nama = strdup(nama);
    new_provinsi->total_pendapatan = total_pendapatan;
    new_provinsi->jumlah_bioskop = jumlah_bioskop;
    return new_provinsi;
}

void create_provinsi(Provinsi* new_provinsi, String nama, int total_pendapatan, int jumlah_bioskop)
{
    new_provinsi = constructor(nama, total_pendapatan, jumlah_bioskop);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name(Provinsi* current_provinsi)
{
    return current_provinsi->nama;
}

int get_pendapatan_provinsi(Provinsi* current_provinsi)
{
    return current_provinsi->total_pendapatan;
}

int get_jumlah_bioskop(Provinsi* current_provinsi)
{
    return current_provinsi->jumlah_bioskop;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name(Provinsi* current_provinsi, String name)
{
    current_provinsi->nama = name;
}

void set_pendapatan(Provinsi* current_provinsi, int pendapatan)
{
    current_provinsi->total_pendapatan = pendapatan;
}

void set_jumlah_bioskop(Provinsi* current_provinsi, int jumlah_bioskop)
{
    current_provinsi->jumlah_bioskop = jumlah_bioskop;
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Provinsi* current_provinsi)
{
    free(current_provinsi->nama);
    free(current_provinsi);
}