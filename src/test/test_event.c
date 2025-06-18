#include "test_event.h"

void destroyString(void* data) {
    free(data); 
}

void testing_queue() {
    PriorityQueue q;
    createQueue(&q);

    char* str1 = strdup("Halo");
    char* str2 = strdup("Dunia");
    enqueue(&q, str1);
    enqueue(&q, str2);

    printf("Isi Awal Queue:\n");
    printf("%s\n", (char*)peekFront(&q));

    while (!isQueueEmpty(&q)) {
        char* data = (char*)dequeue(&q);
        printf("Dequeued: %s\n", data);
        free(data); 
    }

    return 0;
}

