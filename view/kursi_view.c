#include "kursi_view.h"
#include "windows.h"
#define HEGIHT_KURSI 3
#define WIDTH_KURSI 7
#define POSISI_AWAL_KURSI_TOP 10
#define POSISI_AWAL_KURSI_LEFT 20
#define POSISI_AWAL_KURSI_RIGHT (POSISI_AWAL_KURSI_LEFT + WIDTH_KURSI)
#define POSISI_AWAL_KURSI_BOTTOM (POSISI_AWAL_KURSI_TOP + HEGIHT_KURSI)

CHAR_INFO visual_kursi[21];

SMALL_RECT* posisi_kursi;

COORD size_kursi = (COORD){WIDTH_KURSI, HEGIHT_KURSI};

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

void inisialisasi_small_rect(int jumlah_kursi, int jumlah_baris)
{
    int row, col, current_kursi=0;
    posisi_kursi = malloc(jumlah_kursi* sizeof(SMALL_RECT));
    for (current_kursi = 0; current_kursi < jumlah_kursi; current_kursi++) 
    {
        for (row = 0; row < jumlah_baris; row++)
        {
            posisi_kursi[current_kursi].Top = POSISI_AWAL_KURSI_TOP + ( (HEGIHT_KURSI + 1) * (current_kursi % jumlah_baris)); 
            posisi_kursi[current_kursi].Right = POSISI_AWAL_KURSI_RIGHT + ( (WIDTH_KURSI + 1) * (current_kursi )) ;
            posisi_kursi[current_kursi].Bottom = POSISI_AWAL_KURSI_BOTTOM + ((HEGIHT_KURSI + 1) * (current_kursi % jumlah_baris));
            posisi_kursi[current_kursi].Left = POSISI_AWAL_KURSI_BOTTOM;
            
        }
    }
}

void make_kursi_card()
{
    
}