#ifndef KOTA_H
#define KOTA_H

typedef char* String;

// ================================================
// ===================== KOTA =====================
// ================================================

typedef struct DataKota Kota;

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Kota* constructor(String nama, int total_pendapatan, int jumlah_bioskop);
void create_kota(Kota* new_kota, String nama, int total_pendapatan, int jumlah_bioskop);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================
String get_name(Kota* current_kota);
int get_pendapatan_kota(Kota* current_kota);
int get_jumlah_bioskop(Kota* current_kota);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name(Kota* current_kota, String name);
void set_pendapatan(Kota* current_kota, int pendapatan);
void set_jumlah_bioskop(Kota* current_kota, int jumlah_bioskop);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================
void destructor(Kota* current_kota);

#endif /*KOTA_H*/