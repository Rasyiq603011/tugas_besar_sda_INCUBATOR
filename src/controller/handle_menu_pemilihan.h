#ifndef HANDLE_MENU_PEMILIHAN_H
#define HANDLE_MENU_PEMILIHAN_H

#include "../model/stack_tree.h"
#include "../view/view.h"
#include "../view/tampilan_data_struct.h"


void handle_pemilihan_negara(address root);

void handle_pemilihan_provinsi(address root);

void handle_pemilihan_kota(address root);

void handle_pemilihan_bioskop(address root);

void handle_pemilihan_studio(address root);

void handle_pemilihan_jadwal(address root);

void navigasi_tree_for_admin(Tree bioskop);

void (*get_renderer_for_type(DataType type))(int, int, int, void*);

const char* get_title_for_type(DataType type);


#endif /* HANDLE_MENU_PEMILIHAN_H*/

