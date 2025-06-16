#include "handle_menu_pemilihan.h"

// ======================================================
// ============== PEMILIHAN NEGARA SECTION ==============
// ======================================================

void handle_pemilihan_negara(address root)
{
    void** array;
    int jumlah = convert_children_to__array(root, &array);
    int pilihan = scrollable_menu(array, jumlah, tampilan_negara, 3, 4);
    free(array);
    printf("Berhasil");
}

// ======================================================
// ============= PEMILIHAN PROVINSI SECTION =============
// ======================================================
void handle_pemilihan_provinsi(address root)
{
    void** array;
    int jumlah = convert_children_to__array(root, &array);
    int pilihan = scrollable_menu(array, jumlah, tampilan_provinsi, 3, 4);
    free(array);
    printf("Berhasil");
}
// ======================================================
// ================ PEMILIHAN KOTA SECTION ==============
// ======================================================
void handle_pemilihan_kota(address root)
{
    void** array;
    int jumlah = convert_children_to__array(root, &array);
    int pilihan = scrollable_menu(array, jumlah, tampilan_kota, 3, 4);
    free(array);
    printf("Berhasil");
}
// ======================================================
// ============== PEMILIHAN BIOSKOP SECTION =============
// ======================================================

void handle_pemilihan_bioskop(address root)
{
    void** array;
    int jumlah = convert_children_to__array(root, &array);
    int pilihan = scrollable_menu(array, jumlah, tampilan_bioskop, 4, 4);
    free(array);
    printf("Berhasil");
}

// ======================================================
// ============== PEMILIHAN STUDIO SECTION ==============
// ======================================================

void handle_pemilihan_studio(address root)
{
    void** array;
    int jumlah = convert_children_to__array(root, &array);
    int pilihan = scrollable_menu(array, jumlah, tampilan_studio, 4, 4);
    free(array);
    printf("Berhasil");
}
// ======================================================
// =========== PEMILIHAN JADWAL FILM SECTION ============
// ======================================================

