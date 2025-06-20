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
            const char* judul_film = get_judul_film(film);
            const char* nama_jadwal = get_film_name(jadwal);
            if (!judul_film || !nama_jadwal) continue;

            if (strcmp(judul_film, nama_jadwal) == 0)
            {
                set_film_object(jadwal, film);
                break;
            }
        }
    }
}

boolean handle_input_data_jadwal(Time* time_start, Time* time_end, date* date_jadwal, String* judul_film, int* harga_tiket) 
{
    String waktu_start = NULL, waktu_end = NULL, tanggal_tayang = NULL;

    input_jadwal(&waktu_start, &waktu_end, &tanggal_tayang, judul_film, harga_tiket);

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

    if (!isValidTime(*time_start) && !isValidTime(*time_end) && !isValid(*date_jadwal))
    {
        return false;
    }
    free(waktu_start);
    free(waktu_end);
    free(tanggal_tayang);
    return true;
}

boolean handle_input_data_event(char** nama_event, char** judul_film, date* tanggal_mulai, date* tanggal_akhir, int* jumlah_sesi, int* jumlah_kuota_sesi) 
{
    char* date_start = NULL, *date_end = NULL;

    input_event(nama_event, judul_film, &date_start, &date_end, jumlah_sesi, jumlah_kuota_sesi);

    if (string_to_date(date_start, tanggal_mulai) || string_to_date(date_start, tanggal_mulai))
    {
        printf("tanggal tidak valid");
        return false; 
    }

    if (*jumlah_kuota_sesi < 0 || *jumlah_sesi < 0)
    {
        printf("sesi yang dimasukan tidak valid");
        return false;
    }

    if (!isValid(*tanggal_mulai) && !isValid(*tanggal_akhir))
    {
        return false;
    }
    return true;
}
