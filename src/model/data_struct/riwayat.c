#include "riwayat.h"

// ===============================================
// ========= STRUCT DEFINITIONS ==================
// ===============================================

// Struktur data untuk menyimpan riwayat pembelian tiket
struct DataRiwayat {
    String judul_film;
    String tanggal;
    String jam;
    int harga_tiket;
    String kursi;
    Riwayat* next;
};

// ===============================================
// ============== ACCESSOR SECTION ===============
// ===============================================

// Mengembalikan judul film dari riwayat
String get_judul_film_riwayat(Riwayat* riwayat)
{
    return riwayat->judul_film;
}

// Mengembalikan tanggal dari riwayat
String get_tanggal_riwayat(Riwayat* riwayat)
{
    return riwayat->tanggal;
}

// Mengembalikan jam dari riwayat
String get_jam_riwayat(Riwayat* riwayat)
{
    return riwayat->jam;
}

// Mengembalikan harga tiket dari riwayat
int get_harga_tiket_riwayat(Riwayat* riwayat)
{
    return riwayat->harga_tiket;
}

// Mengembalikan kursi dari riwayat
String get_kursi_riwayat(Riwayat* riwayat)
{
    return riwayat->kursi;
}

Riwayat* get_next_riwayat(Riwayat* riwayat)
{
    if (riwayat != NULL){
        return riwayat->next;
    }
}

// ===============================================
// ============== MUTATOR SECTION ================
// ===============================================

// Mengatur judul film dalam riwayat
void set_judul_film_riwayat(Riwayat* riwayat, String judul_film)
{
    free(riwayat->judul_film);
    riwayat->judul_film = strdup(judul_film);
}

// Mengatur tanggal dalam riwayat
void set_tanggal_riwayat(Riwayat* riwayat, String tanggal)
{
    riwayat->tanggal = strdup(tanggal);
}

// Mengatur jam dalam riwayat
void set_jam_riwayat(Riwayat* riwayat, String jam)
{
    riwayat->jam = strdup(jam);
}

// Mengatur harga tiket dalam riwayat
void set_harga_tiket_riwayat(Riwayat* riwayat, int harga_tiket)
{
    riwayat->harga_tiket = harga_tiket;
}

// Mengatur kursi dalam riwayat
void set_kursi_riwayat(Riwayat* riwayat, String kursi)
{
    riwayat->kursi = strdup(kursi);
}

void set_next_riwayat(Riwayat* riwayat, Riwayat* new_riwayat)
{
    riwayat->next = new_riwayat;
}

// ===============================================
// ============ CONSTRUCTOR SECTION ==============
// ===============================================

// Membuat objek riwayat baru dengan nilai default (next = NULL)
Riwayat* create_riwayat(String judul_film, char tanggal[10], char jam[6], int harga_tiket, String kursi)
{
    Riwayat* new_node = (Riwayat*) malloc(sizeof(Riwayat));
    new_node->judul_film = strdup(judul_film);
    strcpy(new_node->tanggal, tanggal);
    strcpy(new_node->jam, jam);
    new_node->harga_tiket = harga_tiket;
    new_node->kursi = strdup(kursi);
    return new_node; 
}

// ===============================================
// ============= DESTRUCTOR SECTION ==============
// ===============================================

// Menghapus objek riwayat dan membebaskan memori yang digunakan
void destroy_riwayat(Riwayat* riwayat)
{
    if (riwayat != NULL)
    {
        free(riwayat->tanggal);
        free(riwayat->jam);
        free(riwayat->judul_film); // membebaskan memori string judul film
        free(riwayat->kursi);      // membebaskan memori string kursi
        free(riwayat);             // membebaskan memori objek riwayat
    }
}

// ===============================================
// ================== CONVERTER ==================
// ===============================================

int convert_riwayat_to_array(Riwayat* head, void*** out_array) 
{
    if (head == NULL) 
    {
        *out_array = NULL;
        return 0;
    }

    // Hitung jumlah elemen
    int count = 0;
    Riwayat* curr = head;
    while (curr != NULL) 
    {
        count++;
        curr = get_next_riwayat(curr);
    }

    // Alokasi array pointer
    void** array = (void**)malloc(sizeof(void*) * count);
    curr = head;
    for (int i = 0; i < count && curr != NULL; i++) 
    {
        array[i] = (void*)curr; // casting Riwayat* ke void*
        curr = get_next_riwayat(curr);
    }

    *out_array = array;
    return count;
}
