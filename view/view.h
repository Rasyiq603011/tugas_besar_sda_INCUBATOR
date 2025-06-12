#ifndef VIEW_H
#define VIEW_H
#include "windows.h"

void gotoxy(int x, int y);


void display_menu(int opsi_terpilih, int jumlah_opsi, char *options[jumlah_opsi], char* header);

void display_scorallable_menu(int opsi_terpilih, int jumlah_pilihan, char *options[jumlah_pilihan], int jumlah_maksimum);

void clear_line(int y);


#endif /*VIEW_H*/