#include "handle_menu_admin.h"

// ==============================================================
// =========== NAVIGASI PEMILIHAN MENU STACK SECTION ============
// ==============================================================

void navigasi_tree_for_admin(Tree bioskop, DataType nav_for)
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

        DataType type = get_tipe_node(current);
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

            if (get_tipe_node(current) == TYPE_STUDIO) 
            {
                if (nav_for == TYPE_JADWAL)
                {
                    management_jadwal(get_info_node(current).studio);
                }
                if (nav_for == TYPE_EVENT)
                {
                    management_event(get_info_node(current).studio);
                }
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


// ===========================================================
// ============== MENU MANAGEMENT JADWAL SECTION =============
// ===========================================================

void management_jadwal(Studio* current_studio)
{
    while (1)
    {
        int pilihan;
        const int jumlah_opsi = 4;
        const char* options[] = {
            "TAMBAH JADWAL",
            "HAPUS JADWAL",
            "KEMBALI KE MENU UTAMA",
            "KEMBALI"
        };
        const char* header = "MANAGEMENT EVENT";
        pilihan = handle_display_menu(jumlah_opsi, options, header);
    
        switch (pilihan) 
        {
            case 0: 
                handle_tambah_jadwal(current_studio);
                break;
                
            case 1:
                handle_hapus_jadwal(current_studio);
                break;
                
            case 2: 
                // balik ke menu utama Admin
                break;
                
            case 3: 
                // kembali ke pemilihan studio
                return;
            default:
                break;
        }
    }
}

void handle_tambah_jadwal(Studio* current_studio)
{
    if (!current_studio) return;

    Time waktu_start, waktu_end;
    date tanggal;
    String judul_film = NULL;
    int harga_tiket, jumlah_kursi;
    List* daftar_jadwal = get_jadwal_studio(current_studio);

    while (1) 
    {

        boolean input_sukses = handle_input_data_jadwal(&waktu_start, &waktu_end, &tanggal, judul_film, &harga_tiket) ;

        if (!input_sukses) 
        {
            printf("❌ Input tidak valid.\n");
        }
         else if (is_exits_jadwal(*daftar_jadwal, tanggal, waktu_start, waktu_end)) 
        {
            printf("❌ Jadwal bentrok dengan jadwal lain!\n");
        }
         else 
        {

            Jadwal* jadwal_baru = constructor_jadwal(waktu_start, waktu_end, tanggal, harga_tiket, judul_film, jumlah_kursi);
            free(judul_film);
            judul_film = NULL;
            if (!jadwal_baru) 
            {
                printf("❌ Gagal membuat jadwal!\n");
                continue;
            }

            insert_value_last(&daftar_jadwal->First, JADWAL_INFO(jadwal_baru), TYPE_JADWAL);
            printf("✅ Jadwal berhasil ditambahkan!\n");
            break;
        }

        if (judul_film) 
        {
            free(judul_film);
            judul_film = NULL;
        }

        char opsi;
        printf("Apakah Anda ingin melanjutkan tambah jadwal ? (y/n): ");
        scanf(" %c", &opsi); getchar(); 

        if (opsi == 'n' || opsi == 'N') {
            printf("Proses pembatalan penambahan jadwal.\n");
            break;
        }
    }
}


void handle_hapus_jadwal(Studio* current_studio)
{
    pnode selected_jadwal = handle_pemilihan_jadwal(*get_all_jadwal(current_studio));

    if (selected_jadwal == NULL) return;
    
    delete_by_address(&(get_all_jadwal(current_studio)->First), selected_jadwal);
    
}


// ===============================================
// ============== EVENT MENU SECTION =============
// ===============================================

void management_event(Studio* Studio)
{
    while (1)
    {
        int pilihan;
        const int jumlah_opsi = 4;
        const char* options[] = {
            "TAMBAH EVENT",
            "PROSES ANTRIAN EVENT",
            "HAPUS EVENT",
            "KEMBALI"
        };
        const char* header = "MANAGEMENT EVENT";
        pilihan = handle_display_menu(jumlah_opsi, options, header);
    
        switch (pilihan) 
        {
            case 0: 
                handle_tambah_event(Studio);
                break;
                
            case 1:
                handle_proses_antrian_event(Studio);
                break;
                
            case 2: 
                handle_hapus_event(Studio);
                break;
            case 3: 
                return;
            default:
                break;
        }
    }
}

void handle_tambah_event(List* jadwal_studio)
{
    String nama_event, waktu_start, waktu_end, judul_film;
    int jumlah_kuota_sesi, jumlah_sesi;

    input_event(nama_event, judul_film, waktu_start, waktu_end, &jumlah_sesi, &jumlah_kuota_sesi);
    date start, end;
    if (!string_to_date(waktu_start, &start))
    {
        start = getTodayDate();
    }
    if (!string_to_date(waktu_end, &end))
    {
        end = getTodayDate();
    }

    Event* new_event = constructor_event(nama_event, start ,end , judul_film, jumlah_kuota_sesi, jumlah_sesi);
    if (!new_event) return;
    
    insert_value_last(&(First(*jadwal_studio)), EVENT_INFO(new_event), TYPE_EVENT);
}

void handle_proses_antrian_event(Studio* current_studio)
{
    pnode selected_event = handle_pemilihan_event(*get_all_event(current_studio));

    if (selected_event == NULL) return;

    int jumlah_proses = proses_antrian_event(get_event_queue(info_event(selected_event)),get_event_daftar_user(info_event(selected_event)), get_total_kuota(info_event(selected_event)));
}

int proses_antrian_event(Queue* antrian_user, QueueData* antrian_fix, int maxSize)
{
    if (!antrian_user || !antrian_fix || maxSize <= 0) return 0;

    int count = 0;
    while (!isPriorityQueueEmpty(antrian_user) && count < maxSize) 
    {
        QueueData data = dequeuePriority(antrian_user);
        if (data) 
        {
            antrian_fix[count++] = data;
        }
    }
    return count;
}

void handle_hapus_event(Studio* current_studio)
{
    pnode selected_event = handle_pemilihan_event(*get_all_event(current_studio));

    if (selected_event == NULL) return;
    
    delete_by_address(&(get_all_event(current_studio)->First), selected_event);
}