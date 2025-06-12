#include "user.h"

// ===============================================
// ============= STRUCT DEFINITIONS ==============
// ===============================================

struct DataUser
{
    String username;
    String password;
    int saldo;
    List riwayat;
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

// ===============================================
// ============== MUTATOR SECTION ================
// ===============================================

// Mengatur username baru untuk user
void set_username_user(User* user, String username)
{
    user->username = username;
}

// Mengatur password baru untuk user
void set_password_user(User* user, String password)
{
    user->password = password;
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

void add_riwayat_user(User* user, pnode new_riwayat)
{
    if (user->riwayat.First == NULL)
    {
        user->riwayat.First = new_riwayat;
        return;
    }
    
    pnode temp = user->riwayat.First;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_riwayat;
}

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

// Membuat objek user baru dengan username, password, dan prioritas tertentu
User* create_user(String username, String password, Prioritas prioritas)
{
    User* user = (User*) malloc(sizeof(User));
    user->username = username;
    user->password = password;
    user->prioritas = prioritas;
    user->riwayat.First = NULL;
    return user;
}

// ===============================================
// ============= DESTRUCTOR SECTION ==============
// ===============================================

// Menghapus objek user dan membebaskan memori yang digunakan
void destroy_user(User* user)
{
    if (user != NULL)
    {
        free(user->username);  // membebaskan memori username
        free(user->password);  // membebaskan memori password (seharusnya ini, bukan username dua kali)
        clear_list(&(user->riwayat.First));
        free(user);            // membebaskan memori objek user
    }
}

