#ifndef USER_H
#define USER_H

typedef char* String;

typedef struct DataUser User;

String get_username_user(User* user);

String get_password_user(User* user);

int get_saldo_user(User* user);

void set_username_user(User* user, String username);

void set_password_user(User* user, String password);

void set_saldo_user(User* user, int saldo);

#endif /*USER_H*/