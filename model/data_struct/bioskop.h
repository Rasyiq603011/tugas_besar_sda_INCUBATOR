#ifndef BIOSKOP_H
#define BIOSKOP_H

typedef char* String;
// ===============================================
// =================== BIOSKOP ===================
// ===============================================

typedef struct DataBioskop Bioskop;

Bioskop* constructor_bioskop();

void create_bioskop(Bioskop* new_bioskop);

String get_name(Bioskop current_bioskop);

int get_pendapatan_bioskop(Bioskop current_bioskop);

String* get_film_terlaris(Bioskop current_bioskop);

void set_name(Bioskop* current_bioskop, String name);

void set_pendapatan(Bioskop* current_bioskop, int pendapatan);

void set_film_telaris(Bioskop* current_bioskop, String film_terlaris[3]);

#endif /*BIOSKOP_H*/