#include "admin.h"

// ===================================================
// ============== STRUCT DEFINITIONS =================
// ===================================================

// Struktur data untuk menyimpan informasi admin
struct DataAdmin {
    String username;
    String password;
};

// ===================================================
// ================ ACCESSOR SECTION =================
// ===================================================

// Mengembalikan username admin
String get_username_admin(Admin* admin)
{
    return admin->username;
}

// Mengembalikan password admin
String get_password_admin(Admin* admin)
{
    return admin->password;
}

// ===================================================
// ================= MUTATOR SECTION =================
// ===================================================

// Mengatur username admin
void set_username_admin(Admin* admin, String username)
{
    admin->username = username;
}

// Mengatur password admin
void set_password_admin(Admin* admin, String password)
{
    admin->password = password;
}

// ===================================================
// ================ CONSTRUCTOR SECTION ==============
// ===================================================

// Membuat objek admin baru dengan username dan password
Admin* create_admin(String username, String password)
{
    Admin* new_admin = (Admin*) malloc(sizeof(Admin));
    new_admin->username = username;
    new_admin->password = password;
    return new_admin;
}

// ===================================================
// ================ DESTRUCTOR SECTION ===============
// ===================================================

// Menghapus objek admin dan membebaskan memori yang digunakan
void destroy_admin(Admin* admin)
{
    if (admin != NULL)
    {
        free(admin->username);  // membebaskan memori username
        free(admin->password);  // membebaskan memori password
        free(admin);            // membebaskan memori objek admin
    }
}
