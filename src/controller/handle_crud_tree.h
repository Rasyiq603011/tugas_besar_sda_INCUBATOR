#ifndef HANDLE_CRUD_TREE_H
#define HANDLE_CRUD_TREE_H
#define DATABASE_BIOSKOP "../../assets/database_bioskop.json"
#include "../model/file_manipulation/read_json.h"
#include "../model/file_manipulation/write_json.h"
#include "../model/file_manipulation/crud_film.h"
#include "../view/tambah_jadwal_view.h"

void handle_inisialisasi_data(Tree* tree, List* list_film);

void linked_jadwal_to_film(address node, void* context);

boolean handle_input_data_jadwal(Time* time_start, Time* time_end, date* date_jadwal, String judul_film, int* harga_tiket);

boolean handle_input_data_event(Time* time_start, Time* time_end, date* date_jadwal, String judul_film, int* harga_tiket);

#endif
