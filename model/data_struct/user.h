#ifndef USER_H
#define USER_H

#include <stdlib.h>
#include "riwayat.h"

typedef char* String;

// ===============================================
// ============= ENUM DEFINITIONS ==============
// ===============================================

// Jenis prioritas pengguna
typedef enum
{
    REGULER,
    VIP_1,
    VIP_2,
} Prioritas;

// Deklarasi tipe User
typedef struct DataUser User;

// ===============================================
// ============== ACESSOR SECTION ================
// ===============================================

String get_username_user(User* user);
String get_password_user(User* user);
int get_saldo_user(User* user);
Prioritas get_prioritas_user(User* user);

// ===============================================
// ============== MUTATOR SECTION ================
// ===============================================

void set_username_user(User* user, String username);
void set_password_user(User* user, String password);
void set_saldo_user(User* user, int saldo);
void set_prioritas_user(User* user, Prioritas prioritas);
void kurangi_saldo_user(User* user, int harga_tiket);

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

User* create_user(String username, String password, Prioritas prioritas);

// ===============================================
// ============= DESTRUCTOR SECTION ==============
// ===============================================

void destroy_user(User* user);

#endif /* USER_H */
