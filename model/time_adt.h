#ifndef TIME_H
#define TIME_H

#include <stdio.h>
#include <time.h>
#include <stdbool.h>

typedef struct time {
    int jam;
    int menit;
    int detik;
} Time;

/* Konstruktor */
void CreateTime(Time *T);

/* Selector */
int GetJam(Time T);
int GetMenit(Time T);
int GetDetik(Time T);

/* Mutator */
void SetJam(int J, Time *T);
void SetMenit(int M, Time *T);
void SetDetik(int D, Time *T);

/* Validasi */
bool isValidTime(Time T);

/* I/O */
void ReadTime(Time *T);
void PrintTime(Time T);

/* Sistem */
Time getCurrentTime();

/* Konversi */
int TimeToSecond(Time T);
Time SecondToTime(int seconds);

/* Perbandingan */
int CompareTime(Time T1, Time T2); // return -1, 0, 1

#endif
