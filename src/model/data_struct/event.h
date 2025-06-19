#ifndef EVENT_H
#define EVENT_H
#include "film.h"
#include "../time_adt.h"
#include "../date.h"
#include "../queue.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataEvent Event;

#include "event.h"

// ================================================
// ============ UTILITAS INTERNAL =================
// ================================================
static char* strdup_safe(const char* src);

// ================================================
// ========= CONSTRUCTOR / DESTRUCTOR =============
// ================================================
Event* constructor_event(String nama_event ,date start, date end, const char* film_title, int kuota, int sesi);

void create_event(Event** new_event, String nama_event, date start, date end, const char* film_title, int kuota, int sesi);

void destructor_event(Event* current_event);

// ================================================
// =================== GETTER =====================
// ================================================
const String get_name_event(const Event* current_event);

date get_event_start(const Event* current_event);

date get_event_end(const Event* current_event);

int get_event_jumlah_kuota(const Event* current_event);

int get_event_jumlah_sesi(const Event* current_event);

bool event_is_linked(const Event* current_event);

Film* get_event_film(Event* current_event);

const char* get_event_film_title(const Event* current_event);

User** get_event_daftar_user(Event* current_event);

User* get_event_user_by_index(Event* current_event, int index);

Queue* get_event_queue(Event* current_event);

int get_total_kuota(Event* current_event);


// ================================================
// =================== SETTER =====================
// ================================================
void set_name_event(Event* current_event, const String name);

void set_event_start(Event* current_event, date new_start);

void set_event_end(Event* current_event, date new_end);

void set_event_jumlah_kuota(Event* current_event, int kuota);

void set_event_jumlah_sesi(Event* current_event, int sesi);

void set_event_film_object(Event* current_event, Film* film);

void set_event_film_title(Event* current_event, const char* title);

void reset_event_film(Event* current_event);

void set_event_daftar_user(Event* current_event, User** daftar_user, int jumlah_user);

void set_daftar_user_by_index(Event* current_event, int index, User* new_value);

void set_event_queue(Event* current_event, Queue* new_queue);

// ================================================
// =============== FUNGSI TAMBAHAN ================
// ================================================
Event* deep_copy_event(const Event* src);

bool compare_event_value(const Event* ev1, const Event* ev2);

#endif /*EVENT_H*/
