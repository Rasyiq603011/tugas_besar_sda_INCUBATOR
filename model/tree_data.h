#ifndef TREE_DATA_H
#define TREE_DATA_H
#include "data_struct.h"

typedef enum {
    PROVINSI,
    KOTA,
    BIOSKOP,
    FILM,
    TANGGAL,
    JADWAL
} Datatype;

typedef union {
    Provinsi* provinsi;
    Kota* kota;
    Bioskop* bioskop;
    Film* film;
    Tanggal* tanggal;
    Jadwal* jadwal;
} Infotype;

typedef struct tElmtList* address;
typedef struct tElmtList {
    Infotype info;
    Datatype tipe;
    address first_son;
    address next_brother;
} ElmtList;

#endif