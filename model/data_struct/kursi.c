#include "kursi.h"

struct DataKursi{
    String id;
    boolean status;
    KursiType tipe;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Kursi* constructor(String id, boolean status, KursiType tipe)
{
    Kursi* new_kursi = (Kursi*)malloc(sizeof(Kursi));
    new_kursi->id = strdup(id);
    new_kursi->status = status;
    new_kursi->tipe = tipe;
    return new_kursi;
}

void create_new_kursi(Kursi* new_kursi, String id, boolean status, KursiType tipe)
{
    new_kursi = constructor_kursi(id, status, tipe);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_id_kursi(Kursi current_kursi)
{
    return current_kursi.id;
}

boolean get_status_kursi(Kursi current_kursi)
{
    return current_kursi.status;
}

KursiType get_tipe_kursi(Kursi current_kursi)
{
    return current_kursi.tipe;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_id_kursi(Kursi* current_kursi, String new_id)
{
    current_kursi->id = new_id;
}

void set_status_kursi(Kursi* current_kursi, boolean new_status)
{
    current_kursi->status = new_status;
}
void set_tipe_kursi(Kursi* current_kursi, KursiType new_tipe)
{
    current_kursi->tipe = new_tipe;
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Kursi* current_kursi)
{
    free(current_kursi->id);
    free(current_kursi->tipe);
}
