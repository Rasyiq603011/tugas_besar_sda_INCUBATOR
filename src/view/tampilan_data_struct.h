#ifndef TAMPILAN_DATA_STRUCT_H
#define TAMPILAN_DATA_STRUCT_H

#include "../model/tree_data.h"
#include "view.h"

/*
 * I.S.  : Parameter node berisi data negara yang valid, indeks, posisi Y, dan status terpilih tersedia.
 * F.S.  : Menampilkan satu baris informasi negara berupa nama dan jumlah bioskop secara terformat ke layar.
 * Fungsi: Menyajikan tampilan visual data negara dalam sistem navigasi data tree.
 */
void tampilan_negara(int idx, int y, int selected, void* selected_node);

/*
 * I.S.  : Parameter node berisi data provinsi yang valid, indeks, posisi Y, dan status terpilih tersedia.
 * F.S.  : Menampilkan satu baris informasi provinsi berupa nama dan jumlah bioskop secara terformat ke layar.
 * Fungsi: Menyajikan tampilan visual data provinsi dalam sistem navigasi data tree.
 */
void tampilan_provinsi(int idx, int y, int selected, void* selected_node);

/*
 * I.S.  : Parameter node berisi data kota yang valid, indeks, posisi Y, dan status terpilih tersedia.
 * F.S.  : Menampilkan satu baris informasi kota berupa nama dan jumlah bioskop secara terformat ke layar.
 * Fungsi: Menyajikan tampilan visual data kota dalam sistem navigasi data tree.
 */
void tampilan_kota(int idx, int y, int selected, void* selected_node);

/*
 * I.S.  : Parameter node berisi data bioskop yang valid, indeks, posisi Y, dan status terpilih tersedia.
 * F.S.  : Menampilkan dua baris informasi bioskop berupa nama (dengan jumlah studio) dan alamatnya.
 * Fungsi: Menyajikan tampilan visual data bioskop sebagai bagian dari hirarki node kota.
 */
void tampilan_bioskop(int idx, int y, int selected, void* selected_node);

/*
 * I.S.  : Parameter node berisi data studio yang valid, indeks, posisi Y, dan status terpilih tersedia.
 * F.S.  : Menampilkan dua baris informasi studio berupa nama dan jumlah jadwal tersedia.
 * Fungsi: Menyajikan tampilan visual data studio sebagai level paling bawah dalam hierarki navigasi.
 */
void tampilan_studio(int idx, int y, int selected, void* pointer_head);

/*
 * I.S.  : Parameter jadwal berisi data valid, indeks dan posisi tampilan ditentukan, serta status terpilih diketahui.
 * F.S.  : Menampilkan dua baris informasi jadwal berupa judul film, harga tiket, tanggal, dan waktu tayang.
 * Fungsi: Menyajikan informasi terperinci untuk satu jadwal tayang dalam tampilan list jadwal di studio.
 */
void tampilan_jadwal(int idx, int y, int selected, void* selected_node);

#endif /* TAMPILAN_DATA_STRUCT_H */
