#include "tambah_jadwal_view.h"

void input_jadwal(char** waktu_start, char** waktu_end, char** tanggal_tayang, char** judul_film, int* harga_tiket) 
{
    system("cls");
    int start_vertikal = 10;
    gotoxy(30, start_vertikal + 0);  printf("|====================================================================|");
    gotoxy(30, start_vertikal + 1);  printf("|                        FORM INPUT JADWAL FILM                      |");
    gotoxy(30, start_vertikal + 2);  printf("|====================================================================|");
    gotoxy(30, start_vertikal + 3);  printf("| Judul Film:                                                        |");
    gotoxy(30, start_vertikal + 4);  printf("| waktu Mulai (HH:MM:SS):                                            |");
    gotoxy(30, start_vertikal + 5);  printf("| waktu Berakhir (HH:MM:SS):                                         |");
    gotoxy(30, start_vertikal + 6);  printf("| Tanggal Tayang (dd/mm/yyyy):                                       |");
    gotoxy(30, start_vertikal + 7);  printf("| Harga Tiket:                                                       |");
    gotoxy(30, start_vertikal + 8);  printf("|====================================================================|");

    gotoxy(44, start_vertikal + 3); input_text_field(44, start_vertikal + 3, judul_film, 50, false);
    
    gotoxy(60, start_vertikal + 4); input_text_field(56, start_vertikal + 4, waktu_start,12 , false);
    
    gotoxy(63, start_vertikal + 5); input_text_field(59, start_vertikal + 5, waktu_end, 12, false);
    
    gotoxy(60, start_vertikal + 6); input_text_field(60, start_vertikal + 6, tanggal_tayang, 12, false);

    gotoxy(45, start_vertikal + 7); *harga_tiket = input_integer_field(45, start_vertikal + 7, 4);

}

// Fungsi utama untuk input event
void input_event(char** nama_event, char** judul_film, char** tanggal_mulai, char** tanggal_akhir, int* jumlah_sesi, int* jumlah_kuota_sesi) 
{
    system("cls");
    int start_vertikal = 10;
    gotoxy(30, start_vertikal + 0);  printf("|====================================================================|");
    gotoxy(30, start_vertikal + 1);  printf("|                         FORM INPUT EVENT FILM                      |");
    gotoxy(30, start_vertikal + 2);  printf("|====================================================================|");
    gotoxy(30, start_vertikal + 3);  printf("| Nama Event:                                                        |");
    gotoxy(30, start_vertikal + 4);  printf("| Tanggal Mulai (dd/mm/yyyy):                                        |");
    gotoxy(30, start_vertikal + 5);  printf("| Tanggal Berakhir (dd/mm/yyyy):                                     |");
    gotoxy(30, start_vertikal + 6);  printf("| Judul Film:                                                        |");
    gotoxy(30, start_vertikal + 7);  printf("| Jumlah Sesi:                                                       |");
    gotoxy(30, start_vertikal + 8);  printf("| Jumlah Kuota/sesi:                                                 |");
    gotoxy(30, start_vertikal + 9);  printf("|====================================================================|");

    gotoxy(44, start_vertikal + 3); input_text_field(44, start_vertikal + 3, nama_event, 50, false);
    
    gotoxy(60, start_vertikal + 4); input_text_field(60, start_vertikal + 4, tanggal_mulai,12 , false);
    
    gotoxy(63, start_vertikal + 5); input_text_field(63, start_vertikal + 5, tanggal_akhir, 12, false);
    
    gotoxy(44, start_vertikal + 6); input_text_field(44, start_vertikal + 6, judul_film, 50, false);

    gotoxy(45, start_vertikal + 7); *jumlah_sesi = input_integer_field(45, start_vertikal + 7, 4);

    gotoxy(51, start_vertikal + 8); *jumlah_kuota_sesi = input_integer_field(51, start_vertikal + 8, 4);
}
