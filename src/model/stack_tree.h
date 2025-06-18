#ifndef STACKTREE_H
#define STACKTREE_H
#include "tree_data.h"
#include <stdlib.h>  

typedef struct StackNode {
    address node;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} StackTree;

void init_stack(StackTree* stack);

bool is_empty_stack(StackTree* stack);

void push_stack(StackTree* stack, address node);

address pop_stack(StackTree* stack);

address peek_stack(StackTree* stack);

void free_stack(StackTree* stack);

void traverse_print_tree_stack_adt(address root);

#endif



