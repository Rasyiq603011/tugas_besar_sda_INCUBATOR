#ifndef HANDLE_CRUD_TREE_H
#define HANDLE_CRUD_TREE_H
#include "../model/file_manipulation/read_json.h"

void tambah_jadwal_ke_studio(Studio* studio);

void input_judul_film(char* buffer, int size);
int input_harga_tiket();
int input_jumlah_kursi();
void input_tanggal(date* tanggal);
void input_waktu(Time* waktu, const char* label);



#endif