#ifndef HANDLE_MENU_ADMIN_H
#define HANDLE_MENU_ADMIN_H
#include "handle_crud_tree.h"
#include "../model/stack_tree.h"
#include "../view/tampilan_data_struct.h"
#include "handle_menu.h"

/*
 * I.S.  : Tree bioskop sudah dimuat ke memori, root tree tidak NULL.
 * F.S.  : Menampilkan menu navigasi dari negara → provinsi → kota → bioskop → studio,
 *         lalu masuk ke menu manajemen jadwal di studio.
 * Fungsi: Mengelola navigasi antar node pohon menggunakan stack dan memungkinkan user mengelola jadwal di level studio.
 */
void navigasi_tree_for_admin(Tree bioskop, DataType nav_for);

/*
 * I.S.  : Nilai enum DataType diberikan.
 * F.S.  : Mengembalikan pointer ke fungsi renderer tampilan sesuai tipe data node.
 * Fungsi: Menentukan renderer (fungsi tampilan) berdasarkan tipe data node dalam tree.
 */
void (*get_renderer_for_type(DataType type))(int, int, int, void*);

/*
 * I.S.  : Nilai enum DataType diberikan.
 * F.S.  : Mengembalikan string judul header menu sesuai dengan tipe node.
 * Fungsi: Menentukan judul menu yang akan ditampilkan dalam navigasi scrollable berdasarkan tipe data.
 */
const char* get_title_for_type(DataType type);

/*
 * I.S.  : Objek Studio valid diberikan sebagai parameter.
 * F.S.  : Menampilkan menu untuk menambah atau menghapus jadwal, serta kembali ke menu utama.
 * Fungsi: Menyediakan antarmuka interaktif bagi admin untuk mengelola daftar jadwal pada studio tertentu.
 */
int management_jadwal(Studio* current_studio);

/*
 * I.S.  : Pointer ke Studio valid, user diarahkan untuk mengisi input jadwal.
 * F.S.  : Jika valid dan tidak bentrok, maka jadwal akan ditambahkan ke list jadwal studio.
 * Fungsi: Menghandle proses input data jadwal baru dan menyisipkannya ke dalam list jadwal studio.
 */
void handle_tambah_jadwal(Studio* current_studio);

/*
 * I.S.  : Pointer ke Studio valid, namun implementasi belum selesai.
 * F.S.  : (Placeholder) Menampilkan pesan dummy untuk menu hapus jadwal.
 * Fungsi: Fungsi ini akan menghapus jadwal yang dipilih dari list studio (masih perlu implementasi lanjutan).
 */
void handle_hapus_jadwal(Studio* current_studio);

/*
 * I.S.  : Tidak ada kondisi awal khusus. Sistem telah berjalan dan event queue sudah tersedia.
 * F.S.  : Menampilkan menu interaktif untuk manajemen event: tambah, proses antrian, dan hapus event.
 * Fungsi: Menyediakan menu utama untuk fitur manajemen event khususnya berbasis antrian prioritas.
 */
int management_event(Studio* current_studio);

/*
 * I.S.  : User akan diminta mengisi data event (nama, film, tanggal, sesi, kuota).
 * F.S.  : Jika input valid, maka event baru akan dibuat dan siap dimasukkan ke dalam sistem.
 * Fungsi: Mengumpulkan data input dan menginisialisasi objek Event baru menggunakan konstruktor.
 */
void handle_tambah_event(Studio* current_studio);

/*
 * I.S.  : Queue antrian event sudah terisi, array tujuan untuk hasil proses sudah dialokasikan.
 * F.S.  : Mengeluarkan item dari queue ke dalam array hasil hingga mencapai batas maksimum atau queue habis.
 * Fungsi: Mengekstrak isi antrian prioritas event ke dalam array untuk diproses lebih lanjut.
 */
int proses_antrian_event(Queue* q, QueueData* outArray, int maxSize);

/*
 * I.S.  : Fungsi belum diimplementasikan secara penuh.
 * F.S.  : (Placeholder) Akan digunakan untuk menghapus event dari sistem.
 * Fungsi: Menyediakan template untuk fitur penghapusan event dari sistem antrian atau list event.
 */
void handle_hapus_event();

/*
 * I.S.  : Fitur masih dalam tahap pengembangan.
 * F.S.  : Fungsi ini akan mengatur tampilan dan proses pengambilan data dari queue event.
 * Fungsi: Menghandle antarmuka untuk proses pengeluaran item dari antrian event sesuai prioritas.
 */
void handle_proses_antrian_event();



#endif /*HANDLE_MENU_ADMIN_H*/
