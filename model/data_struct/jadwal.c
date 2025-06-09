#include "jadwal.h"
#include "kursi.h"
#include "film.h"
#include "../date.h"
#include "../time_adt.h"

struct DataJadwal{
    Time waktu;
    date tanggal;
    Film* film;
    int harga_tiket;
    Kursi* daftar_kursi[MAX_ROW][MAX_COL];
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
    new_jadwal = constructor_jadwal();
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

Time get_time(Jadwal* current_jadwal)
{
    return current_jadwal->waktu;
}

date get_date(Jadwal* current_jadwal)
{
    return current_jadwal->tanggal;
}

Film* get_film(Jadwal* current_jadwal)
{
    return current_jadwal->film;
}

String get_film_name(Jadwal* current_jadwal)
{
    return get_name(current_jadwal->film);
}

int get_harga_tiket(Jadwal* current_jadwal)
{
    return current_jadwal->harga_tiket;
}

Kursi** get_daftar_kursi(Jadwal* current_jadwal)
{
    return current_jadwal->daftar_kursi;
}

Kursi* get_kursi_value_by_index(Jadwal* current_jadwal, int row, int col)
{
    return current_jadwal->daftar_kursi[row][col];
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_waktu(Jadwal* current_jadwal, Time new_time)
{
    current_jadwal->waktu = new_time;
}

void set_tanggal(Jadwal* current_jadwal, date new_date)
{
    current_jadwal->tanggal = new_date;
}

void set_film(Jadwal* current_jadwal, Film* new_film)
{
    current_jadwal->film = new_film;
}

void set_daftar_kursi(Jadwal* current_jadwal, Kursi* new_kursi_list[MAX_ROW][MAX_COL])
{
    int row, col;
    for(row = 0; row < MAX_ROW; row++)
    {
        for(col = 0; col < MAX_COL; col++)
        {
            current_jadwal->daftar_kursi[row][col] = new_kursi_list[row][col];
        }
    }
}

void set_kursi_by_index(Jadwal* current_jadwal, int row, int col, Kursi* new_value)
{
    current_jadwal->daftar_kursi[row][col] = new_value;
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor(Jadwal* current_jadwal)
{
    current_jadwal->film = NULL;
}



