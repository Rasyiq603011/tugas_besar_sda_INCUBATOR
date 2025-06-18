#ifndef TESTING_QUEUE_H
#define TESTING_QUEUE_H
#include <assert.h>
#include <stdio.h>
#include "../model/queue.h"

void test_create_and_empty_queue();

void test_enqueue_and_dequeue_single_user();

void test_priority_order();

void test_enqueue_multiple_same_priority();

void test_clear_queue();

void test_dequeue_empty_queue();

void testing_queue();


#endif