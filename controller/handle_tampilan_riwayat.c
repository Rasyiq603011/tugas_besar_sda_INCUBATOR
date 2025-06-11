#include "handle_tampilan_riwayat.h"

void handle_tampilan_riwayat(Riwayat* head)
{
    scrollable_menu(get_jumlah_riwayat(head), tampilan_riwayat, 7, 4, head);
}