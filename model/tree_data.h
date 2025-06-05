#ifndef TREE_DATA_H
#define TREE_DATA_H
#include "data_struct.h"

typedef union
{
    /* data */
}infotype;

typedef enum{
    TYPE_PROVINSI,
    TYPE_KOTA,
    TYPE_BIOSKOP,
    TYPE_FILM,
    TYPE_JADWAL,
    TYPE_KURSI,
    TYPE_USER
}DataType;

typedef struct treeElmmt* Addrees;
typedef struct treeElmmt
{
    infotype info;
    DataType tipe;
    Addrees first_child;
    Addrees next_brother;
}Tree;

typedef struct tree_data
{
    Addrees first;
    int pendapatan;
}Negara;





#endif