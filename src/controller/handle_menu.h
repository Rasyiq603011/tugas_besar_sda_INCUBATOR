#ifndef HANDLE_MENU_H
#define HANDLE_MENU_H
#include "../view/view.h"
#include "handle_menu_admin.h"
#include "handle_menu_pemilihan.h"
#include "handle_tampilan_riwayat.h"
#include "../view/tampilan_login_signup.h"
#include "../model/file_manipulation/write_json.h"
#include "../model/file_manipulation/read_json.h"

void handle_option_menu(int key, int* opsi_terpilih, int jumlah_opsi);

// ===============================================
// ============= DISPLAY SECTION =================
// ===============================================

int handle_display_menu(int jumlah_opsi, const char* options[], const char* header);

// ===============================================
// ============= MENU ADMIN SECTION ==============
// ===============================================

void handle_menu_admin();

// ===============================================
// ============== MENU USER SECTION ==============
// ===============================================

void handle_menu_user(User* user, Tree T);

void handle_menu_masuk_user();

// ===============================================
// =============== SIGN UP/LOG IN ================
// ===============================================

void handle_signup_user();

void handle_login_user();

void handle_login_admin();

#endif /*HANDLE_MENU_UTAMA_ADMIN_H*/