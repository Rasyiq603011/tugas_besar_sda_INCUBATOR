#ifndef HANDLE_MENU_PEMILIHAN_H
#define HANDLE_MENU_PEMILIHAN_H

#include "../model/tree_data.h"
#include "../view/view.h"
#include "../view/tampilan_negara.h"
#include "../view/tampilan_provinsi.h"
#include "../view/tampilan_kota.h"
#include "../view/tampilan_bioskop.h"
#include "../view/tampilan_studio.h"
#include "../view/tampilan_jadwal.h"

void handle_pemilihan_negara(address root);

void handle_pemilihan_provinsi(address root);

void handle_pemilihan_kota(address root);

void handle_pemilihan_bioskop(address root);

void handle_pemilihan_studio(address root);

void handle_pemilihan_jadwal(address root);

#endif /* HANDLE_MENU_PEMILIHAN_H*/

