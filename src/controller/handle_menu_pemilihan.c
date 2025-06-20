#include "handle_menu_pemilihan.h"

// ======================================================
// ============= PEMILIHAN PROVINSI SECTION =============
// ======================================================

void handle_pemilihan_provinsi(address root, User* user)
{ 
    int next;
    do{
        void** array;
        int jumlah = convert_children_to__array(root, &array);
        int pilihan = scrollable_menu(array, jumlah, tampilan_provinsi, "Tampilan Provinsi", 3, 4);
        free(array);

        if (pilihan == -1) return;
        
        next = handle_pemilihan_kota(get_selected_node(root, pilihan+1), user);
    } while (next == -1);
    return;
}

// ======================================================
// ================ PEMILIHAN KOTA SECTION ==============
// ======================================================

int handle_pemilihan_kota(address parent, User* user)
{
    int next;
    do{
        void** array;
        int jumlah = convert_children_to__array(parent, &array);
        int pilihan = scrollable_menu(array, jumlah, tampilan_kota, "Tampilan Kota", 3, 4);
        free(array);

        if (pilihan == -1) return -1;
        
        next = handle_pemilihan_bioskop(get_selected_node(parent, pilihan+1), user);
    } while (next == -1);
    return 0;
}

// ======================================================
// ============== PEMILIHAN BIOSKOP SECTION =============
// ======================================================

int handle_pemilihan_bioskop(address parent, User* user)
{
    int next;
    do{
        void** array;
        int jumlah = convert_children_to__array(parent, &array);
        int pilihan = scrollable_menu(array, jumlah, tampilan_bioskop, "Tampilan Bioskop", 3, 4);
        free(array);

        if (pilihan == -1) return -1;
        
        next = handle_pemilihan_studio(get_selected_node(parent, pilihan+1), user);
    } while (next == -1);
    return 0;
}

// ======================================================
// ============== PEMILIHAN STUDIO SECTION ==============
// =====================================================

int handle_pemilihan_studio(address parent, User* user)
{
    int next;
    do {
        void** array;
        int jumlah = convert_children_to__array(parent, &array);
        int pilihan = scrollable_menu(array, jumlah, tampilan_studio, "Tampilan Studio", 3, 4);
        free(array);

        if (pilihan == -1) return -1;

        next = handle_pemilihan_kursi(get_selected_node(parent, pilihan+1), user);
    } while (next == -1);
    return 0;
}


// ======================================================
// =========== PEMILIHAN JADWAL FILM SECTION ============
// ======================================================

int handle_pemilihan_jadwal(List current_jadwal, pnode* out_node)
{
    int jumlah, pilihan;
    void** array = list_to_array(current_jadwal, &jumlah);
    pilihan = scrollable_menu(array, jumlah, tampilan_jadwal, "Jadwal yang Tersedia", 3, 4);
    free(array);

    if (pilihan == -1) return -1;

    *out_node = get_node_at(current_jadwal, pilihan);
    return 0;
}

// ======================================================
// ============== PEMILIHAN KURSI SECTION ===============
// ======================================================

int handle_pemilihan_kursi(address studio, User* user)
{
    List* current_jadwal = get_all_jadwal(studio->info.studio);
    pnode node_jadwal = NULL;
    int kembali = handle_pemilihan_jadwal(*current_jadwal, &node_jadwal);

    if (kembali == -1 || node_jadwal == NULL) return -1;

    Jadwal* jadwal_dipilih = info_jadwal(node_jadwal);
    int jumlah_kursi = get_jumlah_tiket(jadwal_dipilih);
    Kursi** daftar_kursi = get_daftar_kursi(jadwal_dipilih);
    Kursi* selected_kursi = pemilihan_kursi(jumlah_kursi, daftar_kursi);

    if (selected_kursi == NULL) return handle_pemilihan_kursi(studio, user); 

    system("cls");
    String info_kursi;
    sprintf(info_kursi, "%d", get_id_kursi(selected_kursi));
    Riwayat* new_riwayat = create_riwayat(get_film_name(current_jadwal->First->info.jadwal), date_to_string(get_tanggal_tayang(jadwal_dipilih)), time_to_string(get_waktu_start(jadwal_dipilih)), get_harga_tiket(jadwal_dipilih), info_kursi);
    add_riwayat_user(user, new_riwayat);
    return 0;
}
// ======================================================
// ============== PEMILIHAN KURSI SECTION ===============
// ======================================================

pnode handle_pemilihan_event(List current_event)
{
    int jumlah, pilihan;
    void** array = list_to_array(current_event, &jumlah);
    pilihan = scrollable_menu(array, jumlah, tampilan_event, "Event yang Tersedia", 3, 4);
    free(array);
    return get_node_at(current_event, pilihan);
}
