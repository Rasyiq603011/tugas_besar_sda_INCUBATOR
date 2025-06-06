#ifndef TREE_DATA_H
#define TREE_DATA_H
#include "data_struct/negara.h"
#include "data_struct/provinsi.h"
#include "data_struct/kota.h"
#include "data_struct/bioskop.h"
#include "data_struct/studio.h"
#include "boolean.h"

// ==============================
// ==== TYPE DEFINITIONS ========
// ==============================

typedef enum
{
    TYPE_PROVINSI,
    TYPE_KOTA,
    TYPE_BIOSKOP,
    TYPE_FILM,
}DataType;

typedef struct tree_data
{
    address first;
    int pendapatan;
}Negara;

typedef union 
{
    Provinsi* provinsi;
    Kota* kota;
    Bioskop* bioskop;
    Studio* studio;
} InfoType;

typedef struct Tree
{
    address root;    
}Tree;

typedef struct tElmtList* address;
typedef struct tElmtList 
{
    InfoType info;
    DataType tipe;
    address first_son;
    address next_brother;
} ElmtList;

// ==============================
// ====== FUNCTION HEADERS =====
// ==============================

// Constructor & init
void init_tree(Tree* T);
address create_node(InfoType info, DataType tipe);

// Validator
boolean is_tree_empty(Tree T);
boolean is_tree_leaf(address P);
boolean has_sibling(address P);
boolean has_child(address P);

// Accessor
address get_first_son(address P);
address get_last_son(address P);
address get_next_brother(address P);
InfoType get_info_node(address P);
DataType get_tipe_node(address P);

// Mutator
void add_child(address parent, InfoType info, DataType tipe);

// Destructor (non-rekursif deklarasi)
void delete_tree(Tree* T);

#endif