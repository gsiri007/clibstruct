#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../singlylinkedlist/singlylinkedlist.h"

// Helper to create a heap-allocated integer
static int* int_ptr(int value) {
    int* p = malloc(sizeof(int));
    assert(p != NULL);
    *p = value;
    return p;
}

// Helper function to clean up memory, including the data pointer
static void cleanup_list(sll_node_t **head) {
    sll_node_t *current = *head;
    sll_node_t *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current->data); // Free the dynamically allocated data
        free(current);       // Free the node itself
        current = next_node;
    }
    *head = NULL;
}

// Helper to print list for debugging
void printList(sll_node_t *head) {
    printf("List: ");
    sll_node_t *current = head;
    while (current != NULL) {
        printf("%d -> ", *(int*)current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void test_insert_nodeAtPosition_empty_list() {
    sll_node_t *head = NULL;
    printf("Running test_insert_nodeAtPosition_empty_list...\n");

    sll_insert_node(0, int_ptr(10), &head); // Insert at position 0 in an empty list
    assert(head != NULL);
    assert(*(int*)head->data == 10);
    assert(head->next == NULL);
    printf("  Inserted 10 at position 0. List: 10->NULL - PASSED\n");

    cleanup_list(&head);
    printf("test_insert_nodeAtPosition_empty_list PASSED\n");
}

void test_insert_nodeAtPosition_beginning() {
    sll_node_t *head = NULL;
    sll_add_end_node(int_ptr(20), &head);
    sll_add_end_node(int_ptr(30), &head);
    printf("Running test_insert_nodeAtPosition_beginning...\n");
    // Initial list: 20 -> 30 -> NULL

    sll_insert_node(0, int_ptr(10), &head); // Insert at beginning
    assert(head != NULL);
    assert(*(int*)head->data == 10);
    assert(*(int*)head->next->data == 20);
    assert(*(int*)head->next->next->data == 30);
    assert(head->next->next->next == NULL);
    printf("  Inserted 10 at position 0. List: 10->20->30->NULL - PASSED\n");

    cleanup_list(&head);
    printf("test_insert_nodeAtPosition_beginning PASSED\n");
}

void test_insert_nodeAtPosition_middle() {
    sll_node_t *head = NULL;
    sll_add_end_node(int_ptr(10), &head);
    sll_add_end_node(int_ptr(30), &head);
    printf("Running test_insert_nodeAtPosition_middle...\n");
    // Initial list: 10 -> 30 -> NULL

    sll_insert_node(1, int_ptr(20), &head); // Insert 20 at position 1
    assert(head != NULL);
    assert(*(int*)head->data == 10);
    assert(*(int*)head->next->data == 20);
    assert(*(int*)head->next->next->data == 30);
    assert(head->next->next->next == NULL);
    printf("  Inserted 20 at position 1. List: 10->20->30->NULL - PASSED\n");

    cleanup_list(&head);
    printf("test_insert_nodeAtPosition_middle PASSED\n");
}

void test_insert_nodeAtPosition_end() {
    sll_node_t *head = NULL;
    sll_add_end_node(int_ptr(10), &head);
    sll_add_end_node(int_ptr(20), &head);
    printf("Running test_insert_nodeAtPosition_end...\n");
    // Initial list: 10 -> 20 -> NULL

    sll_insert_node(2, int_ptr(30), &head); // Insert 30 at position 2 (end)
    assert(head != NULL);
    assert(*(int*)head->data == 10);
    assert(*(int*)head->next->data == 20);
    assert(*(int*)head->next->next->data == 30);
    assert(head->next->next->next == NULL);
    printf("  Inserted 30 at position 2. List: 10->20->30->NULL - PASSED\n");

    cleanup_list(&head);
    printf("test_insert_nodeAtPosition_end PASSED\n");
}

void test_insert_nodeAtPosition_out_of_bounds() {
    sll_node_t *head = NULL;
    sll_add_end_node(int_ptr(10), &head);
    printf("Running test_insert_nodeAtPosition_out_of_bounds...\n");
    // Initial list: 10 -> NULL

    int* data_to_insert = int_ptr(20);
    int result = sll_insert_node(5, data_to_insert, &head); // Insert beyond the current end
    assert(result == 0); // Should fail
    assert(head->next == NULL); // List should be unchanged
    free(data_to_insert); // Manually free data since insertion failed
    printf("  Attempted to insert at position 5. List remains 10->NULL - PASSED\n");

    cleanup_list(&head);
    printf("test_insert_nodeAtPosition_out_of_bounds PASSED\n");
}

void run_insertion_tests() {
    printf("--- Running Insertion Tests ---\n");
    test_insert_nodeAtPosition_empty_list();
    test_insert_nodeAtPosition_beginning();
    test_insert_nodeAtPosition_middle();
    test_insert_nodeAtPosition_end();
    test_insert_nodeAtPosition_out_of_bounds();
    printf("--- All Insertion Tests PASSED ---\n\n");
}
