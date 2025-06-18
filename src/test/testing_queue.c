#include "testing_queue.h"

void test_create_and_empty_queue() {
    PriorityQueue q;
    createPriorityQueue(&q);
    assert(isPriorityQueueEmpty(&q) == true);
    assert(priorityQueueSize(&q) == 0);
    assert(peekFrontPriority(&q) == NULL);
    printf("Test create and empty queue: PASSED\n");
}

void test_enqueue_and_dequeue_single_user() {
    PriorityQueue q;
    createPriorityQueue(&q);
    
    User* user = create_user("testuser", "pass", REGULER);
    enqueuePriority(&q, user);
    
    assert(priorityQueueSize(&q) == 1);
    assert(isPriorityQueueEmpty(&q) == false);
    assert(peekFrontPriority(&q) == user);
    assert(get_username_user(peekFrontPriority(&q)) == get_username_user(user));
    
    User* dequeued = dequeuePriority(&q);
    assert(dequeued == user);
    assert(priorityQueueSize(&q) == 0);
    assert(isPriorityQueueEmpty(&q) == true);
    
    destroy_user(user);
    printf("Test enqueue and dequeue single user: PASSED\n");
}

void test_priority_order() {
    PriorityQueue q;
    createPriorityQueue(&q);
    
    User* user_reg = create_user("reg_user", "pass1", REGULER);
    User* user_vip1 = create_user("vip1_user", "pass2", VIP_1);
    User* user_vip2 = create_user("vip2_user", "pass3", VIP_2);
    
    // Enqueue in mixed order
    enqueuePriority(&q, user_reg);
    enqueuePriority(&q, user_vip2);
    enqueuePriority(&q, user_vip1);
    
    assert(priorityQueueSize(&q) == 3);
    
    // Dequeue should return users in priority order: VIP_2, VIP_1, REGULER
    User* first = dequeuePriority(&q);
    assert(first == user_vip2);
    assert(get_prioritas_user(first) == VIP_2);
    
    User* second = dequeuePriority(&q);
    assert(second == user_vip1);
    assert(get_prioritas_user(second) == VIP_1);
    
    User* third = dequeuePriority(&q);
    assert(third == user_reg);
    assert(get_prioritas_user(third) == REGULER);
    
    assert(isPriorityQueueEmpty(&q) == true);
    
    destroy_user(user_reg);
    destroy_user(user_vip1);
    destroy_user(user_vip2);
    printf("Test priority order: PASSED\n");
}

void test_enqueue_multiple_same_priority() {
    PriorityQueue q;
    createPriorityQueue(&q);
    
    User* user1 = create_user("user1", "pass1", VIP_1);
    User* user2 = create_user("user2", "pass2", VIP_1);
    User* user3 = create_user("user3", "pass3", VIP_1);
    
    enqueuePriority(&q, user1);
    enqueuePriority(&q, user2);
    enqueuePriority(&q, user3);
    
    assert(priorityQueueSize(&q) == 3);
    
    // Dequeue should maintain FIFO order for same priority
    assert(dequeuePriority(&q) == user1);
    assert(dequeuePriority(&q) == user2);
    assert(dequeuePriority(&q) == user3);
    
    assert(isPriorityQueueEmpty(&q) == true);
    
    destroy_user(user1);
    destroy_user(user2);
    destroy_user(user3);
    printf("Test multiple same priority: PASSED\n");
}

void test_clear_queue() {
    PriorityQueue q;
    createPriorityQueue(&q);
    
    User* user1 = create_user("user1", "pass1", REGULER);
    User* user2 = create_user("user2", "pass2", VIP_1);
    
    enqueuePriority(&q, user1);
    enqueuePriority(&q, user2);
    
    assert(priorityQueueSize(&q) == 2);
    
    clearPriorityQueue(&q, destroy_user);
    assert(isPriorityQueueEmpty(&q) == true);
    assert(priorityQueueSize(&q) == 0);
    assert(peekFrontPriority(&q) == NULL);
    
    printf("Test clear queue: PASSED\n");
}

void test_dequeue_empty_queue() {
    PriorityQueue q;
    createPriorityQueue(&q);
    
    assert(dequeuePriority(&q) == NULL);
    assert(priorityQueueSize(&q) == 0);
    printf("Test dequeue empty queue: PASSED\n");
}

void testing_queue() {
    printf("Running PriorityQueue tests...\n");
    test_create_and_empty_queue();
    test_enqueue_and_dequeue_single_user();
    test_priority_order();
    test_enqueue_multiple_same_priority();
    test_clear_queue();
    test_dequeue_empty_queue();
    printf("All tests PASSED!\n");
}