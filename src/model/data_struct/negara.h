#ifndef NEGARA_H
#define NEGARA_H
// ================================================
// ==================== NEGARA ====================
// ================================================

typedef char* String;

typedef struct DataNegara Negara;

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Negara* constructor_negara(const String nama, int total_pendapatan, int jumlah_bioskop);

void create_negara(Negara** new_negara, const String nama, int total_pendapatan, int jumlah_bioskop);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

const String get_name_negara(Negara* current_negara);

int get_pendapatan_negara(Negara* current_negara);

int get_jumlah_bioskop_negara(Negara* current_negara);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_negara(Negara* current_negara, const String nama);

void set_pendapatan_negara(Negara* current_negara, int pendapatan);

void set_jumlah_bioskop_negara(Negara* current_negara, int jumlah_bioskop);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Negara* current_negara);

int compare_value_negara(const Negara* negara_pertama, const Negara* negara_kedua);

#endif /*NEGARA_H*/
