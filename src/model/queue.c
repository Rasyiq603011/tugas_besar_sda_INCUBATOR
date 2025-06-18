#include "queue.h"
#include <stdio.h>

void createPriorityQueue(Queue* q) 
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool isPriorityQueueEmpty(const Queue* q)
{
    return q->size == 0;
}

void enqueuePriority(Queue* q, QueueData data) {
    Pqueue newNode = (Pqueue) malloc(sizeof(QueueNode));
    if (!newNode) return;

    newNode->data = data;
    newNode->next = NULL;

    if (isPriorityQueueEmpty(q)) 
    {
        q->front = q->rear = newNode;
        q->size++;
        return;
    }

    Prioritas newPriority = get_prioritas_user(data);
    Pqueue curr = q->front;
    Pqueue prev = NULL;

    while (curr != NULL && get_prioritas_user(curr->data) >= newPriority) 
    {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) 
    { // Insert at front
        newNode->next = q->front;
        q->front = newNode;
    } else 
    { // Insert after prev
        newNode->next = prev->next;
        prev->next = newNode;
        if (newNode->next == NULL) 
        {
            q->rear = newNode;
        }
    }
    q->size++;
}

QueueData dequeuePriority(Queue* q) 
{
    if (isPriorityQueueEmpty(q)) return NULL;

    QueueNode* temp = q->front;
    QueueData data = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) 
    {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return data;
}

QueueData peekFrontPriority(const Queue* q) 
{
    return (q->front != NULL) ? q->front->data : NULL;
}

int priorityQueueSize(const Queue* q) 
{
    return q->size;
}

void clearPriorityQueue(Queue* q, void (*destroy)(QueueData)) 
{
    while (!isPriorityQueueEmpty(q)) {
        QueueData data = dequeuePriority(q);
        if (destroy) destroy(data);
    }
}

