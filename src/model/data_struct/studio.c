#include "studio.h"

struct DataStudio {
    String nama_studio;
    int total_pendapatan_studio;
    int jumlah_kursi_studio;
    List* jadwal_studio;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Studio* constructor_studio(const String nama, int total_pendapatan, int jumlah_kursi)
{
    if (!nama) return NULL;

    Studio* new_studio = (Studio*)malloc(sizeof(Studio));
    if (!new_studio) return NULL;

    new_studio->nama_studio = strdup(nama);
    if (!new_studio->nama_studio) 
    {
        free(new_studio);
        return NULL;
    }

    new_studio->total_pendapatan_studio = total_pendapatan;
    new_studio->jumlah_kursi_studio = jumlah_kursi;
    CreateList(new_studio->jadwal_studio);
    return new_studio;
}

void create_studio(Studio** new_studio, String nama, int total_pendapatan, int jumlah_kursi)
{
    *new_studio = constructor_studio(nama, total_pendapatan, jumlah_kursi);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name_studio(const Studio* current_studio) 
{
    if (!current_studio) return NULL;
    return current_studio->nama_studio;
}

int get_pendapatan_studio(const Studio* current_studio)
{
    if (!current_studio) return -1; 
    return current_studio->total_pendapatan_studio;
}

List* get_jadwal_studio(const Studio* current_studio) 
{
    if (!current_studio) return NULL;
    return current_studio->jadwal_studio;
}

int get_jumlah_kursi_studio(const Studio* current_studio) {
    if (!current_studio) return -1; 
    return current_studio->jumlah_kursi_studio;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_studio(Studio* current_studio, String name) {
    if (!current_studio || !name) return;
    free(current_studio->nama_studio);
    current_studio->nama_studio = strdup(name);
}

void set_pendapatan_studio(Studio* current_studio, int pendapatan) {
    if (!current_studio) return;
    current_studio->total_pendapatan_studio = pendapatan;
}

void set_jadwal_studio(Studio* current_studio, List* jadwal) {
    if (!current_studio) return;
    clear_list(&(current_studio->jadwal_studio->First));
    copy_list(*(current_studio->jadwal_studio), jadwal);
}

void set_jumlah_kursi_studio(Studio* current_studio, int jumlah_kursi) {
    if (!current_studio) return;
    current_studio->jumlah_kursi_studio = jumlah_kursi;
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_studio(Studio* current_studio)
{
    if (!current_studio) return;
    free(current_studio->nama_studio);
    clear_list(&(current_studio->jadwal_studio->First));
    free(current_studio);
}

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

int compare_studio_value(const Studio* studio_pertama, const Studio* studio_kedua) 
{
    if (!studio_pertama || !studio_kedua) return 0;
    return 
    (
    strcmp(studio_pertama->nama_studio, studio_kedua->nama_studio) == 0 &&
    studio_pertama->jumlah_kursi_studio == studio_kedua->jumlah_kursi_studio &&
    studio_pertama->total_pendapatan_studio == studio_pertama->total_pendapatan_studio &&
    compare_list(*(studio_pertama->jadwal_studio), *(studio_kedua->jadwal_studio))
    );
}

List* get_jadwal_by_date(List jadwal, date tanggal)
{
    if (ListEmpty) return NULL;

    List* filter_list;
    CreateList(filter_list);
    pnode current_jadwal;
    current_jadwal = jadwal.First;

    while (current_jadwal != NULL)
    {
        if (compare_date(get_tanggal_tayang(info_jadwal(current_jadwal)), tanggal))
        {
            insert_value_last(&(filter_list->First), Info(current_jadwal), Type(current_jadwal));
        }
    }
    return filter_list;
} 

int is_exits_jadwal(List Jadwal, date tanggal, Time start, Time end)
{
    if (ListEmpty(Jadwal)) return 0;
    List* filter_list = get_jadwal_by_date(Jadwal, tanggal);
    pnode current_jadwal;
    current_jadwal = filter_list->First;
    while (current_jadwal != NULL)
    {
        if (is_time_in_arrange(get_waktu_start(info_jadwal(current_jadwal)), 
                               get_waktu_end(info_jadwal(current_jadwal)), start) ||
            is_time_in_arrange(get_waktu_start(info_jadwal(current_jadwal)), 
                               get_waktu_end(info_jadwal(current_jadwal)), end)
            )
        {
            return 1;
        }
    }
    return 0;
}
