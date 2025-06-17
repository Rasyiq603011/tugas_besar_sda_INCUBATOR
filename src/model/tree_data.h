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

// =====================================
// ====== DEFINE MACRO FOR HELPER ======
// =====================================

#define info_integer(P) ((P)->info.integer)
#define info_string(P) ((P)->info.str)
#define info_negara(P) ((P)->info.negara)
#define info_provinsi(P) ((P)->info.provinsi)
#define info_kota(P) ((P)->info.kota)
#define info_bioskop(P) ((P)->info.bioskop)
#define info_studio(P) ((P)->info.studio)
#define NEGARA_INFO(x) ((InfoType){.negara = (x)})
#define PROVINSI_INFO(x) ((InfoType){.provinsi = (x)})
#define KOTA_INFO(x) ((InfoType){.kota = (x)})
#define BIOSKOP_INFO(x) ((InfoType){.bioskop = (x)})
#define STUDIO_INFO(x) ((InfoType){.studio = (x)})

// ==============================
// ====== FUNCTION HEADERS =====
// ==============================

// ===================================================
// =========== CONSTRUCTOR & INIT SECTION ============
// ===================================================

// Inisialisasi pohon: jika pohon kosong, root diset NULL

void init_tree(Tree* T);

// Membuat simpul baru sesuai tipe dan info yang diberikan

address create_node(InfoType info, DataType tipe);

// ===================================================
// ================== VALIDATOR SECTION ==============
// ===================================================

// Mengecek apakah tree kosong (root == NULL)

bool is_tree_empty(Tree T);

// Mengecek apakah node adalah daun (tidak memiliki anak)

bool is_tree_leaf(address P);

// Mengecek apakah node memiliki saudara

bool has_sibling(address P);

// Mengecek apakah node memiliki anak

bool has_child(address P);

// ===================================================
// ================ ACCESSOR SECTION =================
// ===================================================

// Mengembalikan pointer ke anak pertama

address get_first_son(address P);

// Mengembalikan pointer ke anak terakhir

address get_last_son(address P);

// Mengembalikan pointer ke saudara berikutnya

address get_next_brother(address P);

// Mengembalikan info data dari node

InfoType get_info_node(address P);

// Mengembalikan tipe data dari node

DataType get_tipe_node(address P);

// Mengembalikan jumlah leaf pada tree

int get_jumlah_leaf(address P);

// Mengembalikan jumlah node dengan tipe tertentu pada tree

int get_jumlah_node_by_type(address P, DataType tipe);

// Mengembalikan jumlah anak 
int get_jumlah_anak(address P);


// ===================================================
// ================== MUTATOR SECTION ================
// ===================================================

// Menambahkan child baru ke simpul parent

void add_child(address* parent, InfoType info, DataType tipe);

// ===================================================
// ================ DESTRUCTOR SECTION ===============
// ===================================================

// Menghapus seluruh node dari tree secara rekursif

void delete_tree(Tree* T);

// Fungsi rekursif untuk menghapus seluruh node dari tree

void delete_tree_rekursif(address P);

// ===================================================
// ================ TRAVERSAL SECTION ================
// ===================================================

// Fungsi untuk traversal secara pre-order

void traversal_preorder(Tree T, void (*Process) (address));

// Fungsi rekursif traversal pre-order

void traversal_preorder_rekursif(address start, void (*Process) (address));

// FUungsi untuk traversal level-order

void TraverseBFS(Tree T, void (*Process)(address));

// ===================================================
// ==================== CONVERTER ====================
// ===================================================

int convert_children_to__array(address parent, void*** out_array);

#endif
