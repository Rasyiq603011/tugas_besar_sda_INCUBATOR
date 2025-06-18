#include "tampilan_jadwal.h"

#define WIDTH 60
#define X_POS (140 - WIDTH) / 2

void tampilan_jadwal(int idx, int y, int selected, void* selected_node)
{
    Jadwal* j = (Jadwal*) selected_node;
    if (j == NULL) return;

    const char *highlight_start = selected ? "\033[1;37;44m" : "";
    const char *highlight_end = selected ? "\033[0m" : "";

    char buffer[WIDTH + 1];
    char kiri[30], kanan[30];

    char*  waktu = time_to_string(get_waktu_start(j));
    char* tanggal = date_to_string(get_tanggal_tayang(j));

    if (waktu == NULL || tanggal == NULL)
    {
        if (waktu) free(waktu);
        if (tanggal) free(tanggal);
        return;
    }

    // Baris 1: Judul (kiri) & Waktu (kanan)
    gotoxy(X_POS, y);
    snprintf(kiri, sizeof(kiri), "Judul: %s", get_film_name(j));
    snprintf(kanan, sizeof(kanan), "Waktu: %s", waktu);
    snprintf(buffer, WIDTH + 1, "%-30s%-30s", kiri, kanan);
    printf("%s%-*s%s", highlight_start, WIDTH, buffer, highlight_end);

    // Baris 2: Harga Tiket (kiri) & Tanggal (kanan)
    gotoxy(X_POS, y + 1);
    snprintf(kiri, sizeof(kiri), "Harga Tiket: %d", get_harga_tiket(j));
    snprintf(kanan, sizeof(kanan), "Tanggal: %s", tanggal);
    snprintf(buffer, WIDTH + 1, "%-30s%-30s", kiri, kanan);
    printf("%s%-*s%s", highlight_start, WIDTH, buffer, highlight_end);

    free(waktu);
    free(tanggal);
}


