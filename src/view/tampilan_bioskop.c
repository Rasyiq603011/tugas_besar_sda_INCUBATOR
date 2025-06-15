#include "tampilan_bioskop.h"


void tampilan_bioskop(int idx, int y, int selected, void* pointer_head)
{
    gotoxy(10, y);
    if (selected) printf("\033[1;37;44mBioskop #%d\033[0m", idx + 1);
    else printf("Bioskop #%d", idx + 1);

    gotoxy(10, y + 1); printf("Nama Bioskop  : %s");
    gotoxy(10, y + 2); printf("Alamat        : %s");
}
