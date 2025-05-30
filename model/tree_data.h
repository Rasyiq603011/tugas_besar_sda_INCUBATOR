#ifndef TREE_DATA_H
#define TREE_DATA_H
#include "data_struct.h"

typedef union
{
    /* data */
}infotype;

typedef enum{

}DataType;


typedef struct treeElmmt* Addrees;
typedef struct treeElmmt
{
    infotype info;
    DataType tipe;
    Addrees first_child;
    Addrees next_brother;

    /* data */
}Tree;




#endif