#include "handle_menu_admin.h"

void handle_tambah_jadwal(Studio* current_studio)
{
    if (!current_studio) return;

    Time waktu_start, waktu_end;
    date tanggal;
    char* judul = NULL;
    int harga_tiket, jumlah_kursi;
    List* daftar_jadwal = get_jadwal_studio(current_studio);

    while (1) 
    {

        boolean input_sukses = handle_input_data_jadwal(&waktu_start, &waktu_end, &tanggal, judul, &harga_tiket, &jumlah_kursi);

        if (!input_sukses) 
        {
            printf("❌ Input tidak valid.\n");
        }
         else if (is_exits_jadwal(*daftar_jadwal, tanggal, waktu_start, waktu_end)) 
        {
            printf("❌ Jadwal bentrok dengan jadwal lain!\n");
        }
         else 
        {

            Jadwal* jadwal_baru = constructor_jadwal(waktu_start, waktu_end, tanggal, harga_tiket, judul, jumlah_kursi);
            free(judul);
            judul = NULL;

            if (!jadwal_baru) 
            {
                printf("❌ Gagal membuat jadwal!\n");
                continue;
            }

            insert_value_last(&daftar_jadwal->First, JADWAL_INFO(jadwal_baru), TYPE_JADWAL);
            printf("✅ Jadwal berhasil ditambahkan!\n");
            break;
        }

        if (judul) 
        {
            free(judul);
            judul = NULL;
        }

        char opsi;
        printf("Apakah Anda ingin melanjutkan tambah jadwal ? (y/n): ");
        scanf(" %c", &opsi); getchar(); 

        if (opsi == 'n' || opsi == 'N') {
            printf("Proses pembatalan penambahan jadwal.\n");
            break;
        }
    }
}


void handle_hapus_jadwal()
{
    pritnf("ini menu untuk hapus jadwal");
}


void handle_tambah_event()
{
    String nama_event, waktu_start, waktu_end, judul_film;
    int jumlah_kuota_sesi, jumlah_sesi;

    input_event(nama_event, judul_film, waktu_start, waktu_end, &jumlah_sesi, &jumlah_kuota_sesi);
    date start, end;
    if (!string_to_date(waktu_start, &start))
    {
        start = getTodayDate();
    }
    if (!string_to_date(waktu_end, &end))
    {
        end = getTodayDate();
    }

    Event* new_event = constructor_event(nama_event, start ,end , judul_film, jumlah_kuota_sesi, jumlah_sesi);
    
    
    // InsertAkhirV(&Head(*buku), judul, stock);
    // printf("Buku berhasil ditambahkan!\n");
}

void handle_proses_antrian_event()
{


}

int proses_antrian_event(Queue* q, QueueData* outArray, int maxSize)
{
    if (!q || !outArray || maxSize <= 0) return 0;

    int count = 0;
    while (!isPriorityQueueEmpty(q) && count < maxSize) 
    {
        QueueData data = dequeuePriority(q);
        if (data) 
        {
            outArray[count++] = data;
        }
    }

    return count;
}

void handle_hapus_event()
{

}