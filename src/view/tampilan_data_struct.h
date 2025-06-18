#ifndef TAMPILAN_DATA_STRUCT_H
#define TAMPILAN_DATA_STRUCT_H
#include "../model/tree_data.h"
#include "view.h"

// I.S : 
// F.S : 
// Fungsi :
void tampilan_negara(int idx, int y, int selected, void* selected_node);

// I.S : 
// F.S : 
// Fungsi :
void tampilan_provinsi(int idx, int y, int selected, void* selected_node);

// I.S : 
// F.S : 
// Fungsi :
void tampilan_kota(int idx, int y, int selected, void* selected_node);

// I.S : 
// F.S : 
// Fungsi :
void tampilan_bioskop(int idx, int y, int selected, void* selected_node);

// I.S : 
// F.S : 
// Fungsi :
void tampilan_studio(int idx, int y, int selected, void* pointer_head);

// I.S : 
// F.S : 
// Fungsi :
void tampilan_jadwal(int idx, int y, int selected, void* selected_node);

#endif /*TAMPILAN_DATA_STRUCT_H*/