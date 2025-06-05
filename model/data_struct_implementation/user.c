#include "../data_struct.h"

struct DataUser
{
    String username;
    String password;
    int saldo;
    Riwayat* riwayat;
};

String get_username_user(User* user)
{

    return user->username;

}

String get_password_user(User* user)
{

    return user->password;

}

int get_saldo_user(User* user)
{

    return user->saldo;

}

void set_username_user(User* user, String username)
{

    user->username = username;

}

void set_password_user(User* user, String password)
{

    user->password = password;

}

void set_saldo_user(User* user, int saldo)
{

    user->saldo = saldo;

}

void kurangi_saldo_user(User* user, int harga_tiket)
{

    user->saldo -= harga_tiket;

}

User* create_user()
{

    User* user = (User*) malloc(sizeof(User));
    user->riwayat = NULL;
    return user;

}

void destroy_user(User* user)
{

    if (user != NULL)
    {
        free(user->username);
        free(user->username);
        free(user);
    }

}

