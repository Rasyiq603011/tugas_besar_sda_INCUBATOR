#include "handle_menu_pemilihan.h"

// ======================================================
// ============== PEMILIHAN NEGARA SECTION ==============
// ======================================================

//void handle_pemilihan_negara(address root)
//{
//    void** array;
//    int jumlah = convert_children_to__array(root, &array);

//    int pilihan = scrollable_menu(array, jumlah, tampilan_negara, "Tampilan Negara", 3, 1);
    // KALO PILIHAN -1 LANGSUNG RETURN
//    free(array);
//    handle_pemilihan_provinsi(root);
//}

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

pnode handle_pemilihan_jadwal(List current_jadwal)
{
    int jumlah, pilihan;
    void** array = list_to_array(current_jadwal, &jumlah);
    pilihan = scrollable_menu(array, jumlah, tampilan_jadwal, "Jadwal yang Tersedia", 3, 4);
    free(array);
    return get_node_at(current_jadwal, pilihan);
}

// ======================================================
// =========== PEMILIHAN EVENT FILM SECTION ============
// ======================================================

pnode handle_pemilihan_event(List current_event)
{
    int jumlah, pilihan;
    void** array = list_to_array(current_event, &jumlah);
    pilihan = scrollable_menu(array, jumlah, tampilan_event, "Event yang Tersedia", 3, 4);
    free(array);
    return get_node_at(current_event, pilihan);
}
