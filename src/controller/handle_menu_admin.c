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
            if (!is_empty_stack(&stack)) 
            {
                current = pop_stack(&stack);
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
            if (is_empty_stack(&stack)) break;
            current = pop_stack(&stack);
        } else {
            push_stack(&stack, current);
            current = get_selected_node(current, pilihan + 1);

            if (get_tipe_node(current) == TYPE_STUDIO) 
            {
                if (nav_for == TYPE_JADWAL)
                {
                    int aksi = management_jadwal(get_info_node(current).studio);
                    if (aksi == 0) return;
                }
                if (nav_for == TYPE_EVENT)
                {
                    int aksi = management_event(get_info_node(current).studio);
                    if (aksi == 0) return;
                }
                current = pop_stack(&stack);
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
        default: return NULL;
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

int management_jadwal(Studio* current_studio)
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
        const char* header = "MANAGEMENT JADWAL";
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
                return 0;
            case 3: 
                return -1;
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
        system("cls");

        boolean input_sukses = handle_input_data_jadwal(&waktu_start, &waktu_end, &tanggal, &judul_film, &harga_tiket);

        if (!input_sukses) {
            gotoxy(35, 14); printf("❌ Input tidak valid!");
        }
        else if (is_exists_bentrok_for_jadwal(*daftar_jadwal, tanggal, waktu_start, waktu_end)) {
            gotoxy(35, 14); printf("❌ Jadwal bentrok dengan jadwal lain!");
        }
        else 
        {
            Jadwal* jadwal_baru = constructor_jadwal(waktu_start, waktu_end, tanggal, harga_tiket, judul_film, jumlah_kursi);
            free(judul_film);
            judul_film = NULL;

            if (!jadwal_baru) {
                gotoxy(35, 14); printf("❌ Gagal membuat jadwal!");
                Sleep(1000);
                continue;
            }

            insert_value_last(&daftar_jadwal->First, JADWAL_INFO(jadwal_baru), TYPE_JADWAL);
            gotoxy(35, 14); printf("✅ Jadwal berhasil ditambahkan!");
            Sleep(1500);
        }

        const char* opsi[] = { "LANJUT TAMBAH JADWAL", "BATALKAN" };
        int konfirmasi = display_konfirmasi_menu(
            "KONFIRMASI PENAMBAHAN JADWAL",
            "Apakah Anda ingin menambahkan jadwal lainnya?",
            opsi, 2
        );

        if (konfirmasi == 1) {
            gotoxy(35, 16); printf("Keluar dari menu tambah jadwal...");
            Sleep(1000);
            break;
        }
    }
}

void handle_hapus_jadwal(Studio* current_studio)
{
    pnode selected_jadwal;
	int pilihan = handle_pemilihan_jadwal(*get_all_jadwal(current_studio), &selected_jadwal);

    if (selected_jadwal == 0) return;
    
    delete_by_address(&(get_all_jadwal(current_studio)->First), selected_jadwal);
    
}


// ===============================================
// ============== EVENT MENU SECTION =============
// ===============================================

int management_event(Studio* Studio)
{
    while (1)
    {
        int pilihan;
        const int jumlah_opsi = 5;
        const char* options[] = {
            "TAMBAH EVENT",
            "PROSES ANTRIAN EVENT",
            "HAPUS EVENT",
            "KEMBALI KE MENU UTAMA",
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
                return 0;
            case 4: 
                return -1;
            default:
                break;
        }
    }
}

void handle_tambah_event(Studio* current_studio)
{
    if (!current_studio) return;

    String nama_event = NULL, judul_film = NULL;
    date tanggal_mulai, tanggal_akhir;
    int jumlah_sesi, jumlah_kuota_sesi;
    List* daftar_jadwal = get_jadwal_studio(current_studio);

    while (1)
    {
        system("cls");

        // Input dan validasi
        boolean input_sukses = handle_input_data_event(
            &nama_event, &judul_film, &tanggal_mulai, &tanggal_akhir,
            &jumlah_sesi, &jumlah_kuota_sesi
        );

        if (!input_sukses) {
            gotoxy(35, 14); printf("❌ Input tidak valid!");
        }
        else if (is_exists_bentrok_for_event(*daftar_jadwal, tanggal_mulai, tanggal_akhir)) {
            gotoxy(35, 14); printf("❌ Event bentrok dengan event lain!");
        }
        else
        {
            Event* event_baru = constructor_event(nama_event, tanggal_mulai, tanggal_akhir, judul_film, jumlah_kuota_sesi, jumlah_sesi);
            
            free(nama_event);
            free(judul_film);
            nama_event = NULL;
            judul_film = NULL;

            if (!event_baru) {
                gotoxy(35, 14); printf("❌ Gagal membuat event!");
                Sleep(1000);
                continue;
            }

            insert_value_last(&daftar_jadwal->First, EVENT_INFO(event_baru), TYPE_EVENT);
            gotoxy(35, 14); printf("✅ Event berhasil ditambahkan!");
            Sleep(1500);
        }

        const char* opsi[] = { "LANJUT TAMBAH EVENT", "BATALKAN" };
        int konfirmasi = display_konfirmasi_menu(
            "KONFIRMASI PENAMBAHAN EVENT",
            "Apakah Anda ingin menambahkan event lainnya?",
            opsi, 2
        );

        if (konfirmasi == 1) {
            gotoxy(35, 16); printf("Keluar dari menu tambah event...");
            Sleep(1000);
            break;
        }
    }
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
