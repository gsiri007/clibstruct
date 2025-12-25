#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "singlylinkedlist.h"

void test_create() {
    printf("Running test_create...\n");
    sll_t *list = sll_create_linked_list();
    assert(list != NULL);
    assert(sll_get_length(list) == 0);
    // Since we don't have a destroy function, we assume the test environment cleans up 
    // or we accept the leak for the test duration.
    free(list); 
    printf("Passed.\n");
}

void test_add_and_delete_head() {
    printf("Running test_add_and_delete_head...\n");
    sll_t *list = sll_create_linked_list();
    
    // Add 10
    assert(sll_add_head_node(list, (void *)10) == 0);
    assert(sll_get_length(list) == 1);
    
    // Add 20
    assert(sll_add_head_node(list, (void *)20) == 0);
    assert(sll_get_length(list) == 2);

    // Should be 20 -> 10
    void *val = sll_delete_head_node(list);
    assert(val == (void *)20);
    assert(sll_get_length(list) == 1);

    val = sll_delete_head_node(list);
    assert(val == (void *)10);
    assert(sll_get_length(list) == 0);
    
    // Delete from empty
    val = sll_delete_head_node(list);
    assert(val == NULL);

    free(list);
    printf("Passed.\n");
}

void test_add_and_delete_tail() {
    printf("Running test_add_and_delete_tail...\n");
    sll_t *list = sll_create_linked_list();
    
    // Add 10
    assert(sll_add_tail_node(list, (void *)10) == 0);
    assert(sll_get_length(list) == 1);
    
    // Add 20
    assert(sll_add_tail_node(list, (void *)20) == 0);
    assert(sll_get_length(list) == 2);
    
    // Should be 10 -> 20
    
    void *val = sll_delete_tail_node(list);
    assert(val == (void *)20);
    assert(sll_get_length(list) == 1);
    
    val = sll_delete_tail_node(list);
    assert(val == (void *)10);
    assert(sll_get_length(list) == 0);
    
    assert(sll_delete_tail_node(list) == NULL);
    
    free(list);
    printf("Passed.\n");
}

void test_insert_and_delete_pos() {
    printf("Running test_insert_and_delete_pos...\n");
    sll_t *list = sll_create_linked_list();
    
    // Insert into empty list at 0
    assert(sll_insert_node(list, 0, (void *)10) == 0); // [10]
    assert(sll_get_length(list) == 1);
    
    // Insert at end (index 1)
    assert(sll_insert_node(list, 1, (void *)30) == 0); // [10, 30]
    
    // Insert in middle (index 1)
    assert(sll_insert_node(list, 1, (void *)20) == 0); // [10, 20, 30]
    
    assert(sll_get_length(list) == 3);
    
    // Test out of bounds
    assert(sll_insert_node(list, 5, (void *)99) == 1); // Should fail
    assert(sll_get_length(list) == 3);
    
    // Delete middle (index 1, value 20)
    void *val = sll_delete_node(list, 1);
    assert(val == (void *)20);
    assert(sll_get_length(list) == 2); // [10, 30]
    
    // Delete head via pos 0
    val = sll_delete_node(list, 0);
    assert(val == (void *)10);
    assert(sll_get_length(list) == 1); // [30]
    
    // Delete tail via pos 0 (since length is 1)
    val = sll_delete_node(list, 0); 
    assert(val == (void *)30);
    assert(sll_get_length(list) == 0);
    
    free(list);
    printf("Passed.\n");
}

void test_reverse() {
    printf("Running test_reverse...\n");
    sll_t *list = sll_create_linked_list();
    
    sll_add_tail_node(list, (void *)1);
    sll_add_tail_node(list, (void *)2);
    sll_add_tail_node(list, (void *)3);
    // 1 -> 2 -> 3
    
    assert(sll_reverse_linked_list(list) == 0);
    // 3 -> 2 -> 1
    
    assert(sll_delete_head_node(list) == (void *)3);
    assert(sll_delete_head_node(list) == (void *)2);
    assert(sll_delete_head_node(list) == (void *)1);
    
    // Test reversing empty list (should fail per implementation)
    assert(sll_reverse_linked_list(list) == 1);
    
    free(list);
    printf("Passed.\n");
}

int main(void) {
    test_create();
    test_add_and_delete_head();
    test_add_and_delete_tail();
    test_insert_and_delete_pos();
    test_reverse();
    printf("All tests passed successfully.\n");
    return 0;
}