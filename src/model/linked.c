#include "linked.h"

/*========================================================*/
/*==================== MAIN FUNCTIONS ====================*/
/*========================================================*/

boolean isEmpty(pnode P) {
    return (P == Nil);
}

boolean is_valid_type(DataList type) {
    return (type >= TYPE_INTEGER && type <= TYPE_FILM);
}

boolean ListEmpty(List L) {
    return (First(L) == Nil);   
}

void Createpnode(pnode *P) {
    *P = Nil;
}

void CreateList(List *L) {
    First(*L) = NULL;
}

InfoList copy_info(InfoList src, DataList type) {
    InfoList dest;
    switch (type) {
        case TYPE_STRING:
            dest.str = strdup(src.str);
            break;
        case TYPE_JADWAL:
            dest.jadwal = deep_copy_jadwal(src.jadwal);
            break;
        case TYPE_EVENT:
            dest.event = deep_copy_event(src.event);
            break;
        case TYPE_FILM:
            dest.film = deep_copy_film(src.film);
            break;
        default:
            dest = src;
    }
    return dest;
}

pnode alokasi(InfoList info, DataList type) {
    if (!is_valid_type(type)) return Nil;
    pnode new_node = (pnode)malloc(sizeof(node));
    if (new_node == Nil) return Nil;

    new_node->type = type;
    new_node->info = copy_info(info, type);
    Next(new_node) = Nil;

    return new_node;
}

void dealokasi(pnode P) {
    if (P == NULL) return;

    switch (P->type) {
        case TYPE_STRING:
            free(info_string(P));
            break;
        case TYPE_JADWAL:
            if (info_jadwal(P)) destructor_jadwal(info_jadwal(P));
            break;
        case TYPE_EVENT:
            if (info_event(P)) destructor_event(info_event(P));
            break;
        case TYPE_FILM:
            if (info_film(P)) destroy_film(info_film(P));
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
        while (Next(last) != Nil) {
            last = Next(last);
        }
        Next(last) = newNode;
    }
}

void InsertAfter(pnode *pBef, pnode PNew) {
    Next(PNew) = Next(*pBef);
    Next(*pBef) = PNew;
}

void InsertBefore(pnode *head, pnode pAft, pnode PNew) {
    if (*head == pAft) {
        PNew->next = pAft;
        *head = PNew;
        return;
    }
    pnode prev = *head;
    while (prev && Next(prev) != pAft) {
        prev = Next(prev);
    }
    if (prev) {
        Next(PNew) = pAft;
        Next(prev) = PNew;
    }
}

void insert_value_first(pnode *P, InfoList info, DataList type) {
    pnode newNode = alokasi(info, type);
    if (newNode != Nil){
        InsertFirst(P, newNode);
    }
}

void insert_value_last(pnode *P, InfoList info, DataList type) {
    pnode newNode = alokasi(info, type);
    if (newNode != Nil) {
        InsertLast(P, newNode);
    }
}

void insert_value_after(pnode *P, InfoList before, InfoList info, DataList type_before, DataList type_insert) {
    pnode target = search_by_value(*P, before);
    if (target != Nil && target->type == type_before) {
        pnode newNode = alokasi(info, type_insert);
        if (newNode != Nil) {
            InsertAfter(&target, newNode);
        }
    }
}

/*========================================================*/
/*================== DELETION FUNCTIONS ==================*/
/*========================================================*/

void delete_first(pnode *P, InfoList *info) {
    if (*P != Nil) {
        pnode temp = *P;
        if (info != NULL) {
            *info = copy_info(temp->info, temp->type);
        }
        *P = Next(temp);
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

        if (info) *info = copy_info(last->info, last->type);

        if (prec == Nil) {
            *P = Nil;
        } else {
            Next(prec) = Nil;
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
        if (current->type != type) {
            current = Next(current);
            continue;
        }
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
                match = compare_event(info_event(current), info.event);
                break;
            case TYPE_FILM:
                match = compare_film_value(info_film(current), info.film);
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
            dealokasi(current);
            return;
        }
        prev = current;
        current = Next(current);
    }
}

void clear_list(pnode *P) {
    InfoList dummy_info;
    while (*P != Nil) {
        delete_first(P, &dummy_info);
    }
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
        if (!is_valid_type(P->type)) {
            P = Next(P);
            continue;
        } 
        switch (P->type) {
            case TYPE_INTEGER:
                if (info_integer(P) == info.integer) return P;
                break;
            case TYPE_STRING:
                if (strcmp(info_string(P), info.str) == 0) return P;
                break;
            case TYPE_JADWAL:
                if (compare_jadwal_value(info_jadwal(P), info.jadwal)) return P;
                break;
            case TYPE_EVENT:
                if (compare_event(info_event(P), info.event)) return P;
                break;
            case TYPE_FILM:
                if (compare_film_value(info_film(P), info.film)) return P;
                break;
        }
        P = Next(P);
    }
    return Nil;
}

/*================================================================*/
/*===================== ADDITIONAL FUNCTIONS =====================*/
/*================================================================*/

pnode get_reverse_list(List L) {
    if (ListEmpty(L)) return Nil;

    pnode result = Nil;
    pnode P = First(L);
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
        clear_list(&First(*L));
        First(*L) = reversed;
    }
}

void copy_list(List L1, List *L2) {
    CreateList(L2);
    if (!ListEmpty(L1)) {
        pnode P = First(L1);
        while (P != Nil) {
            pnode newNode = alokasi(P->info, P->type);
            if (newNode != Nil) {
                InsertLast(&First(*L2), newNode);
            }
            P = Next(P);
        }
    }
}

boolean compare_list(List L1, List L2) {
    pnode p1 = First(L1);
    pnode p2 = First(L2);

    while (p1 != NULL && p2 != NULL) {
        if (p1->type != p2->type) return false;

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
                if (!compare_event(info_event(p1), info_event(p2))) return false;
                break;
            case TYPE_FILM:
                if (!compare_film_value(info_film(p1), info_film(p2))) return false;
                break;
            default:
                return false;
        }
        p1 = Next(p1);
        p2 = Next(p2);
    }
    return (p1 == NULL && p2 == NULL);
}

void merge_list(List* L1, List L2) {
    pnode P = First(L2);
    while (P != NULL) {
        pnode newNode = alokasi(P->info, P->type);
        if (newNode) {
            InsertLast(&First(*L1), newNode);
        }
        P = Next(P);
    }
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
