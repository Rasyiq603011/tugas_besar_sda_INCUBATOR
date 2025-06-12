#include "tampilan_studio.h"

void tampilan_studio(int idx, int y, int selected, void* pointer_head)
{
    Studio* head = (Studio*) pointer_head;
    Studio *s = get_studio_by_index(head, idx);
    if (s == NULL) return;

    gotoxy(10, y);
    if (selected) printf("\033[1;37;44mStudio #%d\033[0m", idx + 1);
    else printf("Studio #%d", idx + 1);

    gotoxy(10, y + 1); printf("Nama Studio  : %s", get_nama_studio(s));
    gotoxy(10, y + 2); printf("Kapasitas    : %d", get_kapasitas_studio(s));
    gotoxy(10, y + 3); printf("Tersedia     : %d", get_tersedia_studio(s));
    gotoxy(10, y + 4); printf("--------------------------------------------");
}