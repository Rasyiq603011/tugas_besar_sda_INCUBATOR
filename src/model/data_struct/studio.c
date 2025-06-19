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

    // *** SOLUSI: Alokasikan pointer List
    new_studio->jadwal_studio = (List*)malloc(sizeof(List));
    if (!new_studio->jadwal_studio) 
	{
        free(new_studio->nama_studio);
        free(new_studio);
        return NULL;
    }
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
    if (current_studio->jadwal_studio) {
        clear_list(&(current_studio->jadwal_studio->First));
        free(current_studio->jadwal_studio);
    }
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

List* get_jadwal_by_date(const List jadwal, date tanggal)
{
    if (ListEmpty(jadwal)) return NULL;

    List* filter_list = (List*)malloc(sizeof(List));
    if (!filter_list) return NULL;
    CreateList(filter_list);

    for (pnode current = jadwal.First; current != NULL; current = Next(current)) 
    {
        if (compare_date(get_tanggal_tayang(info_jadwal(current)), tanggal)) 
        {
            insert_value_last(&(filter_list->First), Info(current), Type(current));
        }
    }

    return filter_list;
}

List* get_jadwal_by_film(Studio* studio, const char* keyword) {
    if (!studio || !keyword || !studio->jadwal_studio) return NULL;

    List* hasil = create_list();
    pnode current = studio->jadwal_studio->First;

    while (current) {
        Jadwal* current_jadwal = info_jadwal(current);

        if (strcasestr_custom(get_film_name(current_jadwal), keyword)) {
            insert_value_last(&(hasil->First), Info(current), Type(current));
        }
        current = current->next;
    }

    return hasil;
}

int is_exits_jadwal(const List Jadwal, date tanggal, Time start, Time end)
{
    if (ListEmpty(Jadwal)) return 0;

    List* filter_list = get_jadwal_by_date(Jadwal, tanggal);
    if (!filter_list) return 0;

    for (pnode current = filter_list->First; current != NULL; current = Next(current)) {
        Time waktu_mulai = get_waktu_start(info_jadwal(current));
        Time waktu_selesai = get_waktu_end(info_jadwal(current));

        if (is_time_in_arrange(waktu_mulai, waktu_selesai, start) ||
            is_time_in_arrange(waktu_mulai, waktu_selesai, end)) 
        {
            clear_list(&(filter_list->First));
            free(filter_list);
            return 1;
        }
    }

    clear_list(&(filter_list->First));
    free(filter_list);
    return 0;
}

Studio* copy_studio(const Studio* original) {
    if (!original) return NULL;

    Studio* copy = (Studio*)malloc(sizeof(Studio));
    if (!copy) return NULL;

    copy->nama_studio = strdup(original->nama_studio);
    if (!copy->nama_studio) {
        free(copy);
        return NULL;
    }

    copy->total_pendapatan_studio = original->total_pendapatan_studio;
    copy->jumlah_kursi_studio = original->jumlah_kursi_studio;

    copy->jadwal_studio = (List*)malloc(sizeof(List));
    if (!copy->jadwal_studio) {
        free(copy->nama_studio);
        free(copy);
        return NULL;
    }
    CreateList(copy->jadwal_studio);

    copy_list(*(copy->jadwal_studio), original->jadwal_studio);

    return copy;
}

char* strcasestr_custom(const char* haystack, const char* needle) 
{
    if (!*needle) return (char*)haystack;

    for (; *haystack; ++haystack) 
    {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && tolower((unsigned char)*h) == tolower((unsigned char)*n)) 
        {
            ++h;
            ++n;
        }

        if (!*n) 
        {
            return (char*)haystack;  // Ditemukan
        }
    }
    return NULL; // Tidak ditemukan
}

int is_exists_bentrok_for_jadwal(const List jadwal, date tanggal, Time start, Time end) 
{
    if (ListEmpty(jadwal)) return 0;

    for (pnode current = jadwal.First; current != NULL; current = Next(current)) 
    {
        if (Type(current) == TYPE_JADWAL)
        {
            date tanggal_jadwal = get_tanggal_tayang(info_jadwal(current));
            if (!compare_date(tanggal_jadwal, tanggal)) continue;
            Time waktu_mulai = get_waktu_start(info_jadwal(current));
            Time waktu_selesai = get_waktu_end(info_jadwal(current));

            if (is_time_in_arrange(waktu_mulai, waktu_selesai, start) ||
                is_time_in_arrange(waktu_mulai, waktu_selesai, end) ||
                is_time_in_arrange(start, end, waktu_mulai)) return 1;
        }

        if (Type(current) == TYPE_EVENT)
        {
            date tanggal_mulai = get_event_start(info_event(current));
            date tanggal_selesai = get_event_end(info_event(current));
            if (compare_date(tanggal_mulai, tanggal)) return 1;
            if (compare_date(tanggal_selesai, tanggal)) return 1;
        }
    }
    return 0;
}

int is_exists_bentrok_for_event(const List jadwal, date tanggal_mulai, date tanggal_selesai) 
{
    if (ListEmpty(jadwal)) return 0;

    for (pnode current = jadwal.First; current != NULL; current = Next(current)) 
    {
        if (Type(current) == TYPE_JADWAL)
        {
            date tanggal_jadwal = get_tanggal_tayang(current);
            if (compare_date(tanggal_jadwal, tanggal_mulai)) return 1;
            if (compare_date(tanggal_jadwal, tanggal_selesai)) return 1;
        }

        if (Type(current) == TYPE_EVENT)
        {
            date tanggal_mulai = get_event_start(info_event(current));
            if (compare_date(tanggal_mulai, tanggal_mulai)) return 1;
            if (compare_date(tanggal_mulai, tanggal_selesai)) return 1;
            date tanggal_selesai = get_event_end(info_event(current));
            if (compare_date(tanggal_selesai, tanggal_mulai)) return 1;
            if (compare_date(tanggal_selesai, tanggal_selesai)) return 1;
        }
    }
    return 0;
}

int compare_waktu_mulai_jadwal(pnode a, pnode b) 
{
    Time t1 = get_waktu_start(info_jadwal(a));
    Time t2 = get_waktu_start(info_jadwal(b));
    return CompareTime(t1, t2);
}

void sort_jadwal_by_start_time(List* jadwal) 
{
    if (ListEmpty(*jadwal)) return;

    pnode sorted = NULL;
    pnode current;
    for (current = First(*jadwal); current != NULL;) 
    {
        pnode next = Next(current);

        if (!sorted || compare_waktu_mulai_jadwal(current, sorted) < 0) 
        {
            Next(current) = sorted;
            sorted = current;
        } else {
            pnode temp = sorted;
            while (Next(temp) && compare_waktu_mulai_jadwal(Next(temp), current) <= 0) 
            {
                temp = Next(temp);
            }
            Next(current) = Next(temp);
            Next(temp) = current;
        }

        current = next;
    }

    First(*jadwal) = sorted;
}

List* get_all_event(const Studio* studio) 
{
    if (!studio || !studio->jadwal_studio) return NULL;

    List* event_list = (List*)malloc(sizeof(List));
    if (!event_list) return NULL;
    CreateList(event_list);
    pnode current;
    for (current = studio->jadwal_studio->First; current != NULL; current = Next(current)) 
    {
        if (Type(current) == TYPE_EVENT) 
        {
            insert_value_last(&(event_list->First), Info(current), TYPE_EVENT);
        }
    }

    return event_list;
}

List* get_all_jadwal(const Studio* studio) 
{
    if (!studio || !studio->jadwal_studio) return NULL;

    List* jadwal_list = (List*)malloc(sizeof(List));
    if (!jadwal_list) return NULL;
    CreateList(jadwal_list);
    pnode current;
    for (current = studio->jadwal_studio->First; current != NULL; current = Next(current)) 
    {
        if (Type(current) == TYPE_JADWAL) 
        {
            insert_value_last(&(jadwal_list->First), Info(current), TYPE_JADWAL);
        }
    }

    return jadwal_list;
}

List* get_jadwal_dan_event_by_film(Studio* studio, const char* keyword) 
{
    if (!studio || !keyword || !studio->jadwal_studio) return NULL;

    List* hasil = create_list();
    pnode current;
    for (current = studio->jadwal_studio->First; current; current = Next(current)) 
    {
        if (Type(current) == TYPE_JADWAL)
        {
            if (strcasestr_custom(get_film_name(info_jadwal(current)), keyword)) 
            {
                insert_value_last(&(hasil->First), Info(current), Type(current));
            }
        }

        if (Type(current) == TYPE_EVENT)
        {
            if (strcasestr_custom(get_event_film_title(info_event(current)), keyword)) 
            {
                insert_value_last(&(hasil->First), Info(current), Type(current));
            }
        }

    }
    return hasil;
}

