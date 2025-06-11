#include "kursi_view.h"
#include "windows.h"

CHAR_INFO visual_kursi[21];

SMALL_RECT** posisi_kursi;

void set_char_visual_kursi(int nomor_kursi, int tipe) // tipe 1 untuk reguler, tipe 2 untuk vip 1, tipe 3 untuk vip 2
{
    int i;
    for(i=0; i<21; i++)
    {
        visual_kursi[i].Char.AsciiChar = 219;
        visual_kursi[i].Attributes = 7;
    }

    char kode = 64 + tipe;
    visual_kursi[8].Char.AsciiChar = kode;
    visual_kursi[9].Char.AsciiChar = '-';
    visual_kursi[10].Char.AsciiChar = (nomor_kursi - (nomor_kursi % 100)) / 100;
    visual_kursi[11].Char.AsciiChar = ((nomor_kursi % 100) - (nomor_kursi % 10)) / 10;
    visual_kursi[12].Char.AsciiChar = (nomor_kursi % 10);
}

void inisialisasi_small_rect(int row, int col)
{
    posisi_kursi = malloc(row * sizeof(SMALL_RECT *));
    for (int i = 0; i < row; i++) 
    {
        posisi_kursi[i] = malloc(col * sizeof(SMALL_RECT));
    }
}

void make_kursi_card()
{
    
}