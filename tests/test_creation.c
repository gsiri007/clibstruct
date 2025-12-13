#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "singlylinkedlist.h" // Assuming singlylinkedlist.h defines sll_node_t and relevant functions

// Helper to create a heap-allocated integer
static int* int_ptr(int value) {
    int* p = malloc(sizeof(int));
    assert(p != NULL); // Ensure malloc was successful
    *p = value;
    return p;
}

// Helper function to clean up memory - made static to avoid multiple definition errors
static void cleanup_list_creation(sll_node_t **head) {
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

// Test function declarations (now called by a central runner)
void test_create_linked_list();
void test_add_end_node_basic();
void test_add_end_node_handles_null_head();

// Function to run all creation-related tests
void run_creation_tests() {
    printf("\n--- Running Singly Linked List Creation Tests ---\n");
    test_create_linked_list();
    test_add_end_node_basic();
    test_add_end_node_handles_null_head();
    printf("--- All Creation Tests Completed ---\n");
}

void test_create_linked_list() {
    printf("  - Testing sll_create_linked_list...");
    sll_node_t *head = sll_create_linked_list(int_ptr(10));
    assert(head != NULL);
    assert(*(int*)head->data == 10);
    assert(head->next == NULL);
    cleanup_list_creation(&head); // Use cleanup helper
    printf(" PASSED\n");
}

void test_add_end_node_basic() {
    printf("  - Testing sll_add_end_node (basic, non-empty list)...");
    sll_node_t *head = NULL;
    // Use sll_add_begin_node to create a non-empty list without sll_create_linked_list for now
    sll_add_begin_node(int_ptr(10), &head); 
    assert(head != NULL);
    assert(*(int*)head->data == 10);
    assert(head->next == NULL);

    int result = sll_add_end_node(int_ptr(20), &head); // Corrected call
    assert(result == 1);
    assert(head->next != NULL);
    assert(*(int*)head->next->data == 20);
    assert(head->next->next == NULL);

    // Add another node to ensure it still works
    result = sll_add_end_node(int_ptr(30), &head);
    assert(result == 1);
    assert(head->next->next != NULL);
    assert(*(int*)head->next->next->data == 30);
    assert(head->next->next->next == NULL);
    
    // Verify list structure and size
    assert(*(int*)head->data == 10);
    assert(*(int*)head->next->data == 20);
    assert(*(int*)head->next->next->data == 30);
    assert(sll_size_linked_list(head) == 3); 

    cleanup_list_creation(&head); // Use cleanup helper
    printf(" PASSED\n");
}

void test_add_end_node_handles_null_head() {
    printf("  - Testing sll_add_end_node (empty list)...");
    sll_node_t *head = NULL;
    
    int result = sll_add_end_node(int_ptr(100), &head); // Add to an empty list
    assert(result == 1);
    assert(head != NULL);
    assert(*(int*)head->data == 100);
    assert(head->next == NULL);
    assert(sll_size_linked_list(head) == 1);

    // Add a second node to ensure it still behaves correctly after the first
    result = sll_add_end_node(int_ptr(200), &head);
    assert(result == 1);
    assert(head->next != NULL);
    assert(*(int*)head->next->data == 200);
    assert(head->next->next == NULL);
    assert(sll_size_linked_list(head) == 2);

    cleanup_list_creation(&head); // Use cleanup helper
    printf(" PASSED\n");
}
