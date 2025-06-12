/* 
	File name	: linked.c
  	Made by		: Muhammad Nabil Syauqi Rasyiq
   	Date		: 30 March 2025
  	Description	: Implementation of linked list supporting both int and char* types
*/

#include "linked.h"

/*========================================================*/
/*==================== MAIN FUNCTIONS ====================*/
/*========================================================*/

boolean isEmpty(pnode P) {
    return (P == Nil);
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

pnode alokasi(infotype info, DataType type) {
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
    if (P != Nil) {
        if (Type(P) == TYPE_STRING){
            if (info_string(P) != NULL) {
                free(info_string(P)); // mendealokasikan String literal
            }
        }
        Next(P) = Nil; // Pencegahan jiak next(P) belum Nil
        free(P);
    }
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

void insert_value_first(pnode *P, infotype info, DataType type) {
    pnode newNode = alokasi(info, type);
    if (newNode != Nil){
        InsertFirst(&(*P), newNode);
    }
}


void insert_value_last(pnode *P, infotype info, DataType type) {
    pnode newNode = alokasi(info, type);
    if (newNode != Nil) {
        InsertLast(&(*P), newNode);
    }
}

void insert_value_after(pnode *P, infotype before, infotype info, DataType type_before, DataType type_insert) {
    if (*P != Nil) {
        boolean found = false;
        pnode current = *P;
        while(current != Nil && !found) {
            if(current->type == type_before) {
                switch (type_before) {
                    case TYPE_INTEGER:
                        if (current->info.integer == before.integer) {
                            found = true;
                        }
                        break;
                        
                    case TYPE_STRING:
                        if (strcmp(current->info.str, before.str) == 0) {
                            found = true;
                        }
                        break;

                    case TYPE_JADWAL:
                        if (current->info.jadwal == before.jadwal) {
                            found = true;
                        }
                        break;
                    case TYPE_EVENT:
                        if (current->info.event == before.event) {
                            found = true;
                        }
                        break;
                    case TYPE_FILM:
                        if (current->info.film == before.film) {
                            found = true;
                        }
                        break;
                    default:
                        return;
                }
            }
            current = Next(current);
        }
        
        if (current != Nil) {
            pnode newNode = alokasi(info, type_insert);
            if (newNode != Nil) {
                InsertAfter(&current, newNode);
            }
        }
    }
}

void insert_value_before(pnode *P, infotype after, infotype info, DataType type_after, DataType type_insert) {
    if (*P != Nil) {
        boolean found = false;
        pnode current = *P;
        while(current != Nil && !found) {
            if(current->type == type_after) {
                switch (type_after) {
                    case TYPE_INTEGER:
                        if (current->info.integer == after.integer) {
                            found = true;
                        }
                        break;
                        
                    case TYPE_STRING:
                        if (strcmp(current->info.str, after.str) == 0) {
                            found = true;
                        }
                        break;

                    case TYPE_JADWAL:
                        if (current->info.jadwal == after.jadwal) {
                            found = true;
                        }
                        break;
                    case TYPE_EVENT:
                        if (current->info.event == after.event) {
                            found = true;
                        }
                        break;                    
                    case TYPE_FILM:
                        if (current->info.film == after.film) {
                            found = true;
                        }
                        break;                        
                    default:
                        return;
                }
            }
            current = Next(current);
        }
        
        if (current != Nil) { // Jika node After berhasil ditemukan
            pnode newNode = alokasi(info, type_insert);
            if (newNode != Nil) {
                InsertBefore(&current, P, newNode);
            }
        }
    }
}

/*========================================================*/
/*================== DELETION FUNCTIONS ==================*/
/*========================================================*/

void delete_first(pnode *P, infotype *info) {
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

void delete_last(pnode *P, infotype *info){
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

void delete_by_value(pnode *P, infotype info, DataType type) {
    pnode head = *P;
    pnode temp;
        
    switch (type) {
        case TYPE_INTEGER:
            while (head != Nil && info_integer(Next(head)) != info.integer) {
                head = Next(head);
            }
            break;
                
        case TYPE_STRING:
            while (head != Nil && strcmp(info_string(Next(head)), info.str) != 0) {
                head = Next(head);
            }
            break;
        
        case TYPE_JADWAL:
            while (head != Nil && info_jadwal(Next(head)) != info.jadwal) {
                head = Next(head);
            }
            break;

        case TYPE_EVENT:
            while (head != Nil && info_event(Next(head)) != info.event) {
                head = Next(head);
            }
            break;
        case TYPE_FILM:
            while (head != Nil && info_film(Next(head)) != info.film) {
                head = Next(head);
            }
            break;        
        default:
            return;
    }
    temp = Next(head);
    Next(head) = Next(temp);
    if (temp != Nil) {
        if (temp->type == TYPE_STRING){
            info_string(temp) = Nil;
        }
        dealokasi(temp);
    }
}

void clear_list(pnode *P) {
    if (P == NULL || *P == NULL) {
        return;
    }
    
    infotype dummy_info;
    
    while (*P != Nil) {
        delete_first(P, &dummy_info);
    }
    *P = Nil;
}

/*=======================================================*/
/*================== DISPLAY FUNCTIONS ==================*/
/*=======================================================*/

void print_info(pnode P) {
    if (P != Nil) {
        switch (P->type)
        {
            case TYPE_INTEGER:
                printf("%d", info_integer(P));
                break;

            case TYPE_STRING:
                printf("%s", info_string(P));
                break;
            
            default:
                return;
        }
    }
}

void print_list(List L) {
    if (ListEmpty(L)) {
        printf("List Kosong\n");
    } else {
        pnode P = First(L);
        while (P != Nil) {
            print_info(P);
            P = Next(P);
            if (P != Nil) {
                printf(" -> ");
            }
        }
        printf("\n");
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

pnode search_prec(List L, infotype info) {
    if (ListEmpty(L)) {
        return Nil;
    }
    
    pnode P = First(L);
    switch (P->type)
    {
        case TYPE_INTEGER:
            if (info_integer(P) == info.integer) 
            {
                return Nil;
            }
            break;
        case TYPE_STRING:
            if (strcmp(info_string(P), info.str) == 0) 
            {
                return Nil;
            }
            break;
        case TYPE_JADWAL:
            if (1)
            {

            }
            break;
        case TYPE_EVENT:
            if (1)
            {

            }
            break;
        case TYPE_FILM:
            if (1)
            {

            }
            break;
        default:
            break;
    }
    while (Next(P) != Nil) {
        switch (Next(P)->type) 
        {
            case TYPE_INTEGER:
                if (info_integer(Next(P)) == info.integer) {
                    return P;
                }
                break;
            case TYPE_STRING:
                if (strcmp(info_string(Next(P)), info.str) == 0) {
                    return P;
                }
                break;
            default:
                break;
        }
        P = Next(P);
    }
    
    return Nil;
}

pnode search_by_value(pnode P, infotype info) {
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

infotype get_front_value(List L) {
    if (ListEmpty(L)) {
        return; 
    }
    pnode P = First(L);
    return Info(P); 
}

infotype get_tail_value(List L) {
    if (ListEmpty(L)) {
        return;
    }
    pnode P = First(L);
    while (Next(P) != Nil) {
        P = Next(P);
    }
    return Info(P);
}
