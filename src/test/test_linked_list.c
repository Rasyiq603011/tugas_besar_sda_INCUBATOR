#include "test_linked_list.h"

void test_insert_delete_string() {
    List L;
    CreateList(&L);
    InfoList info;
    info.str = strdup("Cinematique");
    insert_value_first(&First(L), info, TYPE_STRING);
    assert(count_list(L) == 1);

    InfoList result;
    delete_first(&First(L), &result);
    assert(strcmp(result.str, "Cinematique") == 0);
    free(result.str);
    assert(ListEmpty(L));
}

void test_reverse_and_copy_list() {
    List L1, L2, L3;
    CreateList(&L1);

    InfoList i1 = {.integer = 10}, i2 = {.integer = 20}, i3 = {.integer = 30};
    insert_value_last(&First(L1), i1, TYPE_INTEGER);
    insert_value_last(&First(L1), i2, TYPE_INTEGER);
    insert_value_last(&First(L1), i3, TYPE_INTEGER);

    copy_list(L1, &L2);
    assert(compare_list(L1, L2));

    reverse_list(&L1);
    copy_list(L1, &L3);
    assert(count_list(L3) == 3);

    clear_list(&First(L1));
    clear_list(&First(L2));
    clear_list(&First(L3));
}

void test_delete_by_value() {
    List L;
    CreateList(&L);
    InfoList info1 = {.integer = 42}, info2 = {.integer = 99};
    insert_value_last(&First(L), info1, TYPE_INTEGER);
    insert_value_last(&First(L), info2, TYPE_INTEGER);
    assert(count_list(L) == 2);

    delete_by_value(&First(L), info1, TYPE_INTEGER);
    assert(count_list(L) == 1);

    delete_by_value(&First(L), info2, TYPE_INTEGER);
    assert(ListEmpty(L));
}

void linked_testing() {
    printf("Running unit tests...\n");
    test_insert_delete_string();
    printf("✓ test_insert_delete_string passed.\n");

    test_reverse_and_copy_list();
    printf("✓ test_reverse_and_copy_list passed.\n");

    test_delete_by_value();
    printf("✓ test_delete_by_value passed.\n");

    printf("All tests passed successfully.\n");
}
