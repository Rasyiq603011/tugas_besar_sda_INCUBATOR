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
    Queue antrian_proses;
    User** daftar_user;
};

// ================================================
// ============ UTILITAS INTERNAL =================
// ================================================
static char* strdup_safe(const char* src) {
    if (!src) return NULL;
    char* copy = malloc(strlen(src) + 1);
    if (!copy) return NULL;
    strcpy(copy, src);
    return copy;
}

// ================================================
// ========= CONSTRUCTOR / DESTRUCTOR =============
// ================================================
Event* constructor_event(String nama_event ,date start, date end, const char* film_title, int kuota, int sesi) 
{
    if (!nama_event || !film_title || kuota <= 0 || sesi <= 0 || kuota > 1000 || sesi > 100)
        return NULL;

    Event* new_event = (Event*)calloc(1, sizeof(Event));
    if (!new_event) return NULL;

    new_event->nama_event = strdup_safe(nama_event);
    if (!new_event->nama_event) {
        free(new_event);
        return NULL;
    }

    new_event->waktu_start = start;
    new_event->waktu_end = end;
    new_event->is_linked = false;
    strncpy(new_event->FilmTitle, film_title, sizeof(new_event->FilmTitle) - 1);
    new_event->FilmTitle[sizeof(new_event->FilmTitle) - 1] = '\0';

    new_event->jumlah_kuota_sesi = kuota;
    new_event->jumlah_sesi = sesi;

    int total = kuota * sesi;
    new_event->daftar_user = (User**)calloc(total, sizeof(User*));
    if (!new_event->daftar_user) {
        free(new_event->nama_event);
        free(new_event);
        return NULL;
    }

    createPriorityQueue(&new_event->antrian_proses);
    return new_event;
}

void create_event(Event** new_event, String nama_event, date start, date end, const char* film_title, int kuota, int sesi)
{
    *new_event = constructor_event(nama_event, start, end, film_title, kuota, sesi);
}

void destructor_event(Event* current_event) 
{
    if (!current_event) return;

    free(current_event->nama_event);
    free(current_event->daftar_user);
    destructor_queue(&current_event->antrian_proses);
    free(current_event);
}

// ================================================
// =================== GETTER =====================
// ================================================
const String get_name_event(const Event* current_event)
{
    return (current_event) ? current_event->nama_event : NULL;
}

date get_event_start(const Event* current_event)
{
    return current_event ? current_event->waktu_start : getTodayDate();
}

date get_event_end(const Event* current_event)
{
    return current_event ? current_event->waktu_end : getTodayDate();
}

int get_event_jumlah_kuota(const Event* current_event)
{
    return current_event ? current_event->jumlah_kuota_sesi : 0;
}

int get_event_jumlah_sesi(const Event* current_event)
{
    return current_event ? current_event->jumlah_sesi : 0;
}

bool event_is_linked(const Event* current_event)
{
    return current_event ? current_event->is_linked : false;
}

Film* get_event_film(Event* current_event)
{
    if (!current_event || !current_event->is_linked) return NULL;
    return current_event->film;
}

const char* get_event_film_title(const Event* current_event)
{
    if (!current_event) return "event tidak diketahui";
    return (current_event->is_linked && current_event->film)
        ? get_judul_film(current_event->film)
        : current_event->FilmTitle;
}

User** get_event_daftar_user(Event* current_event)
{
    return (current_event) ? current_event->daftar_user : NULL;
}

User* get_event_user_by_index(Event* current_event, int index)
{
    if (!current_event || !current_event->daftar_user) return NULL;
    int total = current_event->jumlah_kuota_sesi * current_event->jumlah_sesi;
    return (index >= 0 && index < total) ? current_event->daftar_user[index] : NULL;
}

Queue* get_event_queue(Event* current_event)
{
    return current_event ? &current_event->antrian_proses : NULL;
}

int get_total_kuota(Event* current_event)
{
    return current_event ? (current_event->jumlah_sesi * current_event->jumlah_kuota_sesi) : 0;
}


// ================================================
// =================== SETTER =====================
// ================================================
void set_name_event(Event* current_event, const String name)
{
    if (!current_event || !name) return;
    String new_name = strdup_safe(name);
    if (new_name) {
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
    if (current_event && kuota > 0) current_event->jumlah_kuota_sesi = kuota;
}

void set_event_jumlah_sesi(Event* current_event, int sesi)
{
    if (current_event && sesi > 0) current_event->jumlah_sesi = sesi;
}

void set_event_film_object(Event* current_event, Film* film)
{
    if (current_event && film) {
        current_event->film = film;
        current_event->is_linked = true;
    }
}

void set_event_film_title(Event* current_event, const char* title)
{
    if (current_event && title) {
        strncpy(current_event->FilmTitle, title, sizeof(current_event->FilmTitle) - 1);
        current_event->FilmTitle[sizeof(current_event->FilmTitle) - 1] = '\0';
        current_event->is_linked = false;
    }
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
    int batas = current_event->jumlah_kuota_sesi * current_event->jumlah_sesi;

    for (int i = 0; i < jumlah_user && i < batas; i++) {
        current_event->daftar_user[i] = daftar_user[i];
    }
}

void set_daftar_user_by_index(Event* current_event, int index, User* new_value)
{
    if (!current_event || !current_event->daftar_user) return;
    int batas = current_event->jumlah_kuota_sesi * current_event->jumlah_sesi;
    if (index >= 0 && index < batas)
        current_event->daftar_user[index] = new_value;
}

void set_event_queue(Event* current_event, Queue* new_queue)
{
    if (!current_event || !new_queue) return;

    clearPriorityQueue(&(current_event->antrian_proses), destroy_user);

    createPriorityQueue(&current_event->antrian_proses);

    Queue temp = *new_queue;
    Pqueue node = temp.front;

    while (node != NULL) {
        enqueue_user(&current_event->antrian_proses, node->data);
        node = node->next;
    }
}


// ================================================
// =============== FUNGSI TAMBAHAN ================
// ================================================
Event* deep_copy_event(const Event* src)
{
    if (!src) return NULL;

    Event* copy = constructor_event(src->nama_event, src->waktu_start, src->waktu_end, src->FilmTitle,
                                    src->jumlah_kuota_sesi, src->jumlah_sesi);
    if (!copy) return NULL;

    copy->is_linked = src->is_linked;
    copy->film = src->is_linked ? src->film : NULL;

    int total = src->jumlah_kuota_sesi * src->jumlah_sesi;
    for (int i = 0; i < total; i++) {
        copy->daftar_user[i] = src->daftar_user[i];
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
        return strcmp(get_judul_film(ev1->film), get_judul_film(ev2->film)) == 0;
    else
        return strcmp(ev1->FilmTitle, ev2->FilmTitle) == 0;
}
