#include "handle_crud_tree.h"

void tambah_jadwal_ke_studio(Studio* studio) {
    if (!studio) return;

    Time waktu_start, waktu_end;
    date tanggal;
    char judul[128];
    int harga, jumlah_kursi;

    printf("== TAMBAH JADWAL FILM ==\n");
    printf("Judul Film         : "); fgets(judul, sizeof(judul), stdin);
    judul[strcspn(judul, "\n")] = '\0';

    printf("Harga Tiket (Rp)   : "); scanf("%d", &harga); getchar();
    printf("Jumlah Kursi       : "); scanf("%d", &jumlah_kursi); getchar();

    printf("Tanggal Tayang     :\n"); ReadDate(&tanggal);
    printf("Waktu Mulai        :\n"); ReadTime(&waktu_start);
    printf("Waktu Selesai      :\n"); ReadTime(&waktu_end);

    if (is_exits_jadwal(*get_jadwal_studio(studio), tanggal, waktu_start, waktu_end)) {
        printf("❌ Jadwal bentrok dengan jadwal lain!\n");
        return;
    }

    Jadwal* jadwal_baru = constructor_jadwal(waktu_start, waktu_end, tanggal, harga, judul, jumlah_kursi);
    if (!jadwal_baru) {
        printf("❌ Gagal membuat jadwal!\n");
        return;
    }

    insert_value_last(&get_jadwal_studio(studio)->First, JADWAL_INFO(jadwal_baru), TYPE_JADWAL);
    printf("✅ Jadwal berhasil ditambahkan!\n");
}
