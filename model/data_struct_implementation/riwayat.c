#include "../data_struct.h"

struct DataRiwayat{
    String judul_film;
    char tanggal[11];
    char jam[6];
    int harga_tiket;
    String kursi;
    Riwayat* next;
} ;


String get_judul_film_riwayat(Riwayat* riwayat)
{

    return riwayat->judul_film;

}

String get_tanggal_riwayat(Riwayat* riwayat)
{

    return riwayat->tanggal;

}

String get_jam_riwayat(Riwayat* riwayat)
{

    return riwayat->jam;

}

int get_harga_tiket_riwayat(Riwayat* riwayat)
{

    return riwayat->harga_tiket;

}

String get_kursi_riwayat(Riwayat* riwayat)
{

    return riwayat->kursi;

}

Riwayat* get_next_riwayat(Riwayat* riwayat)
{

    return riwayat->next;

}

void set_judul_film_riwayat(Riwayat* riwayat, String judul_film)
{

    riwayat->judul_film = judul_film;

}

void set_tanggal_riwayat(Riwayat* riwayat, char tanggal[10])
{

    strcpy(riwayat->tanggal, tanggal);

}

void set_jam_riwayat(Riwayat* riwayat, char jam[5])
{

    strcpy(riwayat->jam, jam);

}

void set_harga_tiket_riwayat(Riwayat* riwayat, int harga_tiket)
{

    riwayat->harga_tiket = harga_tiket;

}

void set_kursi_riwayat(Riwayat* riwayat, String kursi)
{

    riwayat->kursi = kursi;

}

void set_next_riwayat(Riwayat* riwayat)
{

    riwayat->next = riwayat;

}

Riwayat* create_riwayat()
{

    Riwayat* new_node = (Riwayat*) malloc(sizeof(Riwayat));
    new_node->next = NULL;
    return new_node; 

}

void* destroy_riwayat(Riwayat* riwayat)
{

    free(riwayat->judul_film);
    free(riwayat->kursi);
    free(riwayat);

}