# 📘 INCUBATOR - Tugas Besar Mata Kuliah Struktur Data dan Algoritma 

## 📌 Deskripsi Umum
**INCUBATOR** adalah sebuah program simulasi sistem pemesanan tiket bioskop berskala nasional, dikembangkan sebagai Tugas Besar Mata Kuliah *Struktur Data dan Algoritma*.

Proyek ini mengimplementasikan struktur data pohon non-biner generik untuk menyimpan data hirarkis wilayah (Negara → Provinsi → Kota → Bioskop → Studio), serta list terhubung untuk menyimpan jadwal film di setiap studio. Sistem ini mendukung penambahan, pencarian, pembaruan, dan penghapusan data (CRUD), serta menyimpan data ke dalam format JSON dan binary file.

## 💻 Deskripsi Kode

### Struktur Direktori
📁 src/
├── bioskop.c # ADT untuk data bioskop
├── negara.c # ADT untuk data negara
├── provinsi.c # ADT untuk data provinsi
├── kota.c # ADT untuk data kota
├── studio.c # ADT untuk data studio
├── kursi.c # ADT untuk data kursi dan visualisasi
├── film.c # ADT untuk data film
├── jadwal.c # ADT untuk jadwal penayangan film
├── time_adt.c # ADT waktu (jam, menit, detik)
├── date.c # ADT tanggal
├── linked.c # ADT List terhubung generik
├── tree_data.c # ADT Pohon generik (non-biner)
├── crud_film.c # Modul CRUD untuk film (binary)
├── read_json.c # Modul parser file JSON ke struct
├── write_json.c # Modul serializer struct ke JSON

### Penjelasan File Utama

- **`tree_data.c`**: Mengatur struktur pohon non-biner untuk menyimpan data wilayah dan studio.
- **`linked.c`**: Implementasi list terhubung generik untuk menyimpan data `Jadwal`, `Film`, `Event`, dll.
- **`jadwal.c`**: Menyimpan data jadwal film, relasi dengan kursi dan film.
- **`film.c` & `crud_film.c`**: Modul manajemen data film (CRUD), serta simpan/muat dari file biner.
- **`read_json.c` & `write_json.c`**: Modul pemrosesan JSON menggunakan pustaka `cJSON` untuk serialisasi/deserialisasi data tree.
- **`kursi.c`**: Menyimpan informasi dan status tiap kursi pada sebuah studio.
- **`studio.c`**: Mewakili studio dalam bioskop, menyimpan list jadwal.
- **`time_adt.c` & `date.c`**: Pendukung validasi dan manipulasi data waktu dan tanggal.

## 📈 Peluang Pengembangan
Beberapa ide untuk pengembangan program ini ke depannya antara lain:

- 🔐 **Autentikasi Multi-Role**: Dukungan untuk user dengan role Admin, Pengunjung, dan Operator Studio.
- 📊 **Statistik Penjualan**: Visualisasi atau laporan pendapatan, jumlah penonton per film, per wilayah, dsb.
- 🎫 **Fitur Riwayat dan Pemesanan**: Penyimpanan riwayat pemesanan user termasuk tanggal, jam, kursi, dan harga.
- 🕸️ **Integrasi GUI / Web**: Membuat antarmuka berbasis GUI (GTK / Qt) atau web-based (FastCGI / REST API).
- 🧪 **Unit Testing & Validasi**: Menggunakan kerangka kerja seperti `Unity` atau `CUnit` untuk pengujian fungsionalitas.
- 🛠️ **Optimasi Penyimpanan**: Kompresi file JSON, pengelolaan memori dinamis, dan penghindaran memory leak.

## 📚 Referensi
- Dokumentasi resmi [cJSON](https://github.com/DaveGamble/cJSON)
