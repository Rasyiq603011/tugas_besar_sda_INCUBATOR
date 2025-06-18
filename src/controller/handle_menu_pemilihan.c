#include "handle_menu_pemilihan.h"

// ======================================================
// ============== PEMILIHAN NEGARA SECTION ==============
// ======================================================

void handle_pemilihan_negara(address root)
{
    void** array;
    int jumlah = convert_children_to__array(root, &array);

    int pilihan = scrollable_menu(array, jumlah, tampilan_negara, "Tampilan Negara", 3, 1);
    // KALO PILIHAN -1 LANGSUNG RETURN
    free(array);
    handle_pemilihan_provinsi(root);
}

// ======================================================
// ============= PEMILIHAN PROVINSI SECTION =============
// ======================================================
void handle_pemilihan_provinsi(address root)
{
    void** array;
    int jumlah = convert_children_to__array(root, &array);
    int pilihan = scrollable_menu(array, jumlah, tampilan_provinsi, "Tampilan Provinsi", 3, 4);
    free(array);
    handle_pemilihan_kota(get_selected_node(root, pilihan+1));
}

// ======================================================
// ================ PEMILIHAN KOTA SECTION ==============
// ======================================================
void handle_pemilihan_kota(address root)
{
    void** array;
    int jumlah = convert_children_to__array(root, &array);
    int pilihan = scrollable_menu(array, jumlah, tampilan_kota, "Tampilan Kota", 3, 4);
    // KALO PILIHAN -1 LANGSUNG RETURN
    free(array);
    handle_pemilihan_kota(get_selected_node(root, pilihan+1));
}

// ======================================================
// ============== PEMILIHAN BIOSKOP SECTION =============
// ======================================================

void handle_pemilihan_bioskop(address root)
{
    void** array;
    int jumlah = convert_children_to__array(root, &array);
    int pilihan = scrollable_menu(array, jumlah, tampilan_bioskop, "Tampilan Bioskop", 3, 4);
    free(array);
    handle_pemilihan_kota(get_selected_node(root, pilihan+1));
}

// ======================================================
// ============== PEMILIHAN STUDIO SECTION ==============
// ======================================================

void handle_pemilihan_studio(address root)
{
    void** array;
    int jumlah = convert_children_to__array(root, &array);
    int pilihan = scrollable_menu(array, jumlah, tampilan_studio, "Tampilan Studio", 4, 4);
    free(array);
    handle_pemilihan_kota(get_selected_node(root, pilihan+1));
}

// ======================================================
// =========== PEMILIHAN JADWAL FILM SECTION ============
// ======================================================

void handle_pemilihan_jadwal(address root)
{
    void** array;
    int jumlah = convert_children_to__array(root, &array);
    int pilihan = scrollable_menu(array, jumlah, tampilan_jadwal, "Tampilan Jadwal", 2, 5);
}

// ==============================================================
// =========== NAVIGASI PEMILIHAN MENU STACK SECTION ============
// ==============================================================

void navigasi_tree_for_admin(Tree bioskop)
{
    StackTree stack;
    init_stack(&stack);

    address current = bioskop.root;
    const char* title;

    while (true)
    {
        void** array;
        int jumlah = convert_children_to__array(current, &array);
        if (jumlah == 0)
        {
            free(array);
            if (!is_empty(stack)) 
            {
                current = pop(&stack);
                continue;
            }
             else 
            {
                break;
            }
        }

        DataType type = get_type(current);
        void (*render)(int, int, int, void*) = get_renderer_for_type(type);
        const char* title = get_title_for_type(type);

        int pilihan = scrollable_menu(array, jumlah, render, title, 3, 4);
        free(array);

        if (pilihan == -1) {
            if (is_empty(stack)) break;
            current = pop(&stack);
        } else {
            push(&stack, current);
            current = get_selected_node(current, pilihan + 1);

            if (get_type(current) == TYPE_STUDIO) {
                proses_leaf_node(current);
                current = pop(&stack);
            }
        }
    }
}

void (*get_renderer_for_type(DataType type))(int, int, int, void*) 
{
    switch (type) {
        case TYPE_NEGARA: return tampilan_provinsi;
        case TYPE_PROVINSI: return tampilan_kota;
        case TYPE_KOTA: return tampilan_bioskop;
        case TYPE_BIOSKOP: return tampilan_studio;
        default: return;
    }
}

const char* get_title_for_type(DataType type) 
{
    switch (type) {
        case TYPE_NEGARA: return "PILIH PROVINSI";
        case TYPE_PROVINSI: return "PILIH KOTA";
        case TYPE_KOTA: return "PILIH BIOSKOP";
        case TYPE_BIOSKOP: return "PILIH STUDIO";
        default: return "PILIH DATA";
    }
}
