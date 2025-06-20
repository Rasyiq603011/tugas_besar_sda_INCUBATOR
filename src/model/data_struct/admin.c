#include "admin.h"
#include <stdlib.h>
#include <string.h>

// ===================================================
// ============== STRUCT DEFINITIONS =================
// ===================================================

struct DataAdmin {
    String username;
    String password;
};

// ===================================================
// ================ ACCESSOR SECTION =================
// ===================================================

String get_username_admin(const Admin* admin)
{
    return (admin && admin->username) ? admin->username : "";
}

String get_password_admin(const Admin* admin)
{
    return (admin && admin->password) ? admin->password : "";
}

// ===================================================
// ================= MUTATOR SECTION =================
// ===================================================

void set_username_admin(Admin* admin, const String username)
{
    if (!admin) return;
    if (admin->username) free(admin->username);
    admin->username = (username) ? strdup(username) : NULL;
}

void set_password_admin(Admin* admin, const String password)
{
    if (!admin) return;
    if (admin->password) free(admin->password);
    admin->password = (password) ? strdup(password) : NULL;
}

// ===================================================
// ================ CONSTRUCTOR SECTION ==============
// ===================================================

Admin* create_admin(const String username, const String password)
{
    Admin* new_admin = (Admin*) malloc(sizeof(Admin));
    if (!new_admin) return NULL;

    new_admin->username = (username) ? strdup(username) : NULL;
    new_admin->password = (password) ? strdup(password) : NULL;

    return new_admin;
}

// ===================================================
// ================ DESTRUCTOR SECTION ===============
// ===================================================

void destroy_admin(Admin* admin)
{
    if (!admin) return;

    if (admin->username) free(admin->username);
    if (admin->password) free(admin->password);
    free(admin);
}
