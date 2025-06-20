#ifndef VIEW_H
#define VIEW_H
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "../model/tree_data.h"
#define TERMINAL_WIDTH 160

/*
 * I.S.  : Tidak diketahui posisi kursor di console.
 * F.S.  : Kursor berpindah ke posisi (x, y) di console.
 * Fungsi: Mengatur posisi kursor dalam terminal.
 */
void gotoxy(int x, int y);

/*
 * I.S.  : Terdapat daftar opsi menu dan nilai indeks opsi terpilih.
 * F.S.  : Menu ditampilkan di layar dengan highlight pada opsi yang terpilih.
 * Fungsi: Menampilkan menu statis dengan highlight navigasi.
 */
void display_menu(int opsi_terpilih, int jumlah_opsi, const char *options[jumlah_opsi], const char* header);

/*
 * I.S.  : Terdapat array data dan fungsi render.
 * F.S.  : Menu scrollable ditampilkan, dan pengguna dapat memilih salah satu opsi atau membatalkan.
 * Fungsi: Menampilkan menu yang dapat discroll, mengembalikan indeks pilihan, atau -1 jika dibatalkan.
 */
int scrollable_menu(void** data_array, int jumlah_item, void (*render)(int idx, int y_pos, int selected, void* data), const char* header, int tinggi_blok, int max_tampil);

/*
 * I.S.  : Baris pada terminal telah terisi karakter sebelumnya.
 * F.S.  : Baris terminal dibersihkan (diisi spasi).
 * Fungsi: Membersihkan satu baris di terminal.
 */
void clear_line(int y);

/*
 * I.S.  : Pengguna belum mengisi teks di field.
 * F.S.  : Buffer terisi string dari input pengguna.
 * Fungsi: Mengambil input string dari pengguna, bisa sebagai password (disamarkan).
 */
void input_text_field(int x, int y, char** buffer, int maxLen, bool isPassword);

/*
 * I.S.  : Pengguna belum mengisi input angka.
 * F.S.  : Mengembalikan angka integer hasil input pengguna.
 * Fungsi: Mengambil input angka dengan batas digit maksimum.
 */
int input_integer_field(int x, int y, int maxDigit);

/*
 * I.S.  : String input telah tersedia.
 * F.S.  : String ditampilkan di tengah terminal.
 * Fungsi: Menampilkan teks di tengah layar terminal.
 */
void center_print(const char* text);

/*
 * I.S.  : Belum ada tampilan splashscreen.
 * F.S.  : Splashscreen muncul, menunggu pengguna menekan ENTER.
 * Fungsi: Menampilkan animasi splashscreen awal dengan teks berjalan.
 */
void show_splashscreen();

int display_konfirmasi_menu(const char* header, const char* message, const char* options[], int jumlah_opsi);

#endif /*VIEW_H*/
