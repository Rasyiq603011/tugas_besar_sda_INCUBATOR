#include "../data_struct.h"
#include "../date.h"
#include "../time.h"

struct data_jadwal{
    Time* waktu;
    date tanggal;
    String nama_studio;
    Kursi* daftar_kursi;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Jadwal* constructor_jadwal()
{
    Jadwal* new_jadwal;

    return new_jadwal;
}

void create_jadwal(Jadwal* new_jadwal)
{
    new_jadwal = constructor();
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

Time* get_time(Jadwal current_jadwal)
{
    return current_jadwal.waktu;
}

date get_date(Jadwal current_jadwal)
{
    return current_jadwal.tanggal;
}

String get_studio_name(Jadwal current_jadwal)
{
    return current_jadwal.nama_studio;
}

Kursi** get_daftar_kursi(Jadwal current_jadwal)
{
    return current_jadwal.daftar_kursi;
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_waktu(Jadwal* current_jadwal, Time* new_time)
{

}

void set_tanggal(Jadwal* current_jadwal, date new_date)
{

}

void set_nama_studio(Jadwal* current_jadwal, String new_studio_name)
{

}

void set_daftar_kursi(Jadwal* current_jadwal, Kursi** new_kursi_list)
{

}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================





