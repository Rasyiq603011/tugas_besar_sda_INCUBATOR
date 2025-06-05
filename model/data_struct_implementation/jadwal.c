#include "../data_struct.h"
#include "../date.h"
#define BARIS
#define KOLOM 

struct Jadwal{
    time waktu;
    date tanggal;
    Kursi* kursi[BARIS][KOLOM];
};




