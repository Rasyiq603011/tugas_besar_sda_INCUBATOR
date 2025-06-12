#include "kota.h"

struct DataKota {
    String nama_kota;
    int total_pendapatan_kota;
    int jumlah_bioskop_kota;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Kota* constructor_kota(const String nama, int total_pendapatan, int jumlah_bioskop)
{
    if (!nama || total_pendapatan < 0 || jumlah_bioskop < 0) {return NULL; }

    Kota* new_kota = (Kota*)malloc(sizeof(Kota));
    if (!new_kota) {return NULL;}

    new_kota->nama_kota = strdup(nama);
    if (!new_kota->nama_kota) 
    {
        free(new_kota);
        return NULL; 
    }

    new_kota->total_pendapatan_kota = total_pendapatan;
    new_kota->jumlah_bioskop_kota = jumlah_bioskop;
    return new_kota;
}

void create_kota(Kota** new_kota, const String nama, int total_pendapatan, int jumlah_bioskop)
{
    *new_kota = constructor(nama, total_pendapatan, jumlah_bioskop);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name_kota(Kota* current_kota)
{
    if (!current_kota) return NULL;
    return current_kota->nama_kota;
}

int get_pendapatan_kota(Kota* current_kota)
{
    if (!current_kota) return -1;
    return current_kota->total_pendapatan_kota;
}

int get_jumlah_bioskop_kota(Kota* current_kota)
{
    if (!current_kota) return -1;
    return current_kota->jumlah_bioskop_kota;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_kota(Kota* current_kota, const String nama)
{
    if (current_kota && nama) 
    {
        String new_nama = strdup(nama);
        if (new_nama) {
            free(current_kota->nama_kota);
            current_kota->nama_kota = new_nama;
        }
    }
}

void set_pendapatan_kota(Kota* current_kota, int pendapatan)
{
    if (current_kota && pendapatan >= 0) 
    {
        current_kota->total_pendapatan_kota = pendapatan;
    }
}

void set_jumlah_bioskop_kota(Kota* current_kota, int jumlah_bioskop)
{
    if (current_kota && jumlah_bioskop >= 0) 
    {
        current_kota->jumlah_bioskop_kota = jumlah_bioskop;
    }
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_kota(Kota* current_kota)
{
    if (current_kota) {
        free(current_kota->nama_kota);
        free(current_kota);
    }
}

int compare_kota_value(const Kota* kota_pertama, const Kota* kota_kedua) 
{
    if (kota_pertama == NULL || kota_kedua == NULL) { return 0;}
    return (strcmp(kota_pertama->nama_kota, kota_kedua->nama_kota) == 0 &&
            kota_pertama->total_pendapatan_kota == kota_kedua->total_pendapatan_kota &&
            kota_pertama->jumlah_bioskop_kota == kota_kedua->jumlah_bioskop_kota);
}
