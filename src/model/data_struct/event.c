#include "event.h"

struct DataEvent {
    String nama_event;
    date waktu_start;
    date waktu_end;
    union {
        Film* film;
        char FilmTitle[128];
    };
    bool is_linked;
    int jumlah_kuota_sesi;
    int jumlah_sesi;
    Queue antiran_proses;
    User** daftar_user;
};

static char* strdup_safe(const char* src) {
    if (!src) return NULL;
    char* copy = malloc(strlen(src) + 1);
    if (!copy) return NULL;
    strcpy(copy, src);
    return copy;
}

// ================================================
// ======= CONSTRUCTOR/DESTRUCTOR SECTION =========
// ================================================

Event* constructor_event(String nama_event ,date start, date end, const char* film_title, int kuota, int sesi) 
{
    Event* new_event = (Event*)malloc(sizeof(Event));
    if (!new_event) return NULL;

    new_event->nama_event = strdup_safe(nama_event);
    new_event->waktu_start = start;
    new_event->waktu_end = end;
    new_event->is_linked = false;

    strncpy(new_event->FilmTitle, film_title, sizeof(new_event->FilmTitle) - 1);
    new_event->FilmTitle[sizeof(new_event->FilmTitle) - 1] = '\0';

    new_event->jumlah_kuota_sesi = kuota;
    new_event->jumlah_sesi = sesi;

    new_event->daftar_user = (User**)calloc(kuota*sesi, sizeof(User*));
    if (!new_event->daftar_user) 
    {
        free(new_event);
        return NULL;
    }
    return new_event;
}


void create_jadwal(Event** new_event, String nama_event, date start, date end, const char* film_title, int kuota, int sesi)
{
    *new_event = constructor_event(nama_event ,start, end, film_title, kuota, sesi);
}

void destructor_event(Event* current_event) 
{
    if (!current_event) return;
    free(current_event);
}

// ===============================================
// =============== GETTER SECTION ================
// ===============================================

const String get_name_event(const Event* current_event)
{
    if (!current_event) return NULL;
    return current_event->nama_event;
}

date get_event_start(Event* current_event) 
{
    return current_event ? current_event->waktu_start : getTodayDate();
}

date get_event_end(Event* current_event) 
{
    return current_event ? current_event->waktu_end : getTodayDate();
}

int get_event_jumlah_kuota(Event* current_event) 
{
    return current_event ? current_event->jumlah_kuota_sesi : 0;
}

int get_event_jumlah_sesi(Event* current_event) 
{
    return current_event ? current_event->jumlah_sesi : 0;
}

bool event_is_linked(Event* current_event) 
{
    return current_event ? current_event->is_linked : false;
}

Film* get_event_film(Event* current_event) 
{
    if (!current_event || !current_event->is_linked) return NULL;
    return current_event->film;
}

const char* get_event_film_title(Event* current_event) 
{
    if (!current_event) return "event tidak diketahui";

    if (current_event->is_linked && current_event->film) 
    {
        return get_judul_film(current_event->film);
    }
     else 
    {
        return current_event->FilmTitle;
    }
}

User** get_event_daftar_user(Event* current_event) 
{
    if (!current_event) return NULL;
    return current_event->daftar_user;
}

User* get_event_user_by_index(Event* current_event, int index) 
{
    if (!current_event || !current_event->daftar_user || index < 0 || index >= current_event->jumlah_kuota_sesi * current_event->jumlah_sesi) 
    {
        return NULL;
    }
    return current_event->daftar_user[index];
}

// ===============================================
// =============== SETTER SECTION ================
// ===============================================

void set_name_bioskop(Event* current_event, const String name) 
{
    if (!current_event || !name) return;
    String new_name = strdup_safe(name);
    if (new_name) 
    {
        free(current_event->nama_event);
        current_event->nama_event = new_name;
    }
}

void set_event_start(Event* current_event, date new_start) 
{
    if (current_event) current_event->waktu_start = new_start;
}

void set_event_end(Event* current_event, date new_end) 
{
    if (current_event) current_event->waktu_end = new_end;
}

void set_event_jumlah_kuota(Event* current_event, int kuota) 
{
    if (current_event) current_event->jumlah_kuota_sesi = kuota;
}

void set_event_jumlah_sesi(Event* current_event, int sesi) 
{
    if (current_event) current_event->jumlah_sesi = sesi;
}

void set_event_film_object(Event* current_event, Film* film) 
{
    if (!current_event || !film) return;
    current_event->film = film;
    current_event->is_linked = true;
}

void set_event_film_title(Event* current_event, const char* title) 
{
    if (!current_event || !title) return;
    strncpy(current_event->FilmTitle, title, sizeof(current_event->FilmTitle) - 1);
    current_event->FilmTitle[sizeof(current_event->FilmTitle) - 1] = '\0';
    current_event->is_linked = false;
}

void reset_event_film(Event* current_event) 
{
    if (!current_event) return;
    current_event->film = NULL;
    current_event->FilmTitle[0] = '\0';
    current_event->is_linked = false;
}

void set_event_daftar_user(Event* current_event, User** daftar_user, int jumlah_user) 
{
    if (!current_event || !daftar_user || jumlah_user <= 0) return;

    for (int i = 0; i < jumlah_user && i < current_event->jumlah_kuota_sesi * current_event->jumlah_sesi; i++) 
    {
        current_event->daftar_user[i] = daftar_user[i];
    }
}

void set_daftar_user_by_index(Event* current_event, int index, User* new_value)
{
    if (!current_event || !current_event->daftar_user || index < 0 || index >= (current_event->jumlah_kuota_sesi * current_event->jumlah_sesi))
        return;
    current_event->daftar_user[index] = new_value;
}

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

Event* deep_copy_event(const Event* src) 
{
    if (!src) return NULL;

    Event* copy = (Event*)malloc(sizeof(Event));
    if (!copy) return NULL;

    copy->waktu_start = src->waktu_start;
    copy->waktu_end = src->waktu_end;
    copy->jumlah_kuota_sesi = src->jumlah_kuota_sesi;
    copy->jumlah_sesi = src->jumlah_sesi;
    copy->is_linked = src->is_linked;

    if (src->is_linked && src->film) 
    {
        copy->film = src->film; 
    }
     else 
    {
        strncpy(copy->FilmTitle, src->FilmTitle, sizeof(copy->FilmTitle) - 1);
        copy->FilmTitle[sizeof(copy->FilmTitle) - 1] = '\0';
        copy->film = NULL;
    }

    return copy;
}

bool compare_event_value(const Event* ev1, const Event* ev2) 
{
    if (!ev1 || !ev2) return false;
    
    if (strcmp(ev1->nama_event, ev2->nama_event) != 0) return false;
    if (!compare_date(ev1->waktu_start, ev2->waktu_start)) return false;
    if (!compare_date(ev1->waktu_end, ev2->waktu_end)) return false;

    if (ev1->jumlah_kuota_sesi != ev2->jumlah_kuota_sesi) return false;
    if (ev1->jumlah_sesi != ev2->jumlah_sesi) return false;

    if (ev1->is_linked != ev2->is_linked) return false;

    if (ev1->is_linked && ev2->is_linked) 
    {
        return get_judul_film(ev1->film) == get_judul_film(ev2->film);
    }
     else 
    {
        return strcmp(ev1->FilmTitle, ev2->FilmTitle) == 0;
    }
}
