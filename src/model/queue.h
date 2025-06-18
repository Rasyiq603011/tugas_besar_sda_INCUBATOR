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

// Membuat PriorityQueue kosong
void createQueue(Queue* q);

// Mengembalikan true jika Queue kosong
bool isQueueEmpty(const Queue* q);

// Menambahkan elemen ke Queue berdasarkan prioritas
void enqueue(Queue* q, QueueData data);

// Menghapus elemen dari depan Queue dan mengembalikannya
QueueData dequeue(Queue* q);

// Mengakses data di depan Queue tanpa menghapusnya
QueueData peekFront(const Queue* q);

// Mendapatkan ukuran Queue
int QueueSize(const Queue* q);

// Menghapus seluruh isi Queue
void clearQueue(Queue* q, void (*destroy)(QueueData));

#endif