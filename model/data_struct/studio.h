#ifndef STUDIO_H
#define STUDIO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
// ============ ADDITIONAL SECTION ===============
// ===============================================

int compare_studio_value(const Studio* studio_pertama, const Studio* studio_kedua);

#endif /*STUDIO_H*/