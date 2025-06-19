#include "handle_crud_tree.h"

void handle_inisialisasi_data(Tree* tree, List* list_film)
{
    load_from_binary(list_film);
    tree->root = load_tree_from_file(DATABASE_BIOSKOP);
    mutator_traversal_preorder(*tree, linked_jadwal_to_film, (void*) list_film); 
}

void handle_saving_data(Tree* tree, List* list_film)
{
    mutator_traversal_preorder(*tree, linked_jadwal_to_film, (void*) list_film); 
    save_to_file(*list_film);
    save_tree_to_file(tree->root, DATABASE_BIOSKOP);
}

void linked_jadwal_to_film(address node, void* context) {
    if (get_tipe_node(node) != TYPE_STUDIO) return;

    List* list_film = (List*)context;

    List* jadwal_list = get_jadwal_studio(info_studio(node));
    pnode current_jadwal;
    for ( current_jadwal = First(*jadwal_list); current_jadwal != NULL; current_jadwal = Next(current_jadwal)) {
        Jadwal* jadwal = info_jadwal(current_jadwal);
        if (!jadwal || is_jadwal_linked(jadwal)) continue;

        pnode current_film;
        for ( current_film = First(*list_film); current_film != NULL; current_film = Next(current_film)) 
        {
            Film* film = info_film(current_film);
            if (strcmp(get_judul_film(film), get_film_name(jadwal)) == 0) 
            {
                set_film_object(jadwal, film);
                break;
            }
        }
    }
}

boolean handle_input_data_jadwal(Time* time_start, Time* time_end, date* date_jadwal, String judul_film, int* harga_tiket) 
{
    String waktu_start, waktu_end, tanggal_tayang;

    input_jadwal(waktu_start, waktu_end, tanggal_tayang, judul_film, harga_tiket);

    if (string_to_time(waktu_start, time_start) || string_to_time(waktu_end, time_end)) 
    {
        printf("waktu tidak valid");
        return false;
    }

    if (string_to_date(tanggal_tayang, date_jadwal))
    {
        printf("tanggal tidak valid");
        return false; 
    }

    if (*harga_tiket < 0)
    {
        printf("harga yang dimasukan tidak valid");
        return false;
    }
}

boolean handle_input_data_event(Time* time_start, Time* time_end, date* date_jadwal, String judul_film, int* harga_tiket) 
{
    String waktu_start, waktu_end, tanggal_tayang;

    input_jadwal(waktu_start, waktu_end, tanggal_tayang, judul_film, harga_tiket);

    if (string_to_time(waktu_start, time_start) || string_to_time(waktu_end, time_end)) 
    {
        printf("waktu tidak valid");
        return false;
    }

    if (string_to_date(tanggal_tayang, date_jadwal))
    {
        printf("tanggal tidak valid");
        return false; 
    }

        if (*harga_tiket < 0)
    {
        printf("harga yang dimasukan tidak valid");
        return false;
    }
}
