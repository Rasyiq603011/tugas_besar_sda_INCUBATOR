#ifndef TIME_ADT_H
#define TIME_ADT_H

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

/* ======== Tipe Data Time ======== */
typedef struct {
    int jam;
    int menit;
    int detik;
} Time;

/* ======== Konstruktor & Inisialisasi ======== */
void CreateTime(Time *T);                         

void SetTime(Time *T, int jam, int menit, int detik); 

void CopyTime(Time *dest, Time src);         

/* ======== Selector ======== */
int GetJam(Time T);

int GetMenit(Time T);

int GetDetik(Time T);

/* ======== Mutator ======== */
void SetJam(int jam, Time *T);

void SetMenit(int menit, Time *T);

void SetDetik(int detik, Time *T);

/* ======== Validasi ======== */
bool isValidTime(Time T);

/* ======== Input/Output ======== */
void ReadTime(Time *T);               

void PrintTime(Time T);             

bool string_to_time(const char *str, Time *T); // Parse dari string

char* time_to_string(Time T);

/* ======== Sistem Waktu ======== */
Time getCurrentTime(); 

/* ======== Konversi ======== */

int TimeToSecond(Time T);

Time SecondToTime(int seconds);

/* ======== Operasi ======== */
void AddSecond(Time *T, int seconds);   

bool isEqualTime(Time T1, Time T2);     

int CompareTime(Time T1, Time T2);  

bool is_time_in_arrange(Time awal, Time akhir, Time check); 

#endif
