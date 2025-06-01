#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#define MAX_CHAR
#include <stdbool.h>

// ================================================
// ==================== TREE ======================
// ================================================

// typedef char String[MAX_CHAR];
typedef char* String;

typedef enum {
    PROVINSI,
    KOTA,
    BIOSKOP,
    FILM,
    TANGGAL,
    JADWAL
} Datatype;

typedef union {
    Provinsi* provinsi;
    Kota* kota;
    Bioskop* bioskop;
    Film* film;
    Tanggal* tanggal;
    Jadwal* jadwal;
} Infotype;

typedef struct tElmtList* address;
typedef struct tElmtList {
    Infotype info;
    Datatype type;
    address first_son;
    address next_brother;
} ElmtList;

// ================================================
// ==================== NEGARA ====================
// ================================================

typedef struct data_negara Negara;

Negara *get_negara();

void set_negara(Negara N);




// ================================================
// =================== PROVINSI ===================
// ================================================

typedef struct Provinsi Provinsi;






// ================================================
// ===================== KOTA =====================
// ================================================

typedef struct Kota Kota;





// ===============================================
// =================== BIOSKOP ===================
// ===============================================

typedef struct Bioskop Bioskop;




// ================================================
// ===================== FILM =====================
// ================================================

typedef struct Film Film;




// ================================================
// ==================== Jadwal ====================
// ================================================

typedef struct Jadwal Jadwal;



// ================================================
// ==================== Kursi =====================
// ================================================

typedef struct Kursi Kursi;




#endif