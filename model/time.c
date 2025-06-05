#include "time.h"

/* Konstruktor default */
void CreateTime(Time *T) {
    T->jam = 0;
    T->menit = 0;
    T->detik = 0;
}

/* Selector */
int GetJam(Time T) { return T.jam; }
int GetMenit(Time T) { return T.menit; }
int GetDetik(Time T) { return T.detik; }

/* Mutator */
void SetJam(int J, Time *T) { T->jam = J; }
void SetMenit(int M, Time *T) { T->menit = M; }
void SetDetik(int D, Time *T) { T->detik = D; }

/* Validasi */
bool isValidTime(Time T) {
    return (T.jam >= 0 && T.jam <= 23 &&
            T.menit >= 0 && T.menit <= 59 &&
            T.detik >= 0 && T.detik <= 59);
}

/* Baca dari keyboard */
void ReadTime(Time *T) {
    printf("Masukkan Jam   : "); scanf("%d", &T->jam);
    printf("Masukkan Menit : "); scanf("%d", &T->menit);
    printf("Masukkan Detik : "); scanf("%d", &T->detik);

    if (!isValidTime(*T)) {
        printf("Waktu tidak valid. Di-reset ke 00:00:00.\n");
        CreateTime(T);
    }
}

/* Cetak */
void PrintTime(Time T) {
    printf("%02d:%02d:%02d\n", T.jam, T.menit, T.detik);
}

/* Waktu sistem saat ini */
Time getCurrentTime() {
    Time now;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    now.jam = tm.tm_hour;
    now.menit = tm.tm_min;
    now.detik = tm.tm_sec;

    return now;
}

/* Konversi waktu ke detik */
int TimeToSecond(Time T) {
    return T.jam * 3600 + T.menit * 60 + T.detik;
}

/* Konversi detik ke waktu */
Time SecondToTime(int seconds) {
    Time T;
    seconds = seconds % 86400; // dalam satu hari
    T.jam = seconds / 3600;
    seconds %= 3600;
    T.menit = seconds / 60;
    T.detik = seconds % 60;
    return T;
}

/* Perbandingan waktu */
int CompareTime(Time T1, Time T2) {
    int s1 = TimeToSecond(T1);
    int s2 = TimeToSecond(T2);
    if (s1 < s2) return -1;
    else if (s1 > s2) return 1;
    else return 0;
}
