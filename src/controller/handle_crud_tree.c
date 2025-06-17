#include "handle_crud_tree.h"

void handle_inisialisasi_data(Tree* node_tree, List* list_film)
{

}

void handle_menu_tambah_jadwal()
{
    
}

void tambah_jadwal_ke_studio(Studio* studio) 
{
    if (!studio) return;

    Time waktu_start, waktu_end;
    date tanggal;
    char judul[128];
    int harga, jumlah_kursi;

    printf("== TAMBAH JADWAL FILM ==\n");

    input_judul_film(judul, sizeof(judul));
    harga = input_harga_tiket();
    jumlah_kursi = input_jumlah_kursi();
    input_tanggal(&tanggal);
    input_waktu(&waktu_start, "Waktu Mulai");
    input_waktu(&waktu_end, "Waktu Selesai");

    List* daftar_jadwal = get_jadwal_studio(studio);
    if (is_exits_jadwal(*daftar_jadwal, tanggal, waktu_start, waktu_end)) {
        printf("❌ Jadwal bentrok dengan jadwal lain!\n");
        return;
    }

    Jadwal* jadwal_baru = constructor_jadwal(waktu_start, waktu_end, tanggal, harga, judul, jumlah_kursi);
    if (!jadwal_baru) {
        printf("❌ Gagal membuat jadwal!\n");
        return;
    }

    insert_value_last(&daftar_jadwal->First, JADWAL_INFO(jadwal_baru), TYPE_JADWAL);
    printf("✅ Jadwal berhasil ditambahkan!\n");
}


void input_judul_film(char* buffer, int size) {
    do {
        printf("Judul Film         : ");
        fgets(buffer, size, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
    } while (strlen(buffer) == 0);
}

int input_harga_tiket() {
    int harga;
    do {
        printf("Harga Tiket (Rp)   : ");
    } while (scanf("%d", &harga) != 1 || harga < 0 || getchar() != '\n');
    return harga;
}

int input_jumlah_kursi() {
    int jumlah;
    do {
        printf("Jumlah Kursi       : ");
    } while (scanf("%d", &jumlah) != 1 || jumlah <= 0 || getchar() != '\n');
    return jumlah;
}

void input_tanggal(date* tanggal) {
    printf("Tanggal Tayang     :\n");
    ReadDate(tanggal);
    while (!isValid(*tanggal)) {
        printf("⚠️  Tanggal tidak valid, silakan input ulang.\n");
        ReadDate(tanggal);
    }
}

void input_waktu(Time* waktu, const char* label) {
    printf("%s:\n", label);
    ReadTime(waktu);
    while (!isValidTime(*waktu)) {
        printf("⚠️  Waktu tidak valid, silakan input ulang.\n");
        ReadTime(waktu);
    }
}

