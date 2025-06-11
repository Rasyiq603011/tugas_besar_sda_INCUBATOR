#ifndef STUDIO_H
#define STUDIO_H

// ================================================
// ===================== KOTA =====================
// ================================================
typedef char* String;

// Forward declaration untuk Jadwal
typedef struct DataJadwal Jadwal;

typedef struct DataStudio Studio;

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Studio* constructor(String nama, int total_pendapatan);

void create_studio(Studio** new_studio, String nama, int total_pendapatan);

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

String get_name(Studio current_studio);

int get_pendapatan(Studio current_studio);

Jadwal* get_jadwal(Studio current_studio);

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_name(Studio* current_studio, String name);

void set_pendapatan(Studio* current_studio, int pendapatan);

void set_jadwal(Studio* current_studio, Jadwal* jadwal);

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Studio* current_studio);

#endif /*STUDIO_H*/