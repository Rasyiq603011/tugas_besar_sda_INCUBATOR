#include "date.h"

/*********** Konstruktor dan Selektor ************/
void CreateDate(date *D) {
    SetTgl(1, D);
    SetBln(1, D);
    SetThn(1900, D);
}

date getTodayDate() {
    date today;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    today.Tgl = tm.tm_mday;
    today.Bln = tm.tm_mon + 1;
    today.Thn = tm.tm_year + 1900;

    return today;
}

int GetTgl(date D) { return D.Tgl; }
int GetBln(date D) { return D.Bln; }
int GetThn(date D) { return D.Thn; }

void SetTgl(int NewTgl, date *D) { D->Tgl = NewTgl; }
void SetBln(int NewBln, date *D) { D->Bln = NewBln; }
void SetThn(int NewThn, date *D) { D->Thn = NewThn; }

/*********** Validasi ************/
boolean isKabisat(date D) {
    int y = D.Thn;
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

int getEndDate(date D) {
    switch (D.Bln) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isKabisat(D) ? 29 : 28;
        default: return 31;
    }
}

boolean isValid(date D) {
    return D.Thn >= 1900 && D.Thn <= 2100 &&
           D.Bln >= 1 && D.Bln <= 12 &&
           D.Tgl >= 1 && D.Tgl <= getEndDate(D);
}

/*********** Operasi Tanggal ************/
date DateBefore(date D) {
    date result = D;
    if (D.Tgl == 1) {
        if (D.Bln == 1) {
            result.Bln = 12;
            result.Thn--;
        } else {
            result.Bln--;
        }
        result.Tgl = getEndDate(result);
    } else {
        result.Tgl--;
    }
    return result;
}

date NextDate(date D) {
    date result = D;
    if (D.Tgl == getEndDate(D)) {
        result.Tgl = 1;
        if (D.Bln == 12) {
            result.Bln = 1;
            result.Thn++;
        } else {
            result.Bln++;
        }
    } else {
        result.Tgl++;
    }
    return result;
}

int DateDifference(date d1, date d2) {
    struct tm tm1 = {0}, tm2 = {0};
    tm1.tm_mday = d1.Tgl; tm1.tm_mon = d1.Bln - 1; tm1.tm_year = d1.Thn - 1900;
    tm2.tm_mday = d2.Tgl; tm2.tm_mon = d2.Bln - 1; tm2.tm_year = d2.Thn - 1900;
    time_t t1 = mktime(&tm1), t2 = mktime(&tm2);
    return (int)difftime(t2, t1) / (60 * 60 * 24);
}

int compare_date(const date d1, const date d2) {
    return (d1.Tgl == d2.Tgl) && (d1.Bln == d2.Bln) && (d1.Thn == d2.Thn);
}

/*********** I/O ************/
int getInt(const char *prompt) {
    char buffer[100];
    int value;
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d", &value) == 1) return value;
        }
        printf("Input tidak valid. Silakan coba lagi.\n");
    }
}

void ReadDate(date *D) {
    printf("Masukkan Nilai Tanggal:\n");
    D->Tgl = getInt("Tanggal : ");
    D->Bln = getInt("Bulan   : ");
    D->Thn = getInt("Tahun   : ");
    if (!isValid(*D)) {
        printf("Tanggal tidak valid. Diset ke default.\n");
        CreateDate(D);
    }
}

void PrintObj(date D) {
    printf("%02d/%02d/%04d\n", D.Tgl, D.Bln, D.Thn);
}

/*********** Konversi String ************/
boolean string_to_date(const char* str, date* D) {
    int day, month, year;
    if (sscanf(str, "%d/%d/%d", &day, &month, &year) == 3) {
        D->Tgl = day;
        D->Bln = month;
        D->Thn = year;
        return isValid(*D);
    }
    return false;
}

char* date_to_string(date D) {
    char* buffer = (char*) malloc(11 * sizeof(char));
    if (buffer != NULL) {
        snprintf(buffer, 11, "%02d/%02d/%04d", D.Tgl, D.Bln, D.Thn);
    }
    return buffer;
}

