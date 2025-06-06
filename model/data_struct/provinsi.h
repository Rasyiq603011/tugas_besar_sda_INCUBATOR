#ifndef PROVINSI_H
#define PROVINSI_H

typedef char* String;

typedef struct DataNegara Provinsi;

Provinsi* constructor_provinsi();

void create_provinsi(Provinsi* new_provinsi);

String get_name_provinsi(Provinsi provinsi);

int get_pendapatan_provinsi(Provinsi current_provinsi);

String* get_film_terlaris_provinsi(Provinsi current_provinsi);

void set_name_provinsi(Provinsi* current_provinsi, String name);

void set_pendapatan_provinsi(Provinsi* current_provinsi, int pendapatan);

void set_film_terlaris_provinsi(Provinsi* current_provinsi, String film_terlaris[3]);

#endif /*PROVINSI_H*/