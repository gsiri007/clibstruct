#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "singlylinkedlist.h" // Assuming singlylinkedlist.h defines node_t and relevant functions

// Helper function to clean up memory - made static to avoid multiple definition errors
static void cleanup_list_creation(node_t **head) {
    node_t *current = *head;
    node_t *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}

// Test function declarations (now called by a central runner)
void test_createLinkedList();
void test_addEndNode_basic();
void test_addEndNode_handles_null_head();

// Function to run all creation-related tests
void run_creation_tests() {
    printf("\n--- Running Singly Linked List Creation Tests ---\n");
    test_createLinkedList();
    test_addEndNode_basic();
    test_addEndNode_handles_null_head();
    printf("--- All Creation Tests Completed ---\n");
}

void test_createLinkedList() {
    printf("  - Testing createLinkedList...");
    node_t *head = createLinkedList(10);
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next == NULL);
    cleanup_list_creation(&head); // Use cleanup helper
    printf(" PASSED\n");
}

void test_addEndNode_basic() {
    printf("  - Testing addEndNode (basic, non-empty list)...");
    node_t *head = NULL;
    // Use addBeginNode to create a non-empty list without createLinkedList for now
    addBeginNode(10, &head); 
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next == NULL);

    int result = addEndNode(20, &head); // Corrected call
    assert(result == 0);
    assert(head->next != NULL);
    assert(head->next->data == 20);
    assert(head->next->next == NULL);

    // Add another node to ensure it still works
    result = addEndNode(30, &head);
    assert(result == 0);
    assert(head->next->next != NULL);
    assert(head->next->next->data == 30);
    assert(head->next->next->next == NULL);
    
    // Verify list structure and size
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next->data == 30);
    assert(sizeLinkedList(head) == 3); 

    cleanup_list_creation(&head); // Use cleanup helper
    printf(" PASSED\n");
}

void test_addEndNode_handles_null_head() {
    printf("  - Testing addEndNode (empty list)...");
    node_t *head = NULL;
    
    int result = addEndNode(100, &head); // Add to an empty list
    assert(result == 0);
    assert(head != NULL);
    assert(head->data == 100);
    assert(head->next == NULL);
    assert(sizeLinkedList(head) == 1);

    // Add a second node to ensure it still behaves correctly after the first
    result = addEndNode(200, &head);
    assert(result == 0);
    assert(head->next != NULL);
    assert(head->next->data == 200);
    assert(head->next->next == NULL);
    assert(sizeLinkedList(head) == 2);

    cleanup_list_creation(&head); // Use cleanup helper
    printf(" PASSED\n");
}
