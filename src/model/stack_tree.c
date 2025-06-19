#include "stack_tree.h"

void init_stack(StackTree* stack) {
    stack->top = NULL;
}

bool is_empty_stack(StackTree* stack) {
    return stack->top == NULL;
}

void push_stack(StackTree* stack, address node) {
    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
    if (!newNode) return;
    newNode->node = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

address pop_stack(StackTree* stack) {
    if (is_empty_stack(stack)) return NULL;
    StackNode* temp = stack->top;
    address node = temp->node;
    stack->top = temp->next;
    free(temp);
    return node;
}

address peek_stack(StackTree* stack) {
    if (is_empty_stack(stack)) return NULL;
    return stack->top->node;
}

void free_stack(StackTree* stack) {
    while (!is_empty_stack(stack)) {
        pop_stack(stack);
    }
}

void traverse_print_tree_stack_adt(address root)
{
    if (!root) return;

    StackTree stack;
    init_stack(&stack);
    push_stack(&stack, root);

    while (!is_empty_stack(&stack)) 
    {
        address current = pop_stack(&stack);

        switch (current->tipe) 
        {
            case TYPE_NEGARA:
                printf("Negara: %s\n", get_name_negara(current->info.negara));
                break;
            case TYPE_PROVINSI:
                printf("  Provinsi: %s\n", get_name_provinsi(current->info.provinsi));
                break;
            case TYPE_KOTA:
                printf("    Kota: %s\n", get_name_kota(current->info.kota));
                break;
            case TYPE_BIOSKOP:
                printf("      Bioskop: %s\n", get_name_bioskop(current->info.bioskop));
                break;
            case TYPE_STUDIO:
                printf("        Studio: %s\n", get_name_studio(current->info.studio));
                break;
        }

        address sibling = current->next_brother;
        while (sibling) 
        {
            push_stack(&stack, sibling);
            sibling = sibling->next_brother;
        }

        if (current->first_son) 
        {
            push_stack(&stack, current->first_son);
        }
    }

    free_stack(&stack);
}

List* get_all_jadwal_by_film_from_node(address node_mulai, const char* keyword) 
{
    if (!node_mulai || !keyword) return NULL;

    List* hasil;
    CreateList(hasil);  
    StackTree stack;
    init_stack(&stack);
    push_stack(&stack, node_mulai);

    while (!is_empty_stack(&stack)) {
        address current = pop_stack(&stack);

        if (current->tipe == TYPE_STUDIO) {
            Studio* studio = info_studio(current);
            List* new_list_jadwal = get_jadwal_by_film(studio, keyword);

            if (new_list_jadwal && new_list_jadwal->First) {
                merge_list(hasil, new_list_jadwal);
            } else {
                clear_list(&(new_list_jadwal->First));
                free(new_list_jadwal);
            }
        }

        if (current->next_brother) push_stack(&stack, current->next_brother);
        if (current->first_son) push_stack(&stack, current->first_son);
    }

    free_stack(&stack);
    return hasil;
}

List* get_all_event_from_tree_node(address node_mulai) 
{
    if (!node_mulai) return NULL;

    List* hasil;
    CreateList(hasil);  
    StackTree stack;
    init_stack(&stack);
    push_stack(&stack, node_mulai);

    while (!is_empty_stack(&stack)) {
        address current = pop_stack(&stack);

        if (current->tipe == TYPE_STUDIO) {
            Studio* studio = info_studio(current);
            List* new_list_event = get_all_event(studio);

            if (new_list_event && new_list_event->First) 
            {
                merge_list(hasil, new_list_event);
            } else {
                clear_list(&(new_list_event->First));
                free(new_list_event);
            }
        }

        if (current->next_brother) push_stack(&stack, current->next_brother);
        if (current->first_son) push_stack(&stack, current->first_son);
    }

    free_stack(&stack);
    return hasil;
}
