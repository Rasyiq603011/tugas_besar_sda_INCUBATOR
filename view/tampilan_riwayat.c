#include "tampilan_riwayat.h"

//void tampilan_riwayat(int idx, int y, int selected, void* pointer_head)
//{
//    Riwayat* head = (Riwayat*) pointer_head;
//    Riwayat *r = get_riwayat_by_index();
//    if (r == NULL) return;
//
//    gotoxy(10, y);
//    if (selected) printf("\033[1;37;44mRiwayat #%d\033[0m", idx + 1);
//    else printf("Riwayat #%d", idx + 1);
//
//    gotoxy(10, y + 1); printf("Judul Film   : %s", get_judul_film_riwayat(r));
//    gotoxy(10, y + 2); printf("Tanggal      : %s", get_tanggal_riwayat(r));
//    gotoxy(10, y + 3); printf("Jam          : %s", get_jam_riwayat(r));
//    gotoxy(10, y + 4); printf("Harga Tiket  : Rp%d", get_harga_tiket_riwayat(r));
//    gotoxy(10, y + 5); printf("Nomor Kursi  : %s", get_kursi_riwayat(r));
//    gotoxy(10, y + 6); printf("--------------------------------------------");
//}
