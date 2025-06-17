#ifndef VIEW_H
#define VIEW_H
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "../model/tree_data.h"

void gotoxy(int x, int y);

void display_menu(int opsi_terpilih, int jumlah_opsi, const char *options[jumlah_opsi], const char* header);

void display_scorallable_menu(int opsi_terpilih, int jumlah_pilihan, char *options[jumlah_pilihan], int jumlah_maksimum);

void clear_line(int y);

int scrollable_menu(void** data_array, int jumlah_item, void (*render)(int idx, int y_pos, int selected, void* data), const char* header, int tinggi_blok, int max_tampil);

#endif /*VIEW_H*/
