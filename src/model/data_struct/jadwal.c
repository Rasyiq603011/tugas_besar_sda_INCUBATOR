#include "jadwal.h"

#include <stdbool.h>

struct DataJadwal {
    Time waktu_start;
    Time waktu_end;
    date tanggal_tayang;
    union {
        Film* film;
        char FilmTitle[128];
    };
    bool is_linked;
    int harga_tiket;
    int jumlah_tiket;
    Kursi** daftar_kursi;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Jadwal* constructor_jadwal(Time waktu_start, Time Waktu_end, date tanggal, int harga_tiket, String film, int jumlah_kursi)
{
    if (jumlah_kursi <= 0) return NULL;

    Jadwal* new_jadwal = (Jadwal*) malloc(sizeof(Jadwal));
    if (!new_jadwal) return NULL;

    new_jadwal->waktu_start = waktu_start;
    new_jadwal->waktu_end = Waktu_end;
    new_jadwal->tanggal_tayang = tanggal;

    strncpy(new_jadwal->FilmTitle, film, sizeof(new_jadwal->FilmTitle) - 1);
    new_jadwal->FilmTitle[sizeof(new_jadwal->FilmTitle) - 1] = '\0';
    new_jadwal->is_linked = false;

    new_jadwal->harga_tiket = harga_tiket >= 0 ? harga_tiket : 0;
    new_jadwal->jumlah_tiket = jumlah_kursi;

    new_jadwal->daftar_kursi = (Kursi**)calloc(jumlah_kursi, sizeof(Kursi*));
    if (!new_jadwal->daftar_kursi) 
    {
        free(new_jadwal);
        return NULL;
    }

    for (int i = 0; i < jumlah_kursi; i++) {
        int tipe = (i <= jumlah_kursi / 3) ? 2 : (i <= jumlah_kursi * 2 / 3 ? 1 : 0);
        new_jadwal->daftar_kursi[i] = constructor_kursi(i + 1, true, tipe);
    }

    return new_jadwal;
}


void create_jadwal(Jadwal** new_jadwal, Time waktu_start, Time waktu_end, date tanggal,int harga_tiket, String film, int jumlah_kursi)
{
    *new_jadwal = constructor_jadwal(waktu_start, waktu_end, tanggal, harga_tiket, film, jumlah_kursi);
}

boolean is_jadwal_linked(Jadwal* current_jadwal)
{
    return current_jadwal ? current_jadwal->is_linked : false;
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

Time get_waktu_start(Jadwal* current_jadwal)
{
    return current_jadwal ? current_jadwal->waktu_start: (Time){0,0,0};
}

Time get_waktu_end(Jadwal* current_jadwal)
{
    return current_jadwal ? current_jadwal->waktu_end: (Time){0,0,0};
}

date get_tanggal_tayang(Jadwal* current_jadwal)
{
    return current_jadwal ? current_jadwal->tanggal_tayang : getTodayDate();
}

Film* get_film(Jadwal* jadwal)
{
    if (!jadwal || !jadwal->is_linked) return NULL;
    return jadwal->film;
}

String get_film_name(Jadwal* jadwal)
{
    if (!jadwal) return "film tidak diketahui";

    if (jadwal->is_linked && jadwal->film) {
        return get_judul_film(jadwal->film);
    } else {
        return jadwal->FilmTitle;
    }
}

int get_harga_tiket(Jadwal* current_jadwal)
{
    return current_jadwal ? current_jadwal->harga_tiket : 0;
}

int get_jumlah_tiket(Jadwal* current_jadwal)
{
    return current_jadwal ? current_jadwal->jumlah_tiket : 0;
}

Kursi** get_daftar_kursi(Jadwal* current_jadwal)
{
    return current_jadwal->daftar_kursi;
}

Kursi* get_kursi_value_by_index(Jadwal* current_jadwal, int index)
{
    if (!current_jadwal || !current_jadwal->daftar_kursi || index < 0 || index >= current_jadwal->jumlah_tiket)
        return NULL;
    return current_jadwal->daftar_kursi[index];
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_waktu_start(Jadwal* current_jadwal, Time new_time)
{
    if (current_jadwal) 
    {
        current_jadwal->waktu_start = new_time;
    }
}

void set_waktu_end(Jadwal* current_jadwal, Time new_time)
{
    if (current_jadwal) 
    {
        current_jadwal->waktu_end = new_time;
    }
}

void set_tanggal_tayang(Jadwal* current_jadwal, date new_date)
{
    current_jadwal->tanggal_tayang = new_date;
}

void set_film_object(Jadwal* jadwal, Film* film_obj)
{
    if (!jadwal || !film_obj) return;
    jadwal->film = film_obj;
    jadwal->is_linked = true;
}

void set_film_title(Jadwal* jadwal, const char* title)
{
    if (!jadwal || !title) return;
    strncpy(jadwal->FilmTitle, title, sizeof(jadwal->FilmTitle) - 1);
    jadwal->FilmTitle[sizeof(jadwal->FilmTitle) - 1] = '\0';
    jadwal->is_linked = false;
}


void set_daftar_kursi(Jadwal* current_jadwal, Kursi** new_kursi_list, int jumlah_kursi)
{
    int current_kursi;
    for(current_kursi = 0; current_kursi < jumlah_kursi; current_kursi++)
    {
        current_jadwal->daftar_kursi[current_kursi] = new_kursi_list[current_kursi];
    }
}

void set_kursi_by_index(Jadwal* current_jadwal, int index, Kursi* new_value)
{
    if (!current_jadwal || !current_jadwal->daftar_kursi || index < 0 || index >= current_jadwal->jumlah_tiket)
        return;
    current_jadwal->daftar_kursi[index] = new_value;
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_jadwal(Jadwal* current_jadwal)
{
    if (!current_jadwal) {return;}
    int current_kursi;
    for (current_kursi = 0; current_kursi < current_jadwal->jumlah_tiket; current_kursi++) {
        if (current_jadwal->daftar_kursi[current_kursi]) {
            destructor_kursi(current_jadwal->daftar_kursi[current_kursi]);
            current_jadwal->daftar_kursi[current_kursi] = NULL;
        }
    }
    free(current_jadwal->daftar_kursi);
    free(current_jadwal);
}

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

int compare_daftar_kursi(Kursi** kursi_pertama, Kursi** kursi_kedua, int jumlah) {
    if (!kursi_pertama || !kursi_kedua) return 0;
    int current_kursi;
    for (current_kursi = 0; current_kursi < jumlah; current_kursi++) {
        if (!compare_kursi_value(kursi_pertama[current_kursi], kursi_kedua[current_kursi])) return 0;
    }
    return 1;
}

int compare_jadwal_value(const Jadwal* jadwal_pertama, const Jadwal* jadwal_kedua) 
{
    if (!jadwal_pertama || !jadwal_kedua) return 0;

    return 
    (
        CompareTime(jadwal_pertama->waktu_start, jadwal_kedua ->waktu_start) &&
        CompareTime(jadwal_pertama->waktu_end, jadwal_kedua->waktu_end) &&
        compare_date(jadwal_pertama->tanggal_tayang, jadwal_kedua->tanggal_tayang) &&
        (jadwal_pertama->harga_tiket == jadwal_kedua->harga_tiket) &&
        (jadwal_pertama->jumlah_tiket == jadwal_kedua->jumlah_tiket) &&
        compare_daftar_kursi(jadwal_pertama->daftar_kursi, jadwal_kedua->daftar_kursi, jadwal_pertama->jumlah_tiket)
    );
}

void reset_film(Jadwal* jadwal)
{
    if (!jadwal) return;
    jadwal->film = NULL;
    jadwal->FilmTitle[0] = '\0';
    jadwal->is_linked = false;
}

Jadwal* deep_copy_jadwal(const Jadwal* source) 
{
    if (!source) return NULL;

    Jadwal* copy = (Jadwal*)malloc(sizeof(Jadwal));
    if (!copy) return NULL;

    copy->waktu_start = source->waktu_start;
    copy->waktu_end = source->waktu_end;
    copy->tanggal_tayang = source->tanggal_tayang;

    copy->is_linked = source->is_linked;
    if (source->is_linked && source->film != NULL) {
        copy->film = source->film; 
    } else {
        strncpy(copy->FilmTitle, source->FilmTitle, sizeof(copy->FilmTitle) - 1);
        copy->FilmTitle[sizeof(copy->FilmTitle) - 1] = '\0';
        copy->film = NULL;
    }

    copy->harga_tiket = source->harga_tiket;
    copy->jumlah_tiket = source->jumlah_tiket;

    copy->daftar_kursi = (Kursi**)calloc(copy->jumlah_tiket, sizeof(Kursi*));
    if (!copy->daftar_kursi) {
        free(copy);
        return NULL;
    }

    for (int i = 0; i < copy->jumlah_tiket; i++) {
        Kursi* kursi_asal = source->daftar_kursi[i];
        if (kursi_asal) {
            copy->daftar_kursi[i] = constructor_kursi(
                get_id_kursi(kursi_asal),
                get_status_kursi(kursi_asal),
                get_tipe_kursi(kursi_asal)
            );

            if (!copy->daftar_kursi[i]) {
                for (int j = 0; j < i; j++) {
                    destructor_kursi(copy->daftar_kursi[j]);
                }
                free(copy->daftar_kursi);
                free(copy);
                return NULL;
            }
        } else {
            copy->daftar_kursi[i] = NULL;
        }
    }

    return copy;
}


