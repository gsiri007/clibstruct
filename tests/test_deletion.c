#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "singlylinkedlist.h"


// Test function declarations (now called by a central runner)
void test_delete_end_node_empty();
void test_delete_end_node_single_node();
void test_delete_end_node_multiple_nodes();
void test_delete_end_node_multiple_nodes_after_deletion();
void test_delete_node_empty_list();
void test_delete_node_single_node();
void test_delete_node_first_node();
void test_delete_node_middle_node();
void test_delete_node_last_node();
void test_delete_node_out_of_bounds();

// Function to run all deletion-related tests
void run_deletion_tests() {
    printf("\n--- Running Singly Linked List Deletion Tests ---\n");
    test_delete_end_node_empty();
    test_delete_end_node_single_node();
    test_delete_end_node_multiple_nodes();
    test_delete_end_node_multiple_nodes_after_deletion();
    
    printf("\n--- Running sll_delete_node Tests ---\n");
    test_delete_node_empty_list();
    test_delete_node_single_node();
    test_delete_node_first_node();
    test_delete_node_middle_node();
    test_delete_node_last_node();
    test_delete_node_out_of_bounds();
    
    printf("--- All Deletion Tests Completed ---\n");
}

void test_delete_end_node_empty() {
    printf("  - Testing sll_delete_end_node (empty list)...");
    sll_node_t *head = NULL;
    void *data = sll_delete_end_node(&head);
    assert(data == NULL); // Should fail on an empty list
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_delete_end_node_single_node() {
    printf("  - Testing sll_delete_end_node (single node)...");
    sll_node_t *head = NULL;
    int *value = malloc(sizeof(int));
    *value = 10;
    sll_add_end_node(value, &head);
    assert(head != NULL);
    assert(sll_size_linked_list(head) == 1);

    void *data = sll_delete_end_node(&head);
    assert(data == value);
    assert(head == NULL); // Head should be NULL after deletion
    assert(sll_size_linked_list(head) == 0);
    free(data);
    printf(" PASSED\n");
}

void test_delete_end_node_multiple_nodes() {
    printf("  - Testing sll_delete_end_node (multiple nodes)...");
    sll_node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    int *value3 = malloc(sizeof(int)); *value3 = 30;
    sll_add_end_node(value1, &head);
    sll_add_end_node(value2, &head);
    sll_add_end_node(value3, &head);
    assert(sll_size_linked_list(head) == 3);
    assert(head->data == value1);
    assert(head->next->data == value2);
    assert(head->next->next->data == value3);

    void *data = sll_delete_end_node(&head);
    assert(data == value3);
    assert(head != NULL);
    assert(sll_size_linked_list(head) == 2);
    assert(head->data == value1);
    assert(head->next->data == value2);
    assert(head->next->next == NULL); // New end node
    free(data);
    
    // Clean up
    while (head != NULL) {
        free(sll_delete_begin_node(&head));
    }
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_delete_end_node_multiple_nodes_after_deletion() {
    printf("  - Testing sll_delete_end_node (multiple nodes, sequential deletions)...");
    sll_node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    int *value3 = malloc(sizeof(int)); *value3 = 30;
    int *value4 = malloc(sizeof(int)); *value4 = 40;
    sll_add_end_node(value1, &head);
    sll_add_end_node(value2, &head);
    sll_add_end_node(value3, &head);
    sll_add_end_node(value4, &head);
    assert(sll_size_linked_list(head) == 4);

    void *data = sll_delete_end_node(&head); // Delete 40
    assert(data == value4);
    free(data);
    assert(sll_size_linked_list(head) == 3);
    assert(head->next->next->data == value3);
    assert(head->next->next->next == NULL);

    data = sll_delete_end_node(&head); // Delete 30
    assert(data == value3);
    free(data);
    assert(sll_size_linked_list(head) == 2);
    assert(head->next->data == value2);
    assert(head->next->next == NULL);

    data = sll_delete_end_node(&head); // Delete 20
    assert(data == value2);
    free(data);
    assert(sll_size_linked_list(head) == 1);
    assert(head->data == value1);
    assert(head->next == NULL);

    data = sll_delete_end_node(&head); // Delete 10 (single node case)
    assert(data == value1);
    free(data);
    assert(sll_size_linked_list(head) == 0);
    assert(head == NULL);

    // Attempt to delete from empty list
    data = sll_delete_end_node(&head);
    assert(data == NULL); // Should fail as list is empty

    // Clean up (already empty)
    while (head != NULL) {
        free(sll_delete_begin_node(&head));
    }
    assert(head == NULL);
    printf(" PASSED\n");
}

// New tests for sll_delete_node
void test_delete_node_empty_list() {
    printf("  - Testing sll_delete_node (empty list)...");
    sll_node_t *head = NULL;
    void *data = sll_delete_node(0, &head); // Try to delete from pos 0
    assert(data == NULL); // Should fail
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_delete_node_single_node() {
    printf("  - Testing sll_delete_node (single node, pos 0)...");
    sll_node_t *head = NULL;
    int *value = malloc(sizeof(int));
    *value = 10;
    sll_add_end_node(value, &head);
    assert(sll_size_linked_list(head) == 1);

    void *data = sll_delete_node(0, &head); // Delete the only node
    assert(data == value);
    assert(head == NULL);
    assert(sll_size_linked_list(head) == 0);
    free(data);
    printf(" PASSED\n");
}

void test_delete_node_first_node() {
    printf("  - Testing sll_delete_node (multi-node, pos 0)...");
    sll_node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    int *value3 = malloc(sizeof(int)); *value3 = 30;
    sll_add_end_node(value1, &head);
    sll_add_end_node(value2, &head);
    sll_add_end_node(value3, &head);
    assert(sll_size_linked_list(head) == 3);

    void *data = sll_delete_node(0, &head); // Delete 10
    assert(data == value1);
    free(data);
    assert(sll_size_linked_list(head) == 2);
    assert(head->data == value2);
    assert(head->next->data == value3);
    assert(head->next->next == NULL);

    while (head != NULL) {
        free(sll_delete_begin_node(&head));
    }
    printf(" PASSED\n");
}

void test_delete_node_middle_node() {
    printf("  - Testing sll_delete_node (multi-node, middle pos)...");
    sll_node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    int *value3 = malloc(sizeof(int)); *value3 = 30;
    int *value4 = malloc(sizeof(int)); *value4 = 40;
    sll_add_end_node(value1, &head);
    sll_add_end_node(value2, &head);
    sll_add_end_node(value3, &head);
    sll_add_end_node(value4, &head);
    assert(sll_size_linked_list(head) == 4);

    void *data = sll_delete_node(2, &head); // Delete 30
    assert(data == value3);
    free(data);
    assert(sll_size_linked_list(head) == 3);
    assert(head->data == value1);
    assert(head->next->data == value2);
    assert(head->next->next->data == value4);
    assert(head->next->next->next == NULL);

    while (head != NULL) {
        free(sll_delete_begin_node(&head));
    }
    printf(" PASSED\n");
}

void test_delete_node_last_node() {
    printf("  - Testing sll_delete_node (multi-node, last pos)...");
    sll_node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    int *value3 = malloc(sizeof(int)); *value3 = 30;
    sll_add_end_node(value1, &head);
    sll_add_end_node(value2, &head);
    sll_add_end_node(value3, &head);
    assert(sll_size_linked_list(head) == 3);

    void *data = sll_delete_node(2, &head); // Delete 30
    assert(data == value3);
    free(data);
    assert(sll_size_linked_list(head) == 2);
    assert(head->data == value1);
    assert(head->next->data == value2);
    assert(head->next->next == NULL);

    while (head != NULL) {
        free(sll_delete_begin_node(&head));
    }
    printf(" PASSED\n");
}

void test_delete_node_out_of_bounds() {
    printf("  - Testing sll_delete_node (out-of-bounds pos)...");
    sll_node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    sll_add_end_node(value1, &head);
    sll_add_end_node(value2, &head);
    assert(sll_size_linked_list(head) == 2);

    void *data = sll_delete_node(2, &head); // Position 2 is out of bounds (size is 2)
    assert(data == NULL); // Should fail
    assert(sll_size_linked_list(head) == 2);
    assert(head->data == value1);
    assert(head->next->data == value2);

    data = sll_delete_node(-1, &head); // Negative position
    assert(data == NULL); // Should fail
    assert(sll_size_linked_list(head) == 2);
    assert(head->data == value1);
    assert(head->next->data == value2);

    while (head != NULL) {
        free(sll_delete_begin_node(&head));
    }
    printf(" PASSED\n");
}
