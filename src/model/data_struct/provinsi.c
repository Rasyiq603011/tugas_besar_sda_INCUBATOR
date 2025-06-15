#include "provinsi.h"


struct DataProvinsi {
    String nama_provinsi;
    int total_pendapatan_provinsi;
    int jumlah_bioskop_provinsi;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Provinsi* constructor(const String nama, int total_pendapatan, int jumlah_bioskop)
{
    if (nama == NULL || total_pendapatan < 0 || jumlah_bioskop < 0) { return NULL;}

    Provinsi* new_provinsi = (Provinsi*)malloc(sizeof(Provinsi));
    if (new_provinsi == NULL) { return NULL; }

    new_provinsi->nama_provinsi = (String)malloc(strlen(nama) + 1);
    if (new_provinsi->nama_provinsi == NULL) 
    {
        free(new_provinsi);
        return NULL; 
    }
    strcpy(new_provinsi->nama_provinsi, nama);
    new_provinsi->total_pendapatan_provinsi = total_pendapatan;
    new_provinsi->jumlah_bioskop_provinsi = jumlah_bioskop;

    return new_provinsi;
}

void create_provinsi(Provinsi** new_provinsi, const String nama, int total_pendapatan, int jumlah_bioskop)
{
    *new_provinsi = constructor(nama, total_pendapatan, jumlah_bioskop);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name_provinsi(Provinsi* current_provinsi)
{
    if (current_provinsi == NULL) { return NULL;}
    return current_provinsi->nama_provinsi;
}

int get_pendapatan_provinsi(Provinsi* current_provinsi)
{
    if (current_provinsi == NULL) { return -1;}
    return current_provinsi->total_pendapatan_provinsi;
}

int get_jumlah_bioskop_provinsi(Provinsi* current_provinsi)
{
    if (current_provinsi == NULL) { return -1;}
    return current_provinsi->jumlah_bioskop_provinsi;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_provinsi(Provinsi* current_provinsi, const String name)
{
    if (current_provinsi == NULL || name == NULL) {return;}
        free(current_provinsi->nama_provinsi);
        current_provinsi->nama_provinsi = (String)malloc(strlen(name) + 1);
        if (current_provinsi->nama_provinsi == NULL) {
            return; 
        }
        strcpy(current_provinsi->nama_provinsi, name);
}

void set_pendapatan_provinsi(Provinsi* current_provinsi, int pendapatan)
{
    if (current_provinsi == NULL || pendapatan < 0) { return; }
    current_provinsi->total_pendapatan_provinsi = pendapatan;
}

void set_jumlah_bioskop_provinsi(Provinsi* current_provinsi, int jumlah_bioskop)
{
    if (current_provinsi == NULL || jumlah_bioskop < 0) { return; }
    current_provinsi->jumlah_bioskop_provinsi = jumlah_bioskop;
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_provinsi(Provinsi* current_provinsi)
{
    if (current_provinsi == NULL) {return;}
    free(current_provinsi->nama_provinsi);
    free(current_provinsi);
}

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

int compare_provinsi_value(const Provinsi* provinsi_pertama, const Provinsi* provinsi_kedua) 
{
    if (provinsi_pertama == NULL || provinsi_kedua == NULL) { return 0;}
    return (strcmp(provinsi_pertama->nama_provinsi, provinsi_kedua->nama_provinsi) == 0 &&
            provinsi_pertama->total_pendapatan_provinsi == provinsi_kedua->total_pendapatan_provinsi &&
            provinsi_pertama->jumlah_bioskop_provinsi == provinsi_kedua->jumlah_bioskop_provinsi);
}