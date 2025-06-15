#include "tampilan_negara.h"

void tampilan_negara(int idx, int y, int selected, void* pointer_head)
{




    gotoxy(10, y);
    if (selected) printf("\033[1;37;44mNegara #%d\033[0m", idx + 1);
    else printf("Negara #%d", idx + 1);

    gotoxy(10, y + 1); printf("Nama Negara   %s  Total Bioskop : %d");
}