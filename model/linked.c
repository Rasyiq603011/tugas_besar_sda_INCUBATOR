#include "linked.h"

/*========================================================*/
/*==================== MAIN FUNCTIONS ====================*/
/*========================================================*/

boolean isEmpty(pnode P) {
    return (P == Nil);
}

boolean is_valid_type(DataList type) {
    return (type >= TYPE_INTEGER && type <= TYPE_RIWAYAT);
}

boolean ListEmpty(List L) {
    return (First(L) == Nil);   
}

void Createpnode(pnode *P) {
    *P = Nil;
}

void CreateList(List *L) {
    First(*L) = Nil;
}

pnode alokasi(InfoList info, DataList type) {
    pnode new_node = (pnode) malloc(sizeof(node));
    switch (type)
    {
        case TYPE_INTEGER:
            if (new_node != Nil) {
                info_integer(new_node) = info.integer;
                Next(new_node) = Nil;
            }
            return new_node;
        case TYPE_STRING:
            if (new_node != Nil) {
                info_string(new_node) = strdup(info.str);
                if (info_string(new_node) == NULL) {
                    free(new_node);
                    return Nil;
                }
                Next(new_node) = Nil;
            }
            return new_node;
        case TYPE_JADWAL:
            if (new_node != Nil) {
                info_jadwal(new_node) = info.jadwal; 
                Next(new_node) = Nil;
            }
            return new_node;
        case TYPE_EVENT:
            if (new_node != Nil) {
                info_event(new_node) = info.event; 
                Next(new_node) = Nil;
            }
            return new_node;
        case TYPE_FILM:
            if (new_node != Nil) {
                info_film(new_node) = info.film; 
                Next(new_node) = Nil;
            }
            return new_node;
        case TYPE_RIWAYAT:
            if (new_node != Nil) {
                info_riwayat(new_node) = info.riwayat; 
            }
            return new_node;
        default:
            return Nil;
    }
}

void dealokasi(pnode P) {
if (P == NULL) return;
    switch (P->type) {
        case TYPE_STRING:
            if (info_string(P) != NULL) {
                free(info_string(P));
            }
            break;
        case TYPE_JADWAL:
            if (info_jadwal(P)) destructor_jadwal(info_jadwal(P));
            break;
        case TYPE_EVENT:
            // if (info_event(P)) free_event(info_event(P));
            break;
        case TYPE_FILM:
            if (info_film(P)) destroy_film(info_film(P));
            break;
        case TYPE_RIWAYAT:
            if (info_riwayat(P)) destroy_riwayat(info_riwayat(P));
            break;
        default:
            break;
    }
    free(P);
}

/*=======================================================*/
/*================= INSERTION FUNCTIONS =================*/
/*=======================================================*/

void InsertFirst(pnode *P, pnode newNode) {
    Next(newNode) = *P;
    *P = newNode;
}

void InsertLast(pnode *P, pnode newNode) {
    if (*P == Nil) {
        *P = newNode;
    } else {
        pnode last = *P;
        while (next(last) != Nil) {
            last = next(last);
        }
        Next(last) = newNode;
    }
}

void InsertAfter(pnode *pBef, pnode PNew) {
    Next(PNew) = next(*pBef);
    Next(*pBef) = PNew;
}

void InsertBefore(pnode *pAft, pnode *p, pnode PNew) {
    
    if (*pAft == *p) {
    	// jika pAft elemen pertama
        Next(PNew) = *p;
        *p = PNew;
    } else {
        pnode prev = *p;
        while (Next(prev) != *pAft) {
            prev = Next(prev);
        }
        Next(PNew) = *pAft;
        Next(prev) = PNew;
    }
}

void insert_value_first(pnode *P, InfoList info, DataList type) {
    pnode newNode = alokasi(info, type);
    if (newNode != Nil){
        InsertFirst(&(*P), newNode);
    }
}


void insert_value_last(pnode *P, InfoList info, DataList type) {
    pnode newNode = alokasi(info, type);
    if (newNode != Nil) {
        InsertLast(&(*P), newNode);
    }
}

/*========================================================*/
/*================== DELETION FUNCTIONS ==================*/
/*========================================================*/

void delete_first(pnode *P, InfoList *info) {
    if (*P != Nil) {
        pnode temp = *P;
        
        if (info != NULL) {
            *info = temp->info;
        }
        
        *P = Next(temp);
        
        if (temp->type == TYPE_STRING) {
            info_string(temp) = Nil;
        }
        dealokasi(temp);
    }
}

void delete_last(pnode *P, InfoList *info){
    if (*P != Nil) {
        pnode last = *P;
        pnode prec = Nil;

        while (Next(last) != Nil) {
            prec = last;
            last = Next(last);
        }

        *info = last->info;
        if (prec == Nil) {
            *P = Nil;
        } else {
            Next(prec) = Nil;
        }
        
        if (last->type == TYPE_STRING){
            info_string(last) = Nil;
        }
        dealokasi(last);
    }
}

void delete_by_value(pnode *P, InfoList info, DataList type) {
    if (*P == NULL) return;

    pnode current = *P;
    pnode prev = NULL;

    while (current != NULL) {
        boolean match = false;
        switch (type) {
            case TYPE_INTEGER:
                match = (info_integer(current) == info.integer);
                break;
            case TYPE_STRING:
                match = (strcmp(info_string(current), info.str) == 0);
                break;
            case TYPE_JADWAL:
                match = compare_jadwal_value(info_jadwal(current), info.jadwal);
                break;
            case TYPE_EVENT:
                match = (info_event(current) == info.event);
                break;
            case TYPE_FILM:
                match = compare_film_value(info_film(current), info.film);
                break;
            case TYPE_RIWAYAT:
                match = (info_riwayat(current) == info.riwayat);
                break;
            default:
                return;
        }

        if (match) {
            if (prev == NULL) {
                *P = Next(current);
            } else {
                Next(prev) = Next(current);
            }
            if (current->type == TYPE_STRING) {
                free(info_string(current));
            }
            dealokasi(current);
            return;
        }
        prev = current;
        current = Next(current);
    }
}

void clear_list(pnode *P) {
    if (P == NULL || *P == NULL) {
        return;
    }
    
    InfoList dummy_info;
    
    while (*P != Nil) {
        delete_first(P, &dummy_info);
    }
    *P = Nil;
}

/*================================================================*/
/*================== COUNT AND SEARCH FUNCTIONS ==================*/
/*================================================================*/

int count_list(List L) {
    int count = 0;
    pnode P = First(L);
    
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    
    return count;
}

pnode search_by_value(pnode P, InfoList info) {
    while (P != Nil) {
        switch (P->type) 
        {
            case TYPE_INTEGER:
                if (info_integer(P) == info.integer) {
                    return P;
                }
                break;
            case TYPE_STRING:
                if (strcmp(info_string(P), info.str) == 0) {
                    return P;
                }
                break;
            default:
                break;
        }
        P = Next(P);
    }
    return Nil; // mereturn Nil jika tidak ditemukan
}

/*================================================================*/
/*===================== ADDITIONAL FUNCTIONS =====================*/
/*================================================================*/

pnode get_reverse_list(List L) {
    if (ListEmpty(L)) {
        return Nil;
    }
    
    pnode result = Nil;
    pnode P = First(L);
    pnode newNode;
    
    while (P != Nil) {
        pnode newNode = alokasi(P->info, P->type); 
        if (newNode != Nil) {
            InsertFirst(&result, newNode);
        }
        
        P = Next(P);
    }
    return result;
}


void reverse_list(List *L) {
    if (!ListEmpty(*L)) {
        pnode reversed = get_reverse_list(*L);
        
        // Hapus List yang belum di reverse
        clear_list(&First(*L));

        // set list dengan list yang sudah di reverse
        First(*L) = reversed;
    }
}

void copy_list(List L1, List *L2) {
    CreateList(L2);
    
    if (!ListEmpty(L1)) {
        pnode P = First(L1);
        
        while (P != Nil) {
            pnode newNode = alokasi(P->info, P->type); // Alokasikan node baru
            if (newNode != Nil) {
                InsertLast(&First(*L2), newNode); // Masukkan node baru ke list L2
            }
            P = Next(P);
        }
    }
}

boolean compare_list(List L1, List L2) {
    pnode p1 = First(L1);
    pnode p2 = First(L2);

    while (p1 != NULL && p2 != NULL) {
        if (p1->type != p2->type) {
            return false;
        }

        switch (p1->type) {
            case TYPE_INTEGER:
                if (info_integer(p1) != info_integer(p2)) return false;
                break;
            case TYPE_STRING:
                if (strcmp(info_string(p1), info_string(p2)) != 0) return false;
                break;
            case TYPE_JADWAL:
                if (!compare_jadwal_value(info_jadwal(p1), info_jadwal(p2))) return false;
                break;
            case TYPE_EVENT:
                if (info_event(p1) != info_event(p2)) return false;
                break;
            case TYPE_FILM:
                if (!compare_film_value(info_film(p1), info_film(p2))) return false;
                break;
            case TYPE_RIWAYAT:
                if (info_riwayat(p1) != info_riwayat(p2)) return false;
                break;
            default:
                return false;
        }
        p1 = Next(p1);
        p2 = Next(p2);
    }

    return (p1 == NULL && p2 == NULL);
}

InfoList get_front_value(List L) {
    InfoList result = {0}; 
    if (!ListEmpty(L)) {
        result = Info(First(L));
    }
    return result;
}

InfoList get_tail_value(List L) {
    InfoList result = {0}; 
    if (!ListEmpty(L)) {
        pnode P = First(L);
        while (Next(P) != NULL) {
            P = Next(P);
        }
        result = Info(P);
    }
    return result;
}
