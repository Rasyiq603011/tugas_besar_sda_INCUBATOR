#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#define MAX_CHAR
#include <stdbool.h>

// typedef char String[MAX_CHAR];
typedef char* String;

// ================================================
// ==================== NEGARA ====================
// ================================================

typedef struct data_negara Negara;

Negara *get_negara();

void set_negara(Negara N);




// ================================================
// =================== PROVINSI ===================
// ================================================

typedef struct Provinsi Provinsi;






// ================================================
// ===================== KOTA =====================
// ================================================

typedef struct Kota Kota;





// ===============================================
// =================== BIOSKOP ===================
// ===============================================

typedef struct Bioskop Bioskop;




// ================================================
// ===================== FILM =====================
// ================================================

typedef struct Film Film;




// ================================================
// ==================== Jadwal ====================
// ================================================

typedef struct Jadwal Jadwal;



// ================================================
// ==================== Kursi =====================
// ================================================

typedef struct Kursi Kursi;


// ================================================
// ==================== User ======================
// ================================================

typedef struct User User;

String get_username_user(User* user);
String get_password_user(User* user);
int get_saldo_user(User* user);
void set_username_user(User* user, String username);
void set_password_user(User* user, String password);
void set_saldo_user(User* user, int saldo);

// ================================================
// =================== Riwayat ====================
// ================================================

typedef struct Riwayat Riwayat;

#endif