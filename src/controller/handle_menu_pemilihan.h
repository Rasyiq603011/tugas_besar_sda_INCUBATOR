#ifndef HANDLE_MENU_PEMILIHAN_H
#define HANDLE_MENU_PEMILIHAN_H

#include "../view/view.h"
#include "../view/tampilan_data_struct.h"


//void handle_pemilihan_negara(address root);

void handle_pemilihan_provinsi(address root, User* user);

int handle_pemilihan_kota(address parent, User* user);

int handle_pemilihan_bioskop(address parent, User* user);

int handle_pemilihan_studio(address parent, User* user);

int handle_pemilihan_jadwal(List current_jadwal, pnode* out_node);

int handle_pemilihan_kursi(address studio, User* user);

#endif /* HANDLE_MENU_PEMILIHAN_H*/

