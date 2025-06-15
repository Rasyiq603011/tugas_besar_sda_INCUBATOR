#ifndef DATE_H
#define DATE_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Tipe data untuk tanggal */
typedef struct {
    int Tgl;
    int Bln;
    int Thn;
} date;

/*********** Konstruktor dan Selektor ************/
void CreateDate(date *D);

date getTodayDate();

int GetTgl(date D);

int GetBln(date D);

int GetThn(date D);

void SetTgl(int NewTgl, date *D);

void SetBln(int NewBln, date *D);

void SetThn(int NewThn, date *D);

/*********** Validasi ************/
boolean isKabisat(date D);

int getEndDate(date D);

boolean isValid(date D);

/*********** Operasi Tanggal ************/
date DateBefore(date D);

date NextDate(date D);

int DateDifference(date d1, date d2);

int compare_date(const date d1, const date d2);

/*********** I/O ************/
int getInt(const char *prompt);

void ReadDate(date *D);

void PrintObj(date D);

/*********** Konversi String ************/
boolean string_to_date(const char* str, date* D);

char* date_to_string(date D);

#endif
