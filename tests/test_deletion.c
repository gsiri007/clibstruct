#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "singlylinkedlist.h"


// Test function declarations (now called by a central runner)
void test_deleteEndNode_empty();
void test_deleteEndNode_single_node();
void test_deleteEndNode_multiple_nodes();
void test_deleteEndNode_multiple_nodes_after_deletion();
void test_deleteNode_empty_list();
void test_deleteNode_single_node();
void test_deleteNode_first_node();
void test_deleteNode_middle_node();
void test_deleteNode_last_node();
void test_deleteNode_out_of_bounds();

// Function to run all deletion-related tests
void run_deletion_tests() {
    printf("\n--- Running Singly Linked List Deletion Tests ---\n");
    test_deleteEndNode_empty();
    test_deleteEndNode_single_node();
    test_deleteEndNode_multiple_nodes();
    test_deleteEndNode_multiple_nodes_after_deletion();
    
    printf("\n--- Running deleteNode Tests ---\n");
    test_deleteNode_empty_list();
    test_deleteNode_single_node();
    test_deleteNode_first_node();
    test_deleteNode_middle_node();
    test_deleteNode_last_node();
    test_deleteNode_out_of_bounds();
    
    printf("--- All Deletion Tests Completed ---\n");
}

void test_deleteEndNode_empty() {
    printf("  - Testing deleteEndNode (empty list)...");
    node_t *head = NULL;
    void *data = deleteEndNode(&head);
    assert(data == NULL); // Should fail on an empty list
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_deleteEndNode_single_node() {
    printf("  - Testing deleteEndNode (single node)...");
    node_t *head = NULL;
    int *value = malloc(sizeof(int));
    *value = 10;
    addEndNode(value, &head);
    assert(head != NULL);
    assert(sizeLinkedList(head) == 1);

    void *data = deleteEndNode(&head);
    assert(data == value);
    assert(head == NULL); // Head should be NULL after deletion
    assert(sizeLinkedList(head) == 0);
    free(data);
    printf(" PASSED\n");
}

void test_deleteEndNode_multiple_nodes() {
    printf("  - Testing deleteEndNode (multiple nodes)...");
    node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    int *value3 = malloc(sizeof(int)); *value3 = 30;
    addEndNode(value1, &head);
    addEndNode(value2, &head);
    addEndNode(value3, &head);
    assert(sizeLinkedList(head) == 3);
    assert(head->data == value1);
    assert(head->next->data == value2);
    assert(head->next->next->data == value3);

    void *data = deleteEndNode(&head);
    assert(data == value3);
    assert(head != NULL);
    assert(sizeLinkedList(head) == 2);
    assert(head->data == value1);
    assert(head->next->data == value2);
    assert(head->next->next == NULL); // New end node
    free(data);
    
    // Clean up
    while (head != NULL) {
        free(deleteBeginNode(&head));
    }
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_deleteEndNode_multiple_nodes_after_deletion() {
    printf("  - Testing deleteEndNode (multiple nodes, sequential deletions)...");
    node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    int *value3 = malloc(sizeof(int)); *value3 = 30;
    int *value4 = malloc(sizeof(int)); *value4 = 40;
    addEndNode(value1, &head);
    addEndNode(value2, &head);
    addEndNode(value3, &head);
    addEndNode(value4, &head);
    assert(sizeLinkedList(head) == 4);

    void *data = deleteEndNode(&head); // Delete 40
    assert(data == value4);
    free(data);
    assert(sizeLinkedList(head) == 3);
    assert(head->next->next->data == value3);
    assert(head->next->next->next == NULL);

    data = deleteEndNode(&head); // Delete 30
    assert(data == value3);
    free(data);
    assert(sizeLinkedList(head) == 2);
    assert(head->next->data == value2);
    assert(head->next->next == NULL);

    data = deleteEndNode(&head); // Delete 20
    assert(data == value2);
    free(data);
    assert(sizeLinkedList(head) == 1);
    assert(head->data == value1);
    assert(head->next == NULL);

    data = deleteEndNode(&head); // Delete 10 (single node case)
    assert(data == value1);
    free(data);
    assert(sizeLinkedList(head) == 0);
    assert(head == NULL);

    // Attempt to delete from empty list
    data = deleteEndNode(&head);
    assert(data == NULL); // Should fail as list is empty

    // Clean up (already empty)
    while (head != NULL) {
        free(deleteBeginNode(&head));
    }
    assert(head == NULL);
    printf(" PASSED\n");
}

// New tests for deleteNode
void test_deleteNode_empty_list() {
    printf("  - Testing deleteNode (empty list)...");
    node_t *head = NULL;
    void *data = deleteNode(0, &head); // Try to delete from pos 0
    assert(data == NULL); // Should fail
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_deleteNode_single_node() {
    printf("  - Testing deleteNode (single node, pos 0)...");
    node_t *head = NULL;
    int *value = malloc(sizeof(int));
    *value = 10;
    addEndNode(value, &head);
    assert(sizeLinkedList(head) == 1);

    void *data = deleteNode(0, &head); // Delete the only node
    assert(data == value);
    assert(head == NULL);
    assert(sizeLinkedList(head) == 0);
    free(data);
    printf(" PASSED\n");
}

void test_deleteNode_first_node() {
    printf("  - Testing deleteNode (multi-node, pos 0)...");
    node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    int *value3 = malloc(sizeof(int)); *value3 = 30;
    addEndNode(value1, &head);
    addEndNode(value2, &head);
    addEndNode(value3, &head);
    assert(sizeLinkedList(head) == 3);

    void *data = deleteNode(0, &head); // Delete 10
    assert(data == value1);
    free(data);
    assert(sizeLinkedList(head) == 2);
    assert(head->data == value2);
    assert(head->next->data == value3);
    assert(head->next->next == NULL);

    while (head != NULL) {
        free(deleteBeginNode(&head));
    }
    printf(" PASSED\n");
}

void test_deleteNode_middle_node() {
    printf("  - Testing deleteNode (multi-node, middle pos)...");
    node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    int *value3 = malloc(sizeof(int)); *value3 = 30;
    int *value4 = malloc(sizeof(int)); *value4 = 40;
    addEndNode(value1, &head);
    addEndNode(value2, &head);
    addEndNode(value3, &head);
    addEndNode(value4, &head);
    assert(sizeLinkedList(head) == 4);

    void *data = deleteNode(2, &head); // Delete 30
    assert(data == value3);
    free(data);
    assert(sizeLinkedList(head) == 3);
    assert(head->data == value1);
    assert(head->next->data == value2);
    assert(head->next->next->data == value4);
    assert(head->next->next->next == NULL);

    while (head != NULL) {
        free(deleteBeginNode(&head));
    }
    printf(" PASSED\n");
}

void test_deleteNode_last_node() {
    printf("  - Testing deleteNode (multi-node, last pos)...");
    node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    int *value3 = malloc(sizeof(int)); *value3 = 30;
    addEndNode(value1, &head);
    addEndNode(value2, &head);
    addEndNode(value3, &head);
    assert(sizeLinkedList(head) == 3);

    void *data = deleteNode(2, &head); // Delete 30
    assert(data == value3);
    free(data);
    assert(sizeLinkedList(head) == 2);
    assert(head->data == value1);
    assert(head->next->data == value2);
    assert(head->next->next == NULL);

    while (head != NULL) {
        free(deleteBeginNode(&head));
    }
    printf(" PASSED\n");
}

void test_deleteNode_out_of_bounds() {
    printf("  - Testing deleteNode (out-of-bounds pos)...");
    node_t *head = NULL;
    int *value1 = malloc(sizeof(int)); *value1 = 10;
    int *value2 = malloc(sizeof(int)); *value2 = 20;
    addEndNode(value1, &head);
    addEndNode(value2, &head);
    assert(sizeLinkedList(head) == 2);

    void *data = deleteNode(2, &head); // Position 2 is out of bounds (size is 2)
    assert(data == NULL); // Should fail
    assert(sizeLinkedList(head) == 2);
    assert(head->data == value1);
    assert(head->next->data == value2);

    data = deleteNode(-1, &head); // Negative position
    assert(data == NULL); // Should fail
    assert(sizeLinkedList(head) == 2);
    assert(head->data == value1);
    assert(head->next->data == value2);

    while (head != NULL) {
        free(deleteBeginNode(&head));
    }
    printf(" PASSED\n");
}
