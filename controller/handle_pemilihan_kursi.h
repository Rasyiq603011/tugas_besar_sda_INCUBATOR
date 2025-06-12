#ifndef HANDLE_PEMILIHAN_KURSI
#define HANDLE_PEMILIHAN_KURSI
#include "../view/kursi_view.h"
#include "../model/data_struct/kursi.h"

void set_attribut_kursi(int jumlah_kursi, CHAR_INFO* visual_kursi[], Kursi* daftar_kursi[], int terpilih, int offset);

void display_kursi(int jumlah_kursi, Kursi* daftar_kursi[], int terpilih, int page);

int kelola_operasi(int key, int current_option, int jumlah_kursi, int* page);

void pemilihan_kursi(int jumlah_kursi, Kursi* daftar_kursi[]);

#endif /*HANDLE_PEMILIHAN_KURSI*/