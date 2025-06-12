/* 
	File name    : linked.h
 	Made by      : Muhammad Nabil Syauqi Rasyiq
   	Date         : 30 March 2025
   	Description  : Header file for linked list implementation supporting any types
*/

#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "data_struct/film.h"
#include "data_struct/jadwal.h"
#include "data_struct/event.h"
#include "data_struct/riwayat.h"

typedef char* String;

typedef enum {
    TYPE_INTEGER = 0,
    TYPE_STRING = 1,
    TYPE_JADWAL = 2,
    TYPE_EVENT = 3,
    TYPE_FILM = 4,
    TYPE_RIWAYAT = 5
} DataType;

typedef union {
    int integer;   
    String str;
    Jadwal* jadwal;
    Event* event;
    Film* film;
    Riwayat* riwayat;
}infotype;

typedef struct node *pnode;
typedef struct node {
    infotype info;
    DataType type;
    pnode next;      
} node;

typedef struct {
    pnode First;
} List;

#define Nil NULL
#define First(L) ((L).First)
#define Type(P) ((P)->type)
#define Next(P) ((P)->next)
#define Info(P) ((P)->info)
#define info_integer(P) ((P)->info.integer)
#define info_string(P) ((P)->info.str)
#define info_jadwal(P) ((P)->info.jadwal)
#define info_event(P) ((P)->info.event)
#define info_film(P) ((P)->info.film)
#define info_riwayat(P) ((P)->info.riwayat)
#define INT_INFO(x) ((infotype){.integer = (x)})
#define STR_INFO(x) ((infotype){.str = (x)})
#define JADWAL_INFO(x) ((infotype){.jadwal = (x)})
#define EVENT_INFO(x) ((infotype){.event = (x)})
#define FILM_INFO(x) ((infotype){.film = (x)})
#define RIWAYAT_INFO(x) ((infotype){.riwayat = (x)})

/*========================================================*/
/*==================== MAIN FUNCTIONS ====================*/
/*========================================================*/

// I.S : program tidak tahu apakah node kosong atau tidak
// F.S : mereturn true jika node kosong
// Alur : return hasil cek P == Nil?
boolean isEmpty(pnode P);

// I.S : program tidak tahu apakah List kosong atau tidak
// F.S : mereturn true jika List kosong 
// Alur : return hasil cek L.First == Nil?
boolean ListEmpty(List L);

// I.S : variabel bertipe pnode baru di deklarasikan sebagai kamus data
// F.S : pnode dipastikan siap dipakai dengan membuat pnode menunjuk ke Nil
void Createpnode(pnode *P);

// I.S : variabel bertipe list baru di deklarasikan sebagai kamus data
// F.S : menentukan tipe list dan memastikan list siap dipakai dengan membuat List.first menunjuk ke Nil
void CreateList(List *L);

// Function untuk alokasi node dengan berbagai tipe data
pnode alokasi(infotype info, DataType type);

// Function untuk dealokasi node
void dealokasi(pnode P);

/*=======================================================*/
/*================= INSERTION FUNCTIONS =================*/
/*=======================================================*/

// I.S : pnode *P Sudah di Create
// F.S : pnode newNode sudah dimasukan kedalam List dengan posisi First
void InsertFirst(pnode *P, pnode newNode);

// I.S : pnode *P Sudah di Create
// F.S : pnode newNode sudah dimasukan kedalam List dengan posisi Last
void InsertLast(pnode *P, pnode newNode);

// I.S : pnode *P Sudah di Create
// F.S : pnode newNode sudah dimasukan kedalam List dengan setelah *pBef
void InsertAfter(pnode *pBef, pnode PNew);

// I.S : pnode *P Sudah di Create
// F.S : pnode newNode sudah dimasukan kedalam List dengan sebelum *pAft
void InsertBefore(pnode *pAft, pnode *p, pnode PNew);

// Function untuk menyisipkan nilai di posisi first
void insert_value_first(pnode *P, infotype info, DataType type);

// Function untuk menyisipkan nilai di posisi last
void insert_value_last(pnode *P, infotype info, DataType type);

// Function untuk menyisipkan nilai setelah nilai tertentu
void insert_value_after(pnode *P, infotype before, infotype info, DataType type_before, DataType type_insert);

// Function untuk menyisipkan nilai sebelum nilai tertentu
void insert_value_before(pnode *P, infotype after, infotype info, DataType type_after, DataType type_insert);

/*========================================================*/
/*================== DELETION FUNCTIONS ==================*/
/*========================================================*/

// Function untuk menghapus node pertama
void delete_first(pnode *P, infotype *info);

// Function untuk menghapus node terakhir
void delete_last(pnode *P, infotype *info);

// Function untuk menghapus node berdasarkan nilai
void delete_by_value(pnode *P, infotype info, DataType type);

// IS : l tidak kosong
// FS : mendealokasi/menghapus seluruh isi list 
// Catatan: Jika list berisi string, seluruh memori untuk string tersebut juga akan dibebaskan
void clear_list(pnode *P);

/*=======================================================*/
/*================== DISPLAY FUNCTIONS ==================*/
/*=======================================================*/

// Function untuk mencetak informasi suatu node
void print_info(pnode P);

// IS : l bisa jadi kosong dan L harus sudah memiliki nilai type
// FS : Menampilkan isi list bertipe Integer dengan format angka1, angka2, ....., angkaTerakhir jika l tidak kosong jika kosong maka "List Kosong"
void print_list(List L);

/*================================================================*/
/*================== COUNT AND SEARCH FUNCTIONS ==================*/
/*================================================================*/

// IS : L mungkin kosong
// FS : menghitung jumlah elemen dari sebuah list
int count_list(List L);

// IS : L mungkin kosong, program ingin mengetahui pnode node sebelum pnode node dengan nilai info
// FS : function akan mencari tahu apakah ada node dengan nilai info?, jika ada maka function akan mereturn pnode node sebelumnya, jika tidak ada return Nil
pnode search_prec(List L, infotype info);

// IS : L mungkin kosong, program ingin mengetahui pnode node dengan nilai info
// FS : jika ada maka akan return pnode node tersebut, jika tidak ada maka akan return Nil
pnode search_by_value(pnode P, infotype info);

/*================================================================*/
/*===================== ADDITIONAL FUNCTIONS =====================*/
/*================================================================*/

// IS : L mungkin kosong
// FS : jika L tidak kosong maka function akan mengalokasikan pnode untuk menampung hasil dari mereverse List, lalu mereturnnya
pnode get_reverse_list(List L);

// IS : L mungkin kosong
// FS : jika L tidak kosong maka function akan membalik isi dari List 
void reverse_list(List *L);

// IS : L mungkin kosong
// FS : isi dari L1 akan dicopy ke L2
// Catatan: Untuk list string, semua string akan di-deep copy
void copy_list(List L1, List *L2);

boolean compare_list(List L1, List L2);

// Function untuk mendapatkan nilai di posisi depan
infotype get_front_value(List L);

// Function untuk mendapatkan nilai di posisi belakang
infotype get_tail_value(List L);

#endif /* LINKED_H */
