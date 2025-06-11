#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studio.h"

struct DataStudio {
    String nama;
    int total_pendapatan;
    List* jadwal;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Studio* constructor(String nama, int total_pendapatan)
{
    Studio* new_studio = (Studio*) malloc(sizeof(Studio));
    new_studio->nama = strdup(nama);
    new_studio->total_pendapatan = total_pendapatan;
    new_studio->jadwal = NULL;
    return new_studio;
}

void create_studio(Studio** new_studio, String nama, int total_pendapatan)
{
    *new_studio = constructor(nama, total_pendapatan);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name(Studio* current_studio)
{
    return current_studio->nama;
}

int get_pendapatan(Studio* current_studio)
{
    return current_studio->total_pendapatan;
}

List* get_jadwal(Studio* current_studio)
{
    return current_studio->jadwal;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name(Studio* current_studio, String name)
{
    current_studio->nama = name;
}

void set_pendapatan(Studio* current_studio, int pendapatan)
{
    current_studio->total_pendapatan = pendapatan;
}

void set_jadwal(Studio* current_studio, List* jadwal)
{
    current_studio->jadwal = jadwal;
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Studio* current_studio)
{
    free(current_studio->nama);
    // Note: jadwal tidak di-free di sini karena mungkin digunakan oleh entitas lain
    free(current_studio);
}