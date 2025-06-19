#include "user.h"

// ===============================================
// ============= STRUCT DEFINITIONS ==============
// ===============================================

struct DataUser
{
    String username;
    String password;
    int saldo;
    Riwayat* riwayat;
    Prioritas prioritas;
};

// ===============================================
// ============== ACESSOR SECTION ================
// ===============================================

// Mengembalikan username user
String get_username_user(User* user)
{
    return user->username;
}

// Mengembalikan password user
String get_password_user(User* user)
{
    return user->password;
}

// Mengembalikan saldo user
int get_saldo_user(User* user)
{
    return user->saldo;
}

// Mengembalikan prioritas user (REGULER / VIP_1 / VIP_2)
Prioritas get_prioritas_user(User* user)
{
    return user->prioritas;
}

Riwayat* get_pointer_to_riwayat(User* user)
{
    return user->riwayat;
}

// ===============================================
// ============== MUTATOR SECTION ================
// ===============================================

// Mengatur username baru untuk user
void set_username_user(User* user, String username)
{
    user->username = strdup(username);
}

// Mengatur password baru untuk user
void set_password_user(User* user, String password)
{
    user->password = strdup(password);
}

// Mengatur saldo baru untuk user
void set_saldo_user(User* user, int saldo)
{
    user->saldo = saldo;
}

// Mengatur prioritas baru untuk user
void set_prioritas_user(User* user, Prioritas prioritas)
{
    user->prioritas = prioritas;
}

// Mengurangi saldo user sesuai harga tiket
void kurangi_saldo_user(User* user, int harga_tiket)
{
    user->saldo -= harga_tiket;
}

void add_riwayat_user(User* user, Riwayat* new_riwayat)
{
    if (user->riwayat == NULL)
    {
        user->riwayat = new_riwayat;
        return;
    }
    
    Riwayat* temp = user->riwayat;
    while (get_next_riwayat(temp) != NULL)
    {
        temp = get_next_riwayat(temp);
    }
    set_next_riwayat(temp, new_riwayat);
}

void hapus_riwayat(User** user)
{
    if ((*user)->riwayat != NULL)
    {   
        Riwayat* temp;
        while ((*user)->riwayat != NULL)
        {
            temp = ((*user)->riwayat);
            (*user)->riwayat = get_next_riwayat((*user)->riwayat);

            if (temp != NULL)
            {
                free(temp);
            }
        }
    }
}

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

// Membuat objek user baru dengan username, password, dan prioritas tertentu
User* create_user(String username, String password, Prioritas prioritas, int saldo)
{
    User* user = (User*) malloc(sizeof(User));
    user->username = strdup(username);
    user->password = strdup(password);
    user->prioritas = prioritas;
    user->saldo = saldo;
    user->riwayat = NULL;
    return user;
}

// ===============================================
// ============= DESTRUCTOR SECTION ==============
// ===============================================

// Menghapus objek user dan membebaskan memori yang digunakan
void destroy_user(User** user)
{
    if (*user != NULL)
    {
        free((*user)->username);  // membebaskan memori username
        free((*user)->password);  // membebaskan memori password (seharusnya ini, bukan username dua kali)
        hapus_riwayat(user);
        free(*user);            // membebaskan memori objek user
    }
}