#include "tree_data.h"

// ===================================================
// =========== CONSTRUCTOR & INIT SECTION ============
// ===================================================

// Inisialisasi pohon: jika pohon kosong, root diset NULL
void init_tree(Tree* T)
{
    if (is_tree_empty(*T))
    {
        T->root = NULL;
    }    
}

// Membuat simpul baru sesuai tipe dan info yang diberikan
address create_node(InfoType info, DataType tipe)
{
    address new_node = (address) malloc(sizeof(ElmtList));
    new_node->tipe = tipe;
    new_node->first_son = NULL;
    new_node->next_brother = NULL;

    switch(tipe){
        case TYPE_PROVINSI:
            new_node->info.provinsi = /* Panggil constructor struct Provinsi */;
            break;
        case TYPE_KOTA:
            new_node->info.kota = /* Panggil constructor struct Kota */;
            break;
        case TYPE_BIOSKOP:
            new_node->info.bioskop = /* Panggil constructor struct Bioskop */;
            break;
        case TYPE_FILM:
            new_node->info.film = /* Panggil constructor struct Film */;
            break;
    }

    return new_node;
}

// ===================================================
// ================== VALIDATOR SECTION ==============
// ===================================================

// Mengecek apakah tree kosong (root == NULL)
bool is_tree_empty(Tree T)
{
    return (T.root == NULL);
}

// Mengecek apakah node adalah daun (tidak memiliki anak)
bool is_tree_leaf(address P)
{
    return (P != NULL && P->first_son == NULL);
}

// Mengecek apakah node memiliki saudara
bool has_sibling(address P)
{
    return (P != NULL && P->next_brother != NULL);
}

// Mengecek apakah node memiliki anak
bool has_child(address P)
{
    return (P != NULL && P->first_son != NULL);
}

// ===================================================
// ================ ACCESSOR SECTION =================
// ===================================================

// Mengembalikan pointer ke anak pertama
address get_first_son(address P)
{
    return P->first_son;
}

// Mengembalikan pointer ke anak terakhir
address get_last_son(address P)
{
    address last_son = P->first_son;
    while (last_son->next_brother != NULL)
    {
        last_son = last_son->next_brother;
    }
    return last_son;
}

// Mengembalikan pointer ke saudara berikutnya
address get_next_brother(address P)
{
    return P->next_brother;
}

// Mengembalikan info data dari node
InfoType get_info_node(address P)
{
    return P->info;
}

// Mengembalikan tipe data dari node
DataType get_tipe_node(address P)
{
    return P->tipe;
}

// ===================================================
// ================== MUTATOR SECTION ================
// ===================================================

// Menambahkan child baru ke simpul parent
void add_child(address parent, InfoType info, DataType tipe)
{
    if (parent->first_son == NULL)
    {
        parent->first_son = create_node(info, tipe);
        return;
    }

    address last_son = get_last_son(parent);
    last_son->next_brother = create_node(info, tipe);
}

// ===================================================
// ================ DESTRUCTOR SECTION ==============
// ===================================================

// Menghapus seluruh node dari tree secara rekursif
void delete_tree(Tree* T)
{
    if (!is_tree_empty(*T))
    {
        delete_tree_rekursif(T->root);
    }
}

// Fungsi rekursif untuk menghapus seluruh node dari tree
void delete_tree_rekursif(address P)
{
    if (P == NULL) return;

    delete_tree_rekursif(P->first_son);
    delete_tree_rekursif(P->next_brother);
    free(P);
}
