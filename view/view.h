#ifndef VIEW_H
#define VIEW_H
#include "windows.h"


void scrollable_menu(int jumlah_item, void (*render)(int idx, int y_pos, int selected), int tinggi_blok, int max_tampil, void* pointer_head);

#endif /*VIEW_H*/