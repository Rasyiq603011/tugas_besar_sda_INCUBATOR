#include "handle_tampilan_riwayat.h"

void handle_tampilan_riwayat(User* user)
{
    void** array;
    int jumlah = convert_riwayat_to_array(get_pointer_to_riwayat(user), &array);
    int pilihan = scrollable_menu(array, jumlah, tampilan_riwayat, "Riwayat", 8, 4);
    free(array);
    return;
}
