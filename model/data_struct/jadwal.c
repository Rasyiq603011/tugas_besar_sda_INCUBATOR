#include "jadwal.h"

struct DataJadwal{
    Time waktu_tayang;
    date tanggal_tayang;
    Film* film;
    int harga_tiket;
    int jumlah_tiket;
    Kursi** daftar_kursi;
};

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

Jadwal* constructor_jadwal(Time waktu, date tanggal,int harga_tiket, Film* film, int jumlah_kursi)
{
    if (jumlah_kursi <= 0) {return NULL;}
    int current_kursi, tipe;
    Jadwal* new_jadwal = (Jadwal*) malloc (sizeof(Jadwal));
    if (!new_jadwal) {return NULL;}
    new_jadwal->waktu_tayang = waktu;
    new_jadwal->tanggal_tayang = tanggal;
    new_jadwal->film = film;
    new_jadwal->harga_tiket = harga_tiket >= 0 ? harga_tiket : 0;
    new_jadwal->jumlah_tiket = jumlah_kursi;
    new_jadwal->daftar_kursi = (Kursi**)calloc(jumlah_kursi,sizeof(Kursi*));
    for (current_kursi = 0; current_kursi < jumlah_kursi; current_kursi++) 
    {
        if (current_kursi <= (jumlah_kursi / 3))
        {
            tipe = 2;
        }
         else if (current_kursi <= (jumlah_kursi*2 / 3))
        {
            tipe = 1;
        }
         else
        {
            tipe = 0;
        }
        new_jadwal->daftar_kursi[current_kursi] = constructor_kursi(current_kursi + 1, true, tipe);
    }
    return new_jadwal;
}

void create_jadwal(Jadwal** new_jadwal, Time waktu, date tanggal,int harga_tiket, Film* film, int jumlah_kursi)
{
    *new_jadwal = constructor_jadwal(waktu, tanggal, harga_tiket, film, jumlah_kursi);
}

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

Time get_waktu_tayang(Jadwal* current_jadwal)
{
    return current_jadwal ? current_jadwal->waktu_tayang : (Time){0,0,0};
}

date get_tanggal_tayang(Jadwal* current_jadwal)
{
    return current_jadwal ? current_jadwal->tanggal_tayang : getTodayDate();
}

Film* get_film(Jadwal* current_jadwal)
{
    return current_jadwal ? current_jadwal->film : NULL;
}

String get_film_name(Jadwal* current_jadwal)
{
    if (!current_jadwal || !current_jadwal->film) {return "film tidak diketahui";}
    return get_judul_film(current_jadwal->film);
}

int get_harga_tiket(Jadwal* current_jadwal)
{
    return current_jadwal ? current_jadwal->harga_tiket : 0;
}

int get_jumlah_tiket(Jadwal* current_jadwal)
{
    return current_jadwal ? current_jadwal->jumlah_tiket : 0;
}

Kursi** get_daftar_kursi(Jadwal* current_jadwal)
{
    return current_jadwal->daftar_kursi;
}

Kursi* get_kursi_value_by_index(Jadwal* current_jadwal, int index)
{
    return current_jadwal->daftar_kursi[index];
}

// ===============================================
// =============== MUTATOR SECTION ===============
// ===============================================

void set_waktu_tayang(Jadwal* current_jadwal, Time new_time)
{
    if (current_jadwal) 
    {
        current_jadwal->waktu_tayang = new_time;
    }
}

void set_tanggal_tayang(Jadwal* current_jadwal, date new_date)
{
    current_jadwal->tanggal_tayang = new_date;
}

void set_film(Jadwal* current_jadwal, Film* new_film)
{
    current_jadwal->film = new_film;
}

void set_daftar_kursi(Jadwal* current_jadwal, Kursi** new_kursi_list, int jumlah_kursi)
{
    int current_kursi;
    for(current_kursi = 0; current_kursi < jumlah_kursi; current_kursi++)
    {
        current_jadwal->daftar_kursi[current_kursi] = new_kursi_list[current_kursi];
    }
}

void set_kursi_by_index(Jadwal* current_jadwal, int index, Kursi* new_value)
{
    current_jadwal->daftar_kursi[index] = new_value;
}

// ===============================================
// ============ DESTRUCTOR SECTION ===============
// ===============================================

void destructor_jadwal(Jadwal* current_jadwal)
{
    if (!current_jadwal) {return;}
    int current_kursi;
    for (current_kursi = 0; current_kursi < current_jadwal->jumlah_tiket; current_kursi++) {
        if (current_jadwal->daftar_kursi[current_kursi]) {
            destructor_kursi(current_jadwal->daftar_kursi[current_kursi]);
            current_jadwal->daftar_kursi[current_kursi] = NULL;
        }
    }
    free(current_jadwal->daftar_kursi);
    free(current_jadwal);
}

// ===============================================
// ============ ADDITIONAL SECTION ===============
// ===============================================

int compare_time(const Time* t1, const Time* t2) {
    return t1 && t2 && (t1->jam == t2->jam) && (t1->menit == t2->menit) && (t1->detik == t2->detik);
}

int compare_date(const date* d1, const date* d2) {
    return d1 && d2 && (d1->Tgl == d2->Tgl) && (d1->Bln == d2->Bln) && (d1->Thn == d2->Thn);
}

int compare_daftar_kursi(Kursi** kursi_pertama, Kursi** kursi_kedua, int jumlah) {
    if (!kursi_pertama || !kursi_kedua) return 0;
    int current_kursi;
    for (current_kursi = 0; current_kursi < jumlah; current_kursi++) {
        if (!compare_kursi_value(kursi_pertama[current_kursi], kursi_kedua[current_kursi])) return 0;
    }
    return 1;
}

int compare_jadwal_value(const Jadwal* jadwal_pertama, const Jadwal* jadwal_kedua) 
{
    if (!jadwal_pertama || !jadwal_kedua) return 0;

    return 
    (
        compare_time(&jadwal_pertama->waktu_tayang, &jadwal_kedua->waktu_tayang) &&
        compare_date(&jadwal_pertama->tanggal_tayang, &jadwal_kedua->tanggal_tayang) &&
        (jadwal_pertama->harga_tiket == jadwal_kedua->harga_tiket) &&
        (jadwal_pertama->jumlah_tiket == jadwal_kedua->jumlah_tiket) &&
        compare_daftar_kursi(jadwal_pertama->daftar_kursi, jadwal_kedua->daftar_kursi, jadwal_pertama->jumlah_tiket)
    );
}

