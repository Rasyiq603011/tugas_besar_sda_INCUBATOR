#ifndef CRUD_FILM_H
#define CRUD_FILM_H
#include "../linked.h"
#define DATABASE_FILM "../../assets/films.dat"
#define MAKS_JUDUL 50

void create_list_film(List *L);

void update_film(List *L);

void deleteFilm(List *L);

void save_to_file(List L);

void load_from_binary(List *L);

void clear_screen();

#endif