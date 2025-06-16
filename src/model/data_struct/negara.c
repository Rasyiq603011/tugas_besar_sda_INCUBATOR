#include "negara.h"
#include <stdlib.h>
#include <string.h>

struct DataNegara {
    String nama_negara;
    int total_pendapatan_negara;
    int jumlah_bioskop_negara;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Negara* constructor_negara(const String nama, int total_pendapatan, int jumlah_bioskop) {
    Negara* new_negara = (Negara*) malloc(sizeof(Negara));
    if (!new_negara) return NULL;

    new_negara->nama_negara = strdup(nama);
    if (!new_negara->nama_negara) {
        printf("strdup gagal");
        free(new_negara);
        return NULL;
    }

    new_negara->total_pendapatan_negara = total_pendapatan;
    new_negara->jumlah_bioskop_negara = jumlah_bioskop;
    return new_negara;
}

void create_negara(Negara** new_negara, const String nama, int total_pendapatan, int jumlah_bioskop)
{
    *new_negara = constructor_negara(nama, total_pendapatan, jumlah_bioskop);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name_negara(Negara* current_negara)
{
    return current_negara ? current_negara->nama_negara : "Hello";
}

int get_pendapatan_negara(Negara* current_negara)
{
    return current_negara ? current_negara->total_pendapatan_negara : -1;
}

int get_jumlah_bioskop_negara(Negara* current_negara)
{
    return current_negara ? current_negara->jumlah_bioskop_negara : -1;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_negara(Negara* current_negara, const String nama)
{
    if (current_negara && nama) 
    {
        String new_name = strdup(nama);
        if (new_name) 
        {
            free(current_negara->nama_negara);
            current_negara->nama_negara = new_name;
        }
    }
}

void set_pendapatan_negara(Negara* current_negara, int pendapatan)
{
    if (current_negara && pendapatan >= 0)
    {
        current_negara->total_pendapatan_negara = pendapatan;
    }
}

void set_jumlah_bioskop_negara(Negara* current_negara, int jumlah_bioskop)
{
    if (current_negara && jumlah_bioskop >= 0) 
    {
        current_negara->jumlah_bioskop_negara = jumlah_bioskop;
    }
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Negara* current_negara)
{
    if (current_negara) {
        free(current_negara->nama_negara);
        free(current_negara);
    }
}

int compare_value_negara(const Negara* negara_pertama, const Negara* negara_kedua) 
{
    if (!negara_pertama || !negara_kedua) {
        return 0; 
    }
    return (strcmp(negara_pertama->nama_negara, negara_kedua->nama_negara) == 0 &&
            negara_pertama->total_pendapatan_negara== negara_kedua->total_pendapatan_negara &&
            negara_pertama->jumlah_bioskop_negara== negara_kedua->jumlah_bioskop_negara);
}
