#include "tampilan_riwayat.h"
#define WIDTH 40

void tampilan_riwayat(int idx, int y, int selected, void* selected_node) 
{
    
    Riwayat* r = (Riwayat*) selected_node;
    if (r == NULL) return;

    const char *highlight_start = selected ? "\033[1;37;44m" : "";
    const char *highlight_end = selected ? "\033[0m" : "";
	
	char buffer[WIDTH + 1];
	
	gotoxy((140-40)/2, y ); 
	snprintf(buffer, WIDTH + 1, "Riwayat #%d", idx + 1);
    printf("%s%-*s%s", highlight_start, WIDTH, buffer, highlight_end);
    
	gotoxy((140-40)/2, y + 1);
	snprintf(buffer, WIDTH + 1, "Judul Film   : %s", get_judul_film_riwayat(r));
    printf("%s%-*s%s", highlight_start, WIDTH, buffer, highlight_end);
    
	gotoxy((140-40)/2, y + 2); 
	snprintf(buffer, WIDTH + 1, "Tanggal      : %s", get_tanggal_riwayat(r));
    printf("%s%-*s%s", highlight_start, WIDTH, buffer, highlight_end);
    
	gotoxy((140-40)/2, y + 3);
	snprintf(buffer, WIDTH + 1, "Jam          : %s", get_jam_riwayat(r));
    printf("%s%-*s%s", highlight_start, WIDTH, buffer, highlight_end);
    
	gotoxy((140-40)/2, y + 4); 
	snprintf(buffer, WIDTH + 1, "Harga Tiket  : Rp %d", get_harga_tiket_riwayat(r));
    printf("%s%-*s%s", highlight_start, WIDTH, buffer, highlight_end);
    
	gotoxy((140-40)/2, y + 5); 
	snprintf(buffer, WIDTH + 1, "Nomor Kursi  : %s", get_kursi_riwayat(r));
    printf("%s%-*s%s", highlight_start, WIDTH, buffer, highlight_end);
    
	gotoxy((140-40)/2, y + 6); 
	snprintf(buffer, WIDTH + 1, "----------------------------------------");
	printf("%s%-*s%s", highlight_start, WIDTH, buffer, highlight_end);
}