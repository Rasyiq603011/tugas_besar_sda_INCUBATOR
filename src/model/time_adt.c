#include "time_adt.h"
#include <stdlib.h>
#include <string.h>

/* ======== Konstruktor ======== */
void CreateTime(Time *T) {
    T->jam = 0;
    T->menit = 0;
    T->detik = 0;
}

void SetTime(Time *T, int jam, int menit, int detik) {
    T->jam = jam;
    T->menit = menit;
    T->detik = detik;
}

void CopyTime(Time *dest, Time src) {
    dest->jam = src.jam;
    dest->menit = src.menit;
    dest->detik = src.detik;
}

/* ======== Selector ======== */
int GetJam(Time T) { return T.jam; }
int GetMenit(Time T) { return T.menit; }
int GetDetik(Time T) { return T.detik; }

/* ======== Mutator ======== */
void SetJam(int jam, Time *T) { T->jam = jam; }
void SetMenit(int menit, Time *T) { T->menit = menit; }
void SetDetik(int detik, Time *T) { T->detik = detik; }

/* ======== Validasi ======== */
bool isValidTime(Time T) {
    return T.jam >= 0 && T.jam <= 23 &&
           T.menit >= 0 && T.menit <= 59 &&
           T.detik >= 0 && T.detik <= 59;
}

/* ======== Input/Output ======== */
void ReadTime(Time *T) {
    printf("Masukkan Jam   : "); scanf("%d", &T->jam);
    printf("Masukkan Menit : "); scanf("%d", &T->menit);
    printf("Masukkan Detik : "); scanf("%d", &T->detik);

    if (!isValidTime(*T)) {
        printf("Waktu tidak valid. Di-reset ke 00:00:00.\n");
        CreateTime(T);
    }
}

void PrintTime(Time T) {
    printf("%02d:%02d:%02d\n", T.jam, T.menit, T.detik);
}

bool string_to_time(const char *str, Time *T) {
    int h, m, s;
    if (sscanf(str, "%d:%d:%d", &h, &m, &s) == 3) {
        SetTime(T, h, m, s);
        return isValidTime(*T);
    }
    return false;
}

char* time_to_string(Time T) {
    char *result = (char *)malloc(9);
    if (result != NULL) {
        sprintf(result, "%02d:%02d:%02d", T.jam, T.menit, T.detik);
    }
    return result;
}


/* ======== Sistem Waktu ======== */
Time getCurrentTime() {
    Time now;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    now.jam = tm.tm_hour;
    now.menit = tm.tm_min;
    now.detik = tm.tm_sec;

    return now;
}

/* ======== Konversi ======== */
int TimeToSecond(Time T) {
    return T.jam * 3600 + T.menit * 60 + T.detik;
}

Time SecondToTime(int seconds) {
    Time T;
    seconds = seconds % 86400; // satu hari
    T.jam = seconds / 3600;
    seconds %= 3600;
    T.menit = seconds / 60;
    T.detik = seconds % 60;
    return T;
}

/* ======== Operasi ======== */
void AddSecond(Time *T, int seconds) {
    int total = TimeToSecond(*T) + seconds;
    *T = SecondToTime(total);
}

bool isEqualTime(Time T1, Time T2) {
    return T1.jam == T2.jam &&
           T1.menit == T2.menit &&
           T1.detik == T2.detik;
}

int CompareTime(Time T1, Time T2) {
    int s1 = TimeToSecond(T1);
    int s2 = TimeToSecond(T2);
    if (s1 < s2) return -1;
    else if (s1 > s2) return 1;
    else return 0;
}

bool is_time_in_arrange(Time batas_awal, Time batas_akhir, Time check) {
    int t_awal = TimeToSecond(batas_awal);
    int t_akhir = TimeToSecond(batas_akhir);
    int t_check = TimeToSecond(check);

    if (t_awal <= t_akhir) {
        return (t_awal <= t_check && t_check <= t_akhir);
    } else {
        return (t_check >= t_awal || t_check <= t_akhir); // lintas tengah malam
    }
}
