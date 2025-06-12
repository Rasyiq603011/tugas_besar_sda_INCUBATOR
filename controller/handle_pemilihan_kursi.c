#include "handle_pemilihan_kursi.h"

void set_attribut_kursi(int jumlah_kursi, CHAR_INFO* visual_kursi[], Kursi* daftar_kursi[], int terpilih, int offset) 
{
    int current_kursi;
    for (current_kursi = 0; current_kursi < jumlah_kursi; current_kursi++) 
    {
        visual_kursi[current_kursi] = (CHAR_INFO*)malloc(HEIGHT_KURSI * WIDTH_KURSI * sizeof(CHAR_INFO));
        int id = get_id_kursi(daftar_kursi[current_kursi + offset]);
        int tipe = get_tipe_kursi(daftar_kursi[current_kursi + offset]);
        boolean status = get_status_kursi(daftar_kursi[current_kursi + offset]);
        boolean is_selected = (current_kursi == terpilih);
        set_char_visual_kursi(id, tipe, status, is_selected, visual_kursi[current_kursi]);
    }
}

void display_kursi(int jumlah_kursi, Kursi* daftar_kursi[], int terpilih, int page) 
{
    CHAR_INFO* visual_kursi[JUMLAH_TAMPILAN_KURSI_MAKS];
    int current_kursi;
    int offset = page * JUMLAH_TAMPILAN_KURSI_MAKS;
    int display_count = min(jumlah_kursi - offset, JUMLAH_TAMPILAN_KURSI_MAKS);
    int total_pages = (jumlah_kursi + JUMLAH_TAMPILAN_KURSI_MAKS - 1) / JUMLAH_TAMPILAN_KURSI_MAKS;

    out = GetStdHandle(STD_OUTPUT_HANDLE);
    set_attribut_kursi(display_count, visual_kursi, daftar_kursi, terpilih, offset);
    inisialisasi_small_rect();
    display_legend(page, total_pages);

    for (current_kursi = 0; current_kursi < display_count; current_kursi++) 
    {
        WriteConsoleOutput(out, visual_kursi[current_kursi], size_kursi, pusat, &posisi_kursi[current_kursi]);
    }

    for (current_kursi = 0; current_kursi < display_count; current_kursi++) 
    {
        free(visual_kursi[current_kursi]);
    }
}

int kelola_operasi(int key, int current_option, int jumlah_kursi, int* page) 
{
    int new_option = current_option;
    int total_pages = (jumlah_kursi + JUMLAH_TAMPILAN_KURSI_MAKS - 1) / JUMLAH_TAMPILAN_KURSI_MAKS;
    int display_count = min(jumlah_kursi - (*page * JUMLAH_TAMPILAN_KURSI_MAKS), JUMLAH_TAMPILAN_KURSI_MAKS);

    switch (key) 
    {
        case 72: // UP ARROW
            if (new_option >= JUMLAH_TAMPILAN_KOLOM_KURSI)
                new_option -= JUMLAH_TAMPILAN_KOLOM_KURSI;
            break;
        case 80: // DOWN ARROW
            if (new_option + JUMLAH_TAMPILAN_KOLOM_KURSI < display_count)
                new_option += JUMLAH_TAMPILAN_KOLOM_KURSI;
            break;
        case 75: // LEFT ARROW
            if (new_option % JUMLAH_TAMPILAN_KOLOM_KURSI > 0)
                new_option -= 1;
            break;
        case 77: // RIGHT ARROW
            if (new_option % JUMLAH_TAMPILAN_KOLOM_KURSI < JUMLAH_TAMPILAN_KOLOM_KURSI - 1 && new_option + 1 < display_count)
                new_option += 1;
            break;
        case 73: // PAGE UP
            if (*page > 0) 
            {
                (*page)--;
                new_option = 0;
            }
            break;
        case 81: // PAGE DOWN
            if (*page < total_pages - 1) 
            {
                (*page)++;
                new_option = 0;
            }
            break;
        default:
            return current_option;
    }

    return new_option;
}

void pemilihan_kursi(int jumlah_kursi, Kursi* daftar_kursi[]) {
    int key, option = 0, page = 0;

    while (1) 
    {
        system("cls");
        display_kursi(jumlah_kursi, daftar_kursi, option, page);
        key = _getch();
        if (key == 0 || key == 224) 
        {
            key = _getch();
            option = kelola_operasi(key, option, jumlah_kursi, &page);
        } 
         else if (key == 13) 
        { 
            int global_index = page * JUMLAH_TAMPILAN_KURSI_MAKS + option;
            if (get_status_kursi(daftar_kursi[global_index])) 
            {
                set_status_kursi(daftar_kursi[global_index], false);
                Beep(600, 100);
                char kode = 'A' + get_tipe_kursi(daftar_kursi[global_index]);
                printf("\nKursi %c-%03d berhasil dipesan!\n", kode, get_id_kursi(daftar_kursi[global_index]));
                Sleep(1000);
            }
             else 
            {
                Beep(400, 100);
                char kode = 'A' + get_tipe_kursi(daftar_kursi[global_index]);
                printf("\nKursi %c-%03d sudah dipesan!\n", kode, get_id_kursi(daftar_kursi[global_index]));
                Sleep(1000);
            }
        } 
         else if (key == 27) 
        { // Esc key
            printf("\nKeluar dari pemilihan kursi.\n");
            break;
        }
    }
}
