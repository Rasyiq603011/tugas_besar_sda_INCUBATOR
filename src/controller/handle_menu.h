#ifndef HANDLE_MENU_H
#define HANDLE_MENU_H
#include "../view/view.h"
#include "handle_menu_admin.h"

void handle_option_menu(int key, int* opsi_terpilih, int jumlah_opsi);

int handle_display_menu(int jumlah_opsi, const char* options[], const char* header);

// ===============================================
// ============= MENU ADMIN SECTION ==============
// ===============================================

void handle_menu_admin();

// ===============================================
// ============== MENU USER SECTION ==============
// ===============================================

void handle_menu_user();

// ===============================================
// ============== MENU AWAL SECTION ==============
// ===============================================

void handle_menu_user();

#endif /*HANDLE_MENU_UTAMA_ADMIN_H*/