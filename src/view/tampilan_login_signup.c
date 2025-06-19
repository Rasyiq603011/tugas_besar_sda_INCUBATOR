#include "tampilan_login_signup.h"

void tampilan_login_signup(const char* header)
{
    int kolom = 30;
    int panjang = 60;

    gotoxy(kolom, 11); printf("============================================================");
    
    // Hitung posisi tengah agar teks header bisa di-center-kan
    int header_len = strlen(header);
    int space = (58 - header_len) / 2; // 58 karena lebar dalam frame '|<...>|'
    gotoxy(kolom, 12);
    printf("|%*s%s%*s|", space, "", header, 58 - header_len - space, "");
    
    gotoxy(kolom, 13); printf("============================================================");
    gotoxy(kolom, 14); printf("| Username :                                               |");
    gotoxy(kolom, 15); printf("============================================================");
    gotoxy(kolom, 16); printf("| Password :                                               |");
    gotoxy(kolom, 17); printf("============================================================");
    gotoxy(kolom, 25); printf("Tekan 'esc' untuk kembali");
}