#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdbool.h>
#include "data_struct/user.h"

typedef User* QueueData;

typedef struct QueueNode* Pqueue;
typedef struct QueueNode {
    QueueData data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;


void createPriorityQueue(Queue* q);

bool isPriorityQueueEmpty(const Queue* q);

void enqueuePriority(Queue* q, QueueData data);

QueueData dequeuePriority(Queue* q);

QueueData peekFrontPriority(const Queue* q);

int priorityQueueSize(const Queue* q);

void clearPriorityQueue(Queue* q);

#endif