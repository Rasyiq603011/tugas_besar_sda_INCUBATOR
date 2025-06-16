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
            create_provinsi(&(new_node)->info.provinsi, get_name_provinsi(info.provinsi), get_pendapatan_provinsi(info.provinsi), get_jumlah_bioskop_provinsi(info.provinsi));
            break;
        case TYPE_KOTA:
            create_kota(&(new_node->info.kota), get_name_kota(info.kota), get_pendapatan_kota(info.kota), get_jumlah_bioskop_kota(info.kota));
            break;
        case TYPE_BIOSKOP:
            create_bioskop(&(new_node->info.bioskop), get_name_bioskop(info.bioskop), get_pendapatan_bioskop(info.bioskop), get_alamat_bioskop(info.bioskop)); 
            break;
        case TYPE_STUDIO:
            create_studio(&(new_node->info.studio), get_name_studio(info.studio), get_pendapatan_studio(info.studio), get_jumlah_kursi_studio(info.studio));
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

// Mengembalikan jumlah leaf pada tree
int get_jumlah_leaf(address P)
{
    if (P == NULL) return 0;

    if (P->first_son == NULL) return 1;
    
    int jumlah_leaf = 0;
    address anak = P->first_son;
    while (anak != NULL)
    {
        jumlah_leaf += get_jumlah_leaf(anak);
        anak = anak->next_brother;
    }
    return jumlah_leaf;
}

// Mengembalikan jumlah node dengan tipe tertentu pada tree
int get_jumlah_node_by_type(address P, DataType tipe)
{
    if (P == NULL) return 0;

    int jumlah_node = 0;

    if (P->tipe == tipe)
    {
        jumlah_node = 1;
    }

    jumlah_node += get_jumlah_node_by_type(P->first_son, tipe);
    jumlah_node += get_jumlah_node_by_type(P->next_brother, tipe);
    return jumlah_node;
}

int get_jumlah_anak(address P)
{
    if (P == NULL) return 0;

    int jumlah_anak = 1;
    while (P->next_brother != NULL)
    {
        P = P->next_brother;
        jumlah_anak++;
    }
    return jumlah_anak;
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
// ================ DESTRUCTOR SECTION ===============
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

// ===================================================
// ================ TRAVERSAL SECTION ================
// ===================================================

// Fungsi untuk traversal secara pre-order
void traversal_preorder(Tree T, void (*Process) (address))
{
    if (!is_tree_empty)
    {
        traversal_preorder_rekursif(T.root, Process);
    }
}

// Fungsi rekursif traversal pre-order
void traversal_preorder_rekursif(address start, void (*Process) (address))
{
    if (start == NULL) return;

    Process(start);
    traversal_preorder_rekursif(start->first_son, Process);
    traversal_preorder_rekursif(start->next_brother, Process);
}

// FUungsi untuk traversal level-order
void TraverseBFS(Tree T, void (*Process)(address)) {
    if (is_tree_empty(T)) return;
    
    // Inisialisasi queue untuk BFS
    #define MAX_QUEUE 1000
    address queue[MAX_QUEUE];
    int front = 0, rear = 0;
    
    // Enqueue root
    queue[rear++] = T.root;
    
    while (front < rear) {
        // Dequeue node
        address P = queue[front++];
        
        // Proses node saat ini
        Process(P);
        
        // Enqueue semua anak
        address Child = P->first_son;
        while (Child != NULL) {
            queue[rear++] = Child;
            
            // Cek overflow
            if (rear >= MAX_QUEUE) {
                printf("Error: Queue overflow in BFS!\n");
                return;
            }
            
            Child = Child->next_brother;
        }
    }
    
    #undef MAX_QUEUE
}

// ===================================================
// ==================== CONVERTER ====================
// ===================================================

int convert_children_to__array(address parent, void*** out_array) 
{
    if (parent == NULL || parent->first_son == NULL)
    {
        *out_array = NULL;
        return 0;
    }

    int count = get_jumlah_anak(parent->first_son);
    void** array = (void**)malloc(sizeof(void*) * count);

    address curr = parent->first_son;
    int i = 0;
    while (curr != NULL && i < count) 
    {
        array[i++] = (void*)curr;  // casting address to void*
        curr = curr->next_brother;
    }

    *out_array = array;
    return count;
}

