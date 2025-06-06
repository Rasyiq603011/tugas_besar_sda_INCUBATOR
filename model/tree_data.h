#ifndef TREE_DATA_H
#define TREE_DATA_H
#include "data_struct.h"

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
    Film* film;
    Jadwal* jadwal;
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
bool is_tree_empty(Tree T);
bool is_tree_leaf(address P);
bool has_sibling(address P);
bool has_child(address P);

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