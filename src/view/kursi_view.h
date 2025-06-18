#ifndef KURSI_VIEW_H
#define KURSI_VIEW_H
#include <windows.h>
#include "message_view.h"
#define HEIGHT_KURSI 3
#define WIDTH_KURSI 7
#define POSISI_AWAL_KURSI_TOP 5
#define POSISI_AWAL_KURSI_LEFT 20
#define POSISI_AWAL_KURSI_RIGHT (POSISI_AWAL_KURSI_LEFT + WIDTH_KURSI)
#define POSISI_AWAL_KURSI_BOTTOM (POSISI_AWAL_KURSI_TOP + HEIGHT_KURSI)
#define JUMLAH_TAMPILAN_BARIS_KURSI 10
#define JUMLAH_TAMPILAN_KOLOM_KURSI 15
#define JUMLAH_TAMPILAN_KURSI_MAKS (JUMLAH_TAMPILAN_BARIS_KURSI * JUMLAH_TAMPILAN_KOLOM_KURSI)

extern SMALL_RECT posisi_kursi[JUMLAH_TAMPILAN_KURSI_MAKS];
extern HANDLE out;
extern COORD size_kursi;
extern COORD pusat;

void init_kursi_view();

int get_kode_warna(int tipe, boolean status, boolean is_selected);

void set_char_visual_kursi(int nomor_kursi, int tipe, boolean status, boolean is_selected, CHAR_INFO kursi[HEIGHT_KURSI * WIDTH_KURSI]);

void inisialisasi_small_rect();

#endif /* KURSI_VIEW_H */

