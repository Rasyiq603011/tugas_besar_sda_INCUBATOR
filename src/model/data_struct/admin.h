#ifndef ADMIN_H
#define ADMIN_H

#include "../tree_data.h"

typedef char* String;

typedef struct DataAdmin Admin;

// ================================
// ===== ACCESSOR SECTION =========
// ================================
String get_username_admin(const Admin* admin);
String get_password_admin(const Admin* admin);

// ================================
// ====== MUTATOR SECTION =========
// ================================
void set_username_admin(Admin* admin, const String username);
void set_password_admin(Admin* admin, const String password);

// ================================
// ==== CONSTRUCTOR SECTION =======
// ================================
Admin* create_admin(const String username, const String password);

// ================================
// ==== DESTRUCTOR SECTION ========
// ================================
void destroy_admin(Admin* admin);

#endif /* ADMIN_H */
