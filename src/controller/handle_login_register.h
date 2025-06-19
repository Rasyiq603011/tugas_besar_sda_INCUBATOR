#ifndef HANDLE_LOGIN_REGISTER_H
#define HANDLE_LOGIN_REGISTER_H

#include "handle_login_register.h"
#include "../view/tampilan_login_signup.h"
#include "../model/tree_data.h"
#include "../model/file_manipulation/write_json.h"
#include "../model/file_manipulation/read_json.h"

void handle_signup_user(Tree* T);
void handle_login_user(Tree* T);
void handle_login_admin(Tree* T);

#endif