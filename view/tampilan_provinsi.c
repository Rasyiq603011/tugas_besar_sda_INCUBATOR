#include "tampilan_provinsi.h"

void tampilan_provinsi(int idx, int y, int selected, void* pointer_head)
{




    gotoxy(10, y);
    if (selected) printf("\033[1;37;44mProvinsi #%d\033[0m", idx + 1);
    else printf("Provinsi #%d", idx + 1);
    gotoxy(10, y + 1); printf("Nama Provinsi %s  Total Bioskop : %d");
}