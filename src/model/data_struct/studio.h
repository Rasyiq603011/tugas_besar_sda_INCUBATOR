#ifndef STUDIO_H
#define STUDIO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../linked.h" 

typedef char* String;

typedef struct DataStudio Studio;

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Studio* constructor_studio(const String nama, int total_pendapatan, int jumlah_kursi);

void create_studio(Studio** new_studio, String nama, int total_pendapatan, int jumlah_kursi);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name_studio(const Studio* current_studio);

int get_pendapatan_studio(const Studio* current_studio);

List* get_jadwal_studio(const Studio* current_studio);

int get_jumlah_kursi_studio(const Studio* current_studio);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name_studio(Studio* current_studio, String name);

void set_pendapatan_studio(Studio* current_studio, int pendapatan);

void set_jadwal_studio(Studio* current_studio, List* jadwal);

void set_jumlah_kursi_studio(Studio* current_studio, int jumlah_kursi);
// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_studio(Studio* current_studio);

// ===============================================
// ============ FILTER DATA SECTION ==============
// ===============================================

List* get_jadwal_by_date(const List jadwal, date tanggal);

List* get_jadwal_by_film(Studio* studio, const char* keyword);

void sort_jadwal_by_start_time(List* jadwal);

List* get_all_event(const Studio* studio);

List* get_all_jadwal(const Studio* studio);

List* get_jadwal_dan_event_by_film(Studio* studio, const char* keyword);

// ===============================================
// ============ COMPARISON SECTION ===============
// ===============================================

int compare_studio_value(const Studio* studio_pertama, const Studio* studio_kedua);

int compare_waktu_mulai_jadwal(pnode a, pnode b);

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

Studio* copy_studio(const Studio* original);

char* strcasestr_custom(const char* haystack, const char* needle);

int is_exists_bentrok_for_jadwal(const List jadwal, date tanggal, Time start, Time end);

int is_exists_bentrok_for_event(const List jadwal, date tanggal_mulai, date tanggal_selesai);

#endif /*STUDIO_H*/