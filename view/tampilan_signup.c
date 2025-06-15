#include "tampilan_signup.h"

void tampilan_sign_up(char username[46], char password[46])
{
    int pos = 0;
    char ch;

    gotoxy(30,11); printf("============================================================");
    gotoxy(30,12); printf("|                         SIGN UP                          |");
    gotoxy(30,13); printf("============================================================");
    gotoxy(30,14); printf("| Username :                                               |");
    gotoxy(30,15); printf("============================================================");
    gotoxy(30,16); printf("| Password :                                               |");
    gotoxy(30,17); printf("============================================================");

    // === Input Username ===
    pos = 0;
    gotoxy(43, 14);
    while (1) {
        ch = getch();

        if (ch == 13) { // ENTER pindah ke password
            username[pos] = '\0';
            break;
        } else if (ch == 8) { // BACKSPACE
            if (pos > 0) {
                pos--;
                gotoxy(43 + pos, 14);
                printf(" ");
                gotoxy(43 + pos, 14);
            }
        } else if (ch >= 32 && ch <= 126 && pos < 45) {
            username[pos++] = ch;
            printf("%c", ch);
        }
    }

    // === Input Password ===
    pos = 0;
    gotoxy(43, 16);
    while (1) {
        ch = getch();

        if (ch == 13) { // ENTER selesai
            password[pos] = '\0';
            break;
        } else if (ch == 8) { // BACKSPACE
            if (pos > 0) {
                pos--;
                gotoxy(43 + pos, 16);
                printf(" ");
                gotoxy(43 + pos, 16);
            }
        } else if (ch >= 32 && ch <= 126 && pos < 45) {
            password[pos++] = ch;
            printf("*"); // tampilkan * untuk password
        }
    }

    system("cls");
}