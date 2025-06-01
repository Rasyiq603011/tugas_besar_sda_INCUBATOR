#include "../data_struct.h"

struct Riwayat{
    String judul_film;
    char tanggal[11];
    char jam[6];
    int harga_tiket;
    String kursi;
    struct Riwayat* next;
} ;