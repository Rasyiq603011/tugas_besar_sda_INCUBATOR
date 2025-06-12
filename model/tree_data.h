#ifndef TREE_DATA_H
#define TREE_DATA_H
#include "data_struct/negara.h"
#include "data_struct/provinsi.h"
#include "data_struct/kota.h"
#include "data_struct/bioskop.h"
#include "data_struct/studio.h"
#include "data_struct/user.h"
#include "data_struct/user.h"
#include "stdlib.h"
#include "stdbool.h"

// ==============================
// ==== TYPE DEFINITIONS ========
// ==============================

typedef enum
{
    TYPE_NEGARA = 0,
    TYPE_PROVINSI = 1,
    TYPE_KOTA = 2,
    TYPE_BIOSKOP = 3,
    TYPE_STUDIO = 4,
}DataType;

typedef union 
{
    Negara* negara;
    Provinsi* provinsi;
    Kota* kota;
    Bioskop* bioskop;
    Studio* studio;
} InfoType;

typedef struct tElmtList* address;
typedef struct tElmtList 
{
    InfoType info;
    DataType tipe;
    address first_son;
    address next_brother;
} ElmtList;

typedef struct Tree
{
    address root;    
}Tree;

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
void delete_tree_rekursif(address P);

// Traversal
void traversal_preorder(Tree T, void (*Process) (address));
void TraverseBFS(Tree T, void (*Process)(address)) ;

#endif
