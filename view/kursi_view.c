#include "kursi_view.h"

int get_kode_warna(int tipe, boolean status, boolean is_selected) 
{
    if (is_selected) return 0x70; 
    if (!status) return 0x04; 
    switch (tipe) {
        case 0: return 0x06; 
        case 1: return 0x07; 
        case 2: return 0x0E; 
        default: return 0x07;
    }
}

void set_char_visual_kursi(int nomor_kursi, int tipe, boolean status, boolean is_selected, CHAR_INFO kursi[HEIGHT_KURSI * WIDTH_KURSI]) {
    int current_char;
    for (current_char = 0; current_char < (HEIGHT_KURSI * WIDTH_KURSI); current_char++) 
    {
        kursi[current_char].Char.AsciiChar = 219;
        kursi[current_char].Attributes = get_kode_warna(tipe, status, is_selected);
    }
    char kode = 'A' + tipe;
    kursi[8].Char.AsciiChar = kode;
    kursi[9].Char.AsciiChar = '-';
    kursi[10].Char.AsciiChar = '0' + (nomor_kursi / 100);
    kursi[11].Char.AsciiChar = '0' + ((nomor_kursi % 100) / 10);
    kursi[12].Char.AsciiChar = '0' + (nomor_kursi % 10);
}

void inisialisasi_small_rect() {
    int row, col, current_kursi = 0;
    for (row = 0; row < JUMLAH_TAMPILAN_BARIS_KURSI; row++) 
    {
        for (col = 0; col < JUMLAH_TAMPILAN_KOLOM_KURSI; col++) 
        {
            if (current_kursi >= JUMLAH_TAMPILAN_KURSI_MAKS) return;
            posisi_kursi[current_kursi].Top = POSISI_AWAL_KURSI_TOP + ((HEIGHT_KURSI + 1) * row);
            posisi_kursi[current_kursi].Left = POSISI_AWAL_KURSI_LEFT + ((WIDTH_KURSI + 1) * col);
            posisi_kursi[current_kursi].Bottom = posisi_kursi[current_kursi].Top + HEIGHT_KURSI - 1;
            posisi_kursi[current_kursi].Right = posisi_kursi[current_kursi].Left + WIDTH_KURSI - 1;
            current_kursi++;
        }
    }
}