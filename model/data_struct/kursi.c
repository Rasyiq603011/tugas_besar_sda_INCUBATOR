#include "kursi.h"

struct DataKursi{
    int id;
    boolean status;
    KursiType tipe;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Kursi* constructor_kursi(int id, boolean status, KursiType tipe)
{
if (id < 0) return NULL;
    if (tipe != TYPE_BRONZE && tipe != TYPE_SILVER && tipe != TYPE_GOLD) return NULL;

    Kursi* new_kursi = (Kursi*)malloc(sizeof(Kursi));
    if (new_kursi == NULL) return NULL;

    new_kursi->id = id;
    new_kursi->status = status;
    new_kursi->tipe = tipe;
    return new_kursi;
}

void create_new_kursi(Kursi** new_kursi, int id, boolean status, KursiType tipe)
{
    *new_kursi = constructor_kursi(id, status, tipe);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

int get_id_kursi(Kursi* current_kursi)
{
    assert(current_kursi != NULL);
    return current_kursi->id;
}

boolean get_status_kursi(Kursi* current_kursi)
{
    assert(current_kursi != NULL);
    return current_kursi->status;
}

KursiType get_tipe_kursi(Kursi* current_kursi)
{
    assert(current_kursi != NULL);
    return current_kursi->tipe;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_id_kursi(Kursi* current_kursi, int new_id)
{
    assert(current_kursi != NULL);
    if (new_id >= 0)
    {
        current_kursi->id = new_id;
    }
}

void set_status_kursi(Kursi* current_kursi, boolean new_status)
{
    assert(current_kursi != NULL);
    current_kursi->status = new_status;
}
void set_tipe_kursi(Kursi* current_kursi, KursiType new_tipe)
{
    assert(current_kursi != NULL);
    if (new_tipe == TYPE_BRONZE || new_tipe == TYPE_SILVER || new_tipe == TYPE_GOLD)
    {
        current_kursi->tipe = new_tipe;
    }
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_kursi(Kursi* current_kursi)
{
    if (current_kursi != NULL) 
    {
        free(current_kursi);
    }
}

int compare_kursi_value(const Kursi* kursi_pertama, const Kursi* kursi_kedua)
{
    assert(kursi_pertama != NULL && kursi_kedua != NULL);
    return 
    (
        kursi_pertama->id == kursi_kedua->id &&
        kursi_pertama->status == kursi_kedua->status &&
        kursi_pertama->tipe == kursi_kedua->status
    );
}
