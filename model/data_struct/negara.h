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

Negara* constructor(String nama, int total_pendapatan, String film_terlaris[3], int jumlah_bioskop);

void create_negara(Negara* new_negara, String nama, int total_pendapatan, String film_terlaris[3], int jumlah_bioskop);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name(Negara current_negara);

int get_pendapatan_negara(Negara current_negara);

String* get_film_terlaris(Negara current_negara);

int get_jumlah_bioskop(Negara current_negara);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name(Negara* current_negara, String name);

void set_pendapatan(Negara* current_negara, int pendapatan);

void set_film_terlaris(Negara* current_negara, String film_terlaris[3]);

void set_jumlah_bioskop(Negara* current_negara, int jumlah_bioskop);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Negara* current_negara);

#endif /*NEGARA_H*/
