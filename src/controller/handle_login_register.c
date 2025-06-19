#include "handle_login_register.h"

void handle_signup_user(Tree* T)
{   
    char username[46], password[46];
    int pos, ch;
    
start_input:
    tampilanLogin();

    // === Input Username ===
    pos = 0;
    gotoxy(43, 14);
    while (1) 
    {
        ch = getch();

        if (ch == 27) 
        { // ESC
            return;
        } 
        else if (ch == 13) 
        { 
            username[pos] = '\0';
            if (strcmp(username, "Ivan") == 0) {
            	system("cls");
                gotoxy(30, 20);
                printf("Username sudah tersedia. Masukkan username lain!");
                Sleep(1000); // windows: Sleep(ms)
                system("cls");
				tampilanLogin();
				gotoxy(43, 14);
				pos = 0;
            } else {
                break; // lanjut ke input password
            }
        } 
        else if (ch == 8) 
        { // BACKSPACE
            if (pos > 0) {
                pos--;
                gotoxy(43 + pos, 14);
                printf(" ");
                gotoxy(43 + pos, 14);
            }
        } 
        else if (ch >= 32 && ch <= 126 && pos < 45) 
        {
            username[pos++] = ch;
            printf("%c", ch);
        }
    }

    // === Input Password ===
    pos = 0;
    gotoxy(43, 16);
    while (1) 
    {
        ch = getch();

        if (ch == 27) 
        { // ESC saat input password
            // Bersihkan password dari layar
            int i;
            for (i = 0; i < pos; i++) 
            {
                gotoxy(43 + i, 16);
                printf(" ");
            }
            gotoxy(43, 16); // reset kursor ke awal password
            // Kembali ke input username
            goto start_input;
        } 
        else if (ch == 13) 
        { // ENTER selesai
            password[pos] = '\0';
            break;
        } 
        else if (ch == 8) 
        { // BACKSPACE
            if (pos > 0) 
            {
                pos--;
                gotoxy(43 + pos, 16);
                printf(" ");
                gotoxy(43 + pos, 16);
            }
        } 
        else if (ch >= 32 && ch <= 126 && pos < 45) 
        {
            password[pos++] = ch;
            printf("*");
        }
    }

    system("cls");
    gotoxy(30, 20); printf("Pendaftaran berhasil!");
    return;
}

void handle_login_user(Tree* T)
{
    char username[46], password[46];
    int pos, ch;
    
start_input:
    tampilanLogin();

    // === Input Username ===
    pos = 0;
    gotoxy(43, 14);
    while (1) 
    {
        ch = getch();

        if (ch == 27) 
        { // ESC
            return;
        } 
        else if (ch == 13) 
        { 
            username[pos] = '\0';
            if (strcmp(username, "Ivan") == 0) {
            	system("cls");
                gotoxy(30, 20);
                printf("Username sudah tersedia. Masukkan username lain!");
                Sleep(1000); // windows: Sleep(ms)
                system("cls");
				tampilanLogin();
				gotoxy(43, 14);
				pos = 0;
            } else {
                break; // lanjut ke input password
            }
        } 
        else if (ch == 8) 
        { // BACKSPACE
            if (pos > 0) {
                pos--;
                gotoxy(43 + pos, 14);
                printf(" ");
                gotoxy(43 + pos, 14);
            }
        } 
        else if (ch >= 32 && ch <= 126 && pos < 45) 
        {
            username[pos++] = ch;
            printf("%c", ch);
        }
    }

    // === Input Password ===
    pos = 0;
    gotoxy(43, 16);
    while (1) 
    {
        ch = getch();

        if (ch == 27) 
        { // ESC saat input password
            // Bersihkan password dari layar
            int i;
            for (i = 0; i < pos; i++) 
            {
                gotoxy(43 + i, 16);
                printf(" ");
            }
            gotoxy(43, 16); // reset kursor ke awal password
            // Kembali ke input username
            goto start_input;
        } 
        else if (ch == 13) 
        { // ENTER selesai
            password[pos] = '\0';
            break;
        } 
        else if (ch == 8) 
        { // BACKSPACE
            if (pos > 0) 
            {
                pos--;
                gotoxy(43 + pos, 16);
                printf(" ");
                gotoxy(43 + pos, 16);
            }
        } 
        else if (ch >= 32 && ch <= 126 && pos < 45) 
        {
            password[pos++] = ch;
            printf("*");
        }
    }

    system("cls");
    gotoxy(30, 20); printf("Pendaftaran berhasil!");
    return;   
}