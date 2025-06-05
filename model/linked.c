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

boolean isEmpty(address P) {
    return (P == Nil);
}

boolean ListEmpty(List L) {
    return (First(L) == Nil);
}

void CreateAddress(address *P) {
    *P = Nil;
}

void CreateList(List *L) {
    First(*L) = Nil;
}


address alokasi(infotype info, DataType type) {
    address P = (address) malloc(sizeof(ElmtList));
    switch (type)
    {
        case TYPE_INTEGER:
            if (P != Nil) {
                info_integer(P) = info.integer;
                Next(P) = Nil;
            }
            return P;
        case TYPE_STRING:
            if (P != Nil) {
                info_string(P) = strdup(info.str); // Deep copy menggunakan strdup
                if (info_string(P) == NULL) {
                    free(P); // mendealokasikan node bila gagal mengcopy string
                    return Nil;
                }
                Next(P) = Nil;
            }
            return P;
        default:
            return Nil;
    }
}

void dealokasi(address P) {
    if (P != Nil) {
        if(Type(P) == TYPE_STRING){
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

void InsertFirst(address *P, address newNode) {
    Next(newNode) = *P;
    *P = newNode;
}

void InsertLast(address *P, address newNode) {
    if (*P == Nil) {
        *P = newNode;
    } else {
        address last = *P;
        while (next(last) != Nil) {
            last = next(last);
        }
        Next(last) = newNode;
    }
}

void InsertAfter(address *pBef, address PNew) {
    Next(PNew) = next(*pBef);
    Next(*pBef) = PNew;
}

void InsertBefore(address *pAft, address *p, address PNew) {
    
    if (*pAft == *p) {
    	// jika pAft elemen pertama
        Next(PNew) = *p;
        *p = PNew;
    } else {
        address prev = *p;
        while (Next(prev) != *pAft) {
            prev = Next(prev);
        }
        Next(PNew) = *pAft;
        Next(prev) = PNew;
    }
}

void insert_value_first(address *P, infotype info, DataType type) {
    address newNode = alokasi(info, type);
    if (newNode != Nil){
        InsertFirst(&(*P), newNode);
    }
}


void insert_value_last(address *P, infotype info, DataType type) {
    address newNode = alokasi(info, type);
    if (newNode != Nil) {
        InsertLast(&(*P), newNode);
    }
}

void insert_value_after(address *P, infotype before, infotype info, DataType type_before, DataType type_insert) {
    if (*P != Nil) {
        boolean found = false;
        address current = *P;
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
                        
                    default:
                        return;
                }
            }
            current = Next(current);
        }
        
        if (current != Nil) { // Jika node After berhasil ditemukan
            address newNode = alokasi(info, type_insert);
            if (newNode != Nil) {
                InsertAfter(&current, newNode);
            }
        }
    }
}

void insert_value_before(address *P, infotype after, infotype info, DataType type_after, DataType type_insert) {
    if (*P != Nil) {
        boolean found = false;
        address current = *P;
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
                        
                    default:
                        return;
                }
            }
            current = Next(current);
        }
        
        if (current != Nil) { // Jika node After berhasil ditemukan
            address newNode = alokasi(info, type_insert);
            if (newNode != Nil) {
                InsertBefore(&current, P, newNode);
            }
        }
    }
}

/*========================================================*/
/*================== DELETION FUNCTIONS ==================*/
/*========================================================*/

void delete_first(address *P, infotype *info) {
    if (*P != Nil) {
        address temp = *P;
        
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

void delete_last(address *P, infotype *info){
    if (*P != Nil) {
        address last = *P;
        address prec = Nil;

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

void delete_by_value(address *P, infotype info, DataType type) {
    address head = *P;
    address temp;
        
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

void clear_list(address *P) {
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

void print_info(address P) {
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
        address P = First(L);
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
    address P = First(L);
    
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    
    return count;
}

address search_prec(List L, infotype info) {
    if (ListEmpty(L)) {
        return Nil;
    }
    
    address P = First(L);
    switch (P->type)
    {
        case TYPE_INTEGER:
            if (info_integer(P) == info.integer) {
                return Nil;
            }
            break;
        case TYPE_STRING:
            if (strcmp(info_string(P), info.str) == 0) {
                return Nil;
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

address search_by_value(address P, infotype info) {
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

address get_reverse_list(List L) {
    if (ListEmpty(L)) {
        return Nil;
    }
    
    address result = Nil;
    address P = First(L);
    address newNode;
    
    while (P != Nil) {
        address newNode = alokasi(P->info, P->type); 
        if (newNode != Nil) {
            InsertFirst(&result, newNode);
        }
        
        P = Next(P);
    }
    return result;
}


void reverse_list(List *L) {
    if (!ListEmpty(*L)) {
        address reversed = get_reverse_list(*L);
        
        // Hapus List yang belum di reverse
        clear_list(&First(*L));

        // set list dengan list yang sudah di reverse
        First(*L) = reversed;
    }
}

void copy_list(List L1, List *L2) {
    CreateList(L2);
    
    if (!ListEmpty(L1)) {
        address P = First(L1);
        
        while (P != Nil) {
            address newNode = alokasi(P->info, P->type); // Alokasikan node baru
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
    address P = First(L);
    return Info(P); 
}

infotype get_tail_value(List L) {
    if (ListEmpty(L)) {
        return;
    }
    address P = First(L);
    while (Next(P) != Nil) {
        P = Next(P);
    }
    return Info(P);
}
