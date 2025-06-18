#include "handle_event.h"


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