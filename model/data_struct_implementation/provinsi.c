#include "../data_struct.h"

struct DataProvinsi{
    String nama;
    int jumlah_bioskop;
    int total_pendapatan;
    String leaderboard_bioskop[3];
    String film_terlaris[3];
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Provinsi* constructor_provinsi()
{
    Provinsi* new_provinsi;

    return new_provinsi;
}

void create_provinsi(Provinsi* new_provinsi)
{
    new_provinsi = constructor();
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name_provinsi(Provinsi current_provinsi)
{
    return current_provinsi.nama;
}

int get_pendapatan_provinsi(Provinsi current_provinsi)
{
    return current_provinsi.total_pendapatan;
}

String* get_film_terlaris_provinsi(Provinsi current_provinsi)
{
    return current_provinsi.film_terlaris;
}
// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_provinsi(Provinsi* current_provinsi, String name)
{
    current_provinsi->nama = name;
}
void set_pendapatan_provinsi(Provinsi* current_provinsi, int pendapatan)
{
    current_provinsi->total_pendapatan = pendapatan;
}

void set_film_terlaris_provinsi(Provinsi* current_provinsi, String film_terlaris[3])
{
    current_provinsi->film_terlaris[0] = film_terlaris[0];
    current_provinsi->film_terlaris[1] = film_terlaris[1];
    current_provinsi->film_terlaris[2] = film_terlaris[2];
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================