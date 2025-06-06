#ifndef KURSI_H
#define KURSI_H
#include "../boolean.h"
#define MAX_ROW 10
#define MAX_COL 30

typedef char* String;

typedef enum{
    TYPE_BRONZE,
    TYPE_SILVER,
    TYPE_GOLD
}KursiType;
// ================================================
// ==================== Kursi =====================
// ================================================

typedef struct DataKursi Kursi;

Kursi* constructor_kursi();

void create_new_kursi(Kursi* new_kursi);

String get_id_kursi(Kursi current_kursi);

boolean get_status_kursi(Kursi current_kursi);

KursiType get_tipe_kursi(Kursi current_kursi);

void set_id_kursi(Kursi* current_kursi, String new_id);

void set_status_kursi(Kursi* current_kursi, boolean new_status);

void set_tipe_kursi(Kursi* current_kursi, KursiType new_tipe);

#endif /*KURSI_H*/