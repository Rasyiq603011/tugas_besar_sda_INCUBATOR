#include "bioskop.h"

struct DataBioskop{
    String nama_bioskop;
    int total_pendapatan_bioskop;
    String alamat_bioskop;
};

static char* strdup_safe(const char* src) {
    if (!src) return NULL;
    char* copy = malloc(strlen(src) + 1);
    char* copy = malloc(strlen(src) + 1);
    if (!copy) return NULL;
    strcpy(copy, src);
    return copy;
}

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Bioskop* constructor_bioskop(const String nama, int total_pendapatan, const String alamat)
{
    if (!nama || !alamat || total_pendapatan < 0) 
    {
        return NULL;
    }

    Bioskop* bioskop = (Bioskop*)malloc(sizeof(Bioskop));
    if (!bioskop) 
    {
        return NULL;
    }

    bioskop->nama_bioskop = strdup_safe(nama);
    bioskop->total_pendapatan_bioskop = total_pendapatan;
    bioskop->alamat_bioskop = strdup_safe(alamat);

    if (!bioskop->nama_bioskop || !bioskop->alamat_bioskop) 
    {
        destructor_bioskop(bioskop);
        return NULL;
    }

    return bioskop;
}

void create_bioskop(Bioskop** new_bioskop, const String nama, int total_pendapatan, const String alamat)
{
    *new_bioskop = constructor_bioskop(nama, total_pendapatan, alamat);

}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

const String get_name_bioskop(const Bioskop* bioskop)
{
    if (!bioskop) return NULL;
    return bioskop->nama_bioskop;
}

int get_pendapatan_bioskop(const Bioskop* bioskop) 
{
    if (!bioskop) return -1;
    return bioskop->total_pendapatan_bioskop;
}

const String get_alamat_bioskop(const Bioskop* bioskop) 
{
    if (!bioskop) return NULL;
    return bioskop->alamat_bioskop;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_bioskop(Bioskop* bioskop, const String name) 
{
    if (!bioskop || !name) return;
    String new_name = strdup_safe(name);
    if (new_name) 
    {
        free(bioskop->nama_bioskop);
        bioskop->nama_bioskop = new_name;
    }
}

void set_pendapatan_bioskop(Bioskop* bioskop, int pendapatan) 
{
    if (!bioskop || pendapatan < 0) return;
    bioskop->total_pendapatan_bioskop = pendapatan;
}

void set_alamat_bioskop(Bioskop* bioskop, const String alamat) 
{
    if (!bioskop || !alamat) return;
    String new_alamat = strdup_safe(alamat);
    if (new_alamat) 
    {
        free(bioskop->alamat_bioskop);
        bioskop->alamat_bioskop = new_alamat;
    }
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_bioskop(Bioskop* bioskop)
{
    if (!bioskop) return;
    free(bioskop->nama_bioskop);
    bioskop->nama_bioskop = NULL;
    free(bioskop->alamat_bioskop);
    bioskop->alamat_bioskop = NULL;
    free(bioskop);
}

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

int compare_pendapatan_bioskop(Bioskop* bioskop_pertama, Bioskop* bioskop_kedua)
{
if (!bioskop_pertama || !bioskop_kedua) return 0; 
    if (bioskop_pertama->total_pendapatan_bioskop < bioskop_kedua->total_pendapatan_bioskop) return -1;
    if (bioskop_pertama->total_pendapatan_bioskop > bioskop_kedua->total_pendapatan_bioskop) return 1;
    return 0;     
}

int compare_value_bioskop(Bioskop* bioskop_pertama, Bioskop* bioskop_kedua)
{
    if (!bioskop_pertama || !bioskop_kedua) { return (bioskop_pertama == bioskop_kedua); }
    if (bioskop_pertama->total_pendapatan_bioskop != bioskop_kedua->total_pendapatan_bioskop) { return 0; } 
    if (strcmp(bioskop_pertama->nama_bioskop, bioskop_kedua->nama_bioskop) != 0) { return 0; }
    if (strcmp(bioskop_pertama->alamat_bioskop, bioskop_kedua->alamat_bioskop) != 0) { return 0; }
    return 1; 
}
