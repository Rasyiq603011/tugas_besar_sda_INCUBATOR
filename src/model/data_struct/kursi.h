#ifndef KURSI_H
#define KURSI_H
#include "../boolean.h"
#include <stdlib.h>
#include <assert.h>

typedef char* String;

typedef enum{
    TYPE_BRONZE = 0,
    TYPE_SILVER = 1,
    TYPE_GOLD = 2
}KursiType;
// ================================================
// ==================== Kursi =====================
// ================================================

typedef struct DataKursi Kursi;

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Kursi* constructor_kursi(int id, boolean status, KursiType tipe);

void create_new_kursi(Kursi** new_kursi, int id, boolean status, KursiType tipe);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

int get_id_kursi(Kursi* current_kursi);

boolean get_status_kursi(Kursi* current_kursi);

KursiType get_tipe_kursi(Kursi* current_kursi);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_id_kursi(Kursi* current_kursi, int new_id);

void set_status_kursi(Kursi* current_kursi, boolean new_status);

void set_tipe_kursi(Kursi* current_kursi, KursiType new_tipe);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_kursi(Kursi* current_kursi);

int compare_kursi_value(const Kursi* kursi_pertama, const Kursi* kursi_kedua);

#endif /*KURSI_H*/