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


// ================================================
// ======= CONSTRUCTOR/DESTRUCTOR SECTION =========
// ================================================

Event* constructor_event(String nama_event ,date start, date end, const char* film_title, int kuota, int sesi);

void create_jadwal(Event** new_event, String nama_event, date start, date end, const char* film_title, int kuota, int sesi);

void destructor_event(Event* current_event);

// ===============================================
// =============== GETTER SECTION ================
// ===============================================

date get_event_start(Event* current_event);

date get_event_end(Event* current_event);

int get_event_jumlah_kuota(Event* current_event);

int get_event_jumlah_sesi(Event* current_event);

bool event_is_linked(Event* current_event);

Film* get_event_film(Event* current_event);

const char* get_event_film_title(Event* current_event);

// ===============================================
// =============== SETTER SECTION ================
// ===============================================

void set_event_start(Event* current_event, date new_start);

void set_event_end(Event* current_event, date new_end);

void set_event_jumlah_kuota(Event* current_event, int kuota);

void set_event_jumlah_sesi(Event* current_event, int sesi);

void set_event_film_object(Event* current_event, Film* film);

void set_event_film_title(Event* current_event, const char* title);

void reset_event_film(Event* current_event);

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

Event* deep_copy_event(const Event* src);

bool compare_event_value(const Event* ev1, const Event* ev2);

#endif /*EVENT_H*/
