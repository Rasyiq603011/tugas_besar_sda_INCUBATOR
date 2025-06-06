#ifndef KOTA_H
#define KOTA_H

typedef char* String;

// ================================================
// ===================== KOTA =====================
// ================================================

typedef struct DataKota Kota;

Kota* constructor_kota();

void create_kota(Kota* new_kota);

String get_name_kota(Kota current_kota);

int get_pendapatan_kota(Kota current_kota);

String* get_film_terlaris_kota(Kota current_kota);

void set_name_kota(Kota* current_kota, String name);

void set_pendapatan_kota(Kota* current_kota, int pendapatan);

void set_film_terlaris_kota(Kota* current_kota, String film_terlaris[3]);

#endif /*KOTA_H*/