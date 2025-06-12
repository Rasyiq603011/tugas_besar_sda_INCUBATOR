#include "tampilan_kota.h"

void tampilan_kota(int idx, int y, int selected, void* pointer_head)
{
    Kota* head = (Kota*) pointer_head;
    Kota *k = get_kota_by_index(head, idx);
    if (k == NULL) return;

    gotoxy(10, y);
    if (selected) printf("\033[1;37;44mKota #%d\033[0m", idx + 1);
    else printf("Kota #%d", idx + 1);

    gotoxy(10, y + 1); printf("Nama Kota   : %s", get_nama_kota(k));
    gotoxy(10, y + 2); printf("Jumlah Bioskop: %d", get_jumlah_bioskop_kota(k));
    gotoxy(10, y + 3); printf("--------------------------------------------");
}