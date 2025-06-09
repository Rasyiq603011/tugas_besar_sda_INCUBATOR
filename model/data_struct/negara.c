#include "negara.h"
#include <stdlib.h>
#include <string.h>

struct DataNegara {
    String nama;
    int total_pendapatan;
    String film_terlaris[3];
    int jumlah_bioskop;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Negara* constructor(String nama, int total_pendapatan, String film_terlaris[3], int jumlah_bioskop)
{
    Negara* new_negara = (Negara*) malloc(sizeof(Negara));
    new_negara->nama = strdup(nama);
    new_negara->total_pendapatan = total_pendapatan;
    new_negara->film_terlaris[0] = strdup(film_terlaris[0]);
    new_negara->film_terlaris[1] = strdup(film_terlaris[1]);
    new_negara->film_terlaris[2] = strdup(film_terlaris[2]);
    new_negara->jumlah_bioskop = jumlah_bioskop;
    return new_negara;
}

void create_negara(Negara* new_negara, String nama, int total_pendapatan, String film_terlaris[3], int jumlah_bioskop)
{
    new_negara = constructor(nama, total_pendapatan, film_terlaris, jumlah_bioskop);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name(Negara current_negara)
{
    return current_negara.nama;
}

int get_pendapatan_negara(Negara current_negara)
{
    return current_negara.total_pendapatan;
}

String* get_film_terlaris(Negara current_negara)
{
    return current_negara.film_terlaris;
}

int get_jumlah_bioskop(Negara current_negara)
{
    return current_negara.jumlah_bioskop;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name(Negara* current_negara, String name)
{
    current_negara->nama = name;
}

void set_pendapatan(Negara* current_negara, int pendapatan)
{
    current_negara->total_pendapatan = pendapatan;
}

void set_film_terlaris(Negara* current_negara, String film_terlaris[3])
{
    // Free existing strings if any
    if (current_negara->film_terlaris[0] != NULL) free(current_negara->film_terlaris[0]);
    if (current_negara->film_terlaris[1] != NULL) free(current_negara->film_terlaris[1]);
    if (current_negara->film_terlaris[2] != NULL) free(current_negara->film_terlaris[2]);
    
    // Copy new strings
    current_negara->film_terlaris[0] = strdup(film_terlaris[0]);
    current_negara->film_terlaris[1] = strdup(film_terlaris[1]);
    current_negara->film_terlaris[2] = strdup(film_terlaris[2]);
}

void set_jumlah_bioskop(Negara* current_negara, int jumlah_bioskop)
{
    current_negara->jumlah_bioskop = jumlah_bioskop;
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Negara* current_negara)
{
    free(current_negara->nama);
    free(current_negara->film_terlaris[0]);
    free(current_negara->film_terlaris[1]);
    free(current_negara->film_terlaris[2]);
    free(current_negara);
}