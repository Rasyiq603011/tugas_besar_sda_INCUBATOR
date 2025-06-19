#ifndef HANDLE_MENU_PEMILIHAN_H
#define HANDLE_MENU_PEMILIHAN_H

#include "../view/view.h"
#include "../view/tampilan_data_struct.h"


//void handle_pemilihan_negara(address root);

void handle_pemilihan_provinsi(address root);

void handle_pemilihan_kota(address root);

void handle_pemilihan_bioskop(address root);

void handle_pemilihan_studio(address root);

pnode handle_pemilihan_jadwal(List current_jadwal);

pnode handle_pemilihan_event(List current_event);

#endif /* HANDLE_MENU_PEMILIHAN_H*/

