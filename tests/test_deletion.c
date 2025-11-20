#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "singlylinkedlist.h"

// Test function declarations (now called by a central runner)
void test_deleteLinkedList_empty();
void test_deleteLinkedList_single_node();
void test_deleteLinkedList_multiple_nodes();
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
    test_deleteLinkedList_empty();
    test_deleteLinkedList_single_node();
    test_deleteLinkedList_multiple_nodes();
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

void test_deleteLinkedList_empty() {
    printf("  - Testing deleteLinkedList (empty list)...");
    node_t *head = NULL;
    int result = deleteLinkedList(&head);
    assert(result == 0); // Should succeed even on an empty list
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_deleteLinkedList_single_node() {
    printf("  - Testing deleteLinkedList (single node)...");
    node_t *head = NULL;
    addEndNode(10, &head); // Use the now-correct addEndNode
    assert(head != NULL);

    int result = deleteLinkedList(&head);
    assert(result == 0);
    assert(head == NULL); // Head should be NULL after deletion

    printf(" PASSED\n");
}

void test_deleteLinkedList_multiple_nodes() {
    printf("  - Testing deleteLinkedList (multiple nodes)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(20, &head);
    addEndNode(30, &head);
    assert(sizeLinkedList(head) == 3);

    int result = deleteLinkedList(&head);
    assert(result == 0);
    assert(head == NULL); // Head should be NULL after deletion
    
    printf(" PASSED\n");
}

void test_deleteEndNode_empty() {
    printf("  - Testing deleteEndNode (empty list)...");
    node_t *head = NULL;
    int result = deleteEndNode(&head);
    assert(result == -1); // Should fail on an empty list
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_deleteEndNode_single_node() {
    printf("  - Testing deleteEndNode (single node)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    assert(head != NULL);
    assert(sizeLinkedList(head) == 1);

    int result = deleteEndNode(&head);
    assert(result == 0);
    assert(head == NULL); // Head should be NULL after deletion
    assert(sizeLinkedList(head) == 0);
    printf(" PASSED\n");
}

void test_deleteEndNode_multiple_nodes() {
    printf("  - Testing deleteEndNode (multiple nodes)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(20, &head);
    addEndNode(30, &head);
    assert(sizeLinkedList(head) == 3);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next->data == 30);

    int result = deleteEndNode(&head);
    assert(result == 0);
    assert(head != NULL);
    assert(sizeLinkedList(head) == 2);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next == NULL); // New end node
    
    // Clean up
    deleteLinkedList(&head); // Use deleteLinkedList for cleanup
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_deleteEndNode_multiple_nodes_after_deletion() {
    printf("  - Testing deleteEndNode (multiple nodes, sequential deletions)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(20, &head);
    addEndNode(30, &head);
    addEndNode(40, &head);
    assert(sizeLinkedList(head) == 4);

    deleteEndNode(&head); // Delete 40
    assert(sizeLinkedList(head) == 3);
    assert(head->next->next->data == 30);
    assert(head->next->next->next == NULL);

    deleteEndNode(&head); // Delete 30
    assert(sizeLinkedList(head) == 2);
    assert(head->next->data == 20);
    assert(head->next->next == NULL);

    deleteEndNode(&head); // Delete 20
    assert(sizeLinkedList(head) == 1);
    assert(head->data == 10);
    assert(head->next == NULL);

    deleteEndNode(&head); // Delete 10 (single node case)
    assert(sizeLinkedList(head) == 0);
    assert(head == NULL);

    // Attempt to delete from empty list
    int result = deleteEndNode(&head);
    assert(result == -1); // Should fail as list is empty

    // Clean up (already empty)
    deleteLinkedList(&head); 
    assert(head == NULL);
    printf(" PASSED\n");
}

// New tests for deleteNode
void test_deleteNode_empty_list() {
    printf("  - Testing deleteNode (empty list)...");
    node_t *head = NULL;
    int result = deleteNode(&head, 0); // Try to delete from pos 0
    assert(result == -1); // Should fail
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_deleteNode_single_node() {
    printf("  - Testing deleteNode (single node, pos 0)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    assert(sizeLinkedList(head) == 1);

    int result = deleteNode(&head, 0); // Delete the only node
    assert(result == 0);
    assert(head == NULL);
    assert(sizeLinkedList(head) == 0);
    printf(" PASSED\n");
}

void test_deleteNode_first_node() {
    printf("  - Testing deleteNode (multi-node, pos 0)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(20, &head);
    addEndNode(30, &head);
    assert(sizeLinkedList(head) == 3);

    int result = deleteNode(&head, 0); // Delete 10
    assert(result == 0);
    assert(sizeLinkedList(head) == 2);
    assert(head->data == 20);
    assert(head->next->data == 30);
    assert(head->next->next == NULL);

    deleteLinkedList(&head);
    printf(" PASSED\n");
}

void test_deleteNode_middle_node() {
    printf("  - Testing deleteNode (multi-node, middle pos)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(20, &head);
    addEndNode(30, &head);
    addEndNode(40, &head);
    assert(sizeLinkedList(head) == 4);

    int result = deleteNode(&head, 2); // Delete 30
    assert(result == 0);
    assert(sizeLinkedList(head) == 3);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next->data == 40);
    assert(head->next->next->next == NULL);

    deleteLinkedList(&head);
    printf(" PASSED\n");
}

void test_deleteNode_last_node() {
    printf("  - Testing deleteNode (multi-node, last pos)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(20, &head);
    addEndNode(30, &head);
    assert(sizeLinkedList(head) == 3);

    int result = deleteNode(&head, 2); // Delete 30
    assert(result == 0);
    assert(sizeLinkedList(head) == 2);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next == NULL);

    deleteLinkedList(&head);
    printf(" PASSED\n");
}

void test_deleteNode_out_of_bounds() {
    printf("  - Testing deleteNode (out-of-bounds pos)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(20, &head);
    assert(sizeLinkedList(head) == 2);

    int result = deleteNode(&head, 2); // Position 2 is out of bounds (size is 2)
    assert(result == -1); // Should fail
    assert(sizeLinkedList(head) == 2); // List should be unchanged
    assert(head->data == 10);
    assert(head->next->data == 20);

    result = deleteNode(&head, -1); // Negative position
    assert(result == -1); // Should fail
    assert(sizeLinkedList(head) == 2); // List should be unchanged

    deleteLinkedList(&head);
    printf(" PASSED\n");
}

void test_deleteLinkedList_empty() {
    printf("  - Testing deleteLinkedList (empty list)...");
    node_t *head = NULL;
    int result = deleteLinkedList(&head);
    assert(result == 0); // Should succeed even on an empty list
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_deleteLinkedList_single_node() {
    printf("  - Testing deleteLinkedList (single node)...");
    node_t *head = NULL;
    addEndNode(10, &head); // Use the now-correct addEndNode
    assert(head != NULL);

    int result = deleteLinkedList(&head);
    assert(result == 0);
    assert(head == NULL); // Head should be NULL after deletion

    printf(" PASSED\n");
}

void test_deleteLinkedList_multiple_nodes() {
    printf("  - Testing deleteLinkedList (multiple nodes)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(20, &head);
    addEndNode(30, &head);
    assert(sizeLinkedList(head) == 3);

    int result = deleteLinkedList(&head);
    assert(result == 0);
    assert(head == NULL); // Head should be NULL after deletion
    
    printf(" PASSED\n");
}

void test_deleteEndNode_empty() {
    printf("  - Testing deleteEndNode (empty list)...");
    node_t *head = NULL;
    int result = deleteEndNode(&head);
    assert(result == -1); // Should fail on an empty list
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_deleteEndNode_single_node() {
    printf("  - Testing deleteEndNode (single node)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    assert(head != NULL);
    assert(sizeLinkedList(head) == 1);

    int result = deleteEndNode(&head);
    assert(result == 0);
    assert(head == NULL); // Head should be NULL after deletion
    assert(sizeLinkedList(head) == 0);
    printf(" PASSED\n");
}

void test_deleteEndNode_multiple_nodes() {
    printf("  - Testing deleteEndNode (multiple nodes)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(20, &head);
    addEndNode(30, &head);
    assert(sizeLinkedList(head) == 3);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next->data == 30);

    int result = deleteEndNode(&head);
    assert(result == 0);
    assert(head != NULL);
    assert(sizeLinkedList(head) == 2);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next == NULL); // New end node
    
    // Clean up
    deleteLinkedList(&head); // Use deleteLinkedList for cleanup
    assert(head == NULL);
    printf(" PASSED\n");
}

void test_deleteEndNode_multiple_nodes_after_deletion() {
    printf("  - Testing deleteEndNode (multiple nodes, sequential deletions)...");
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(20, &head);
    addEndNode(30, &head);
    addEndNode(40, &head);
    assert(sizeLinkedList(head) == 4);

    deleteEndNode(&head); // Delete 40
    assert(sizeLinkedList(head) == 3);
    assert(head->next->next->data == 30);
    assert(head->next->next->next == NULL);

    deleteEndNode(&head); // Delete 30
    assert(sizeLinkedList(head) == 2);
    assert(head->next->data == 20);
    assert(head->next->next == NULL);

    deleteEndNode(&head); // Delete 20
    assert(sizeLinkedList(head) == 1);
    assert(head->data == 10);
    assert(head->next == NULL);

    deleteEndNode(&head); // Delete 10 (single node case)
    assert(sizeLinkedList(head) == 0);
    assert(head == NULL);

    // Attempt to delete from empty list
    int result = deleteEndNode(&head);
    assert(result == -1); // Should fail as list is empty

    // Clean up (already empty)
    deleteLinkedList(&head); 
    assert(head == NULL);
    printf(" PASSED\n");
}
