#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../singlylinkedlist/singlylinkedlist.h"

// Helper to print list for debugging
void printList(node_t *head) {
    printf("List: ");
    node_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void test_insertNodeAtPosition_empty_list() {
    node_t *head = NULL;
    printf("Running test_insertNodeAtPosition_empty_list...\n");

    insertNode(0, 10, &head); // Insert at position 0 in an empty list
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next == NULL);
    printf("  Inserted 10 at position 0. List: 10->NULL - PASSED\n");

    deleteLinkedList(&head);
    printf("test_insertNodeAtPosition_empty_list PASSED\n");
}

void test_insertNodeAtPosition_beginning() {
    node_t *head = NULL;
    addEndNode(20, &head);
    addEndNode(30, &head);
    printf("Running test_insertNodeAtPosition_beginning...\n");
    // Initial list: 20 -> 30 -> NULL

    insertNode(0, 10, &head); // Insert at beginning
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next->data == 30);
    assert(head->next->next->next == NULL);
    printf("  Inserted 10 at position 0. List: 10->20->30->NULL - PASSED\n");

    deleteLinkedList(&head);
    printf("test_insertNodeAtPosition_beginning PASSED\n");
}

void test_insertNodeAtPosition_middle() {
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(30, &head);
    printf("Running test_insertNodeAtPosition_middle...\n");
    // Initial list: 10 -> 30 -> NULL

    insertNode(1, 20, &head); // Insert 20 at position 1
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next->data == 30);
    assert(head->next->next->next == NULL);
    printf("  Inserted 20 at position 1. List: 10->20->30->NULL - PASSED\n");

    deleteLinkedList(&head);
    printf("test_insertNodeAtPosition_middle PASSED\n");
}

void test_insertNodeAtPosition_end() {
    node_t *head = NULL;
    addEndNode(10, &head);
    addEndNode(20, &head);
    printf("Running test_insertNodeAtPosition_end...\n");
    // Initial list: 10 -> 20 -> NULL

    insertNode(2, 30, &head); // Insert 30 at position 2 (end)
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next->data == 30);
    assert(head->next->next->next == NULL);
    printf("  Inserted 30 at position 2. List: 10->20->30->NULL - PASSED\n");

    deleteLinkedList(&head);
    printf("test_insertNodeAtPosition_end PASSED\n");
}

void test_insertNodeAtPosition_out_of_bounds() {
    node_t *head = NULL;
    addEndNode(10, &head);
    printf("Running test_insertNodeAtPosition_out_of_bounds...\n");
    // Initial list: 10 -> NULL

    int result = insertNode(5, 20, &head); // Insert beyond the current end
    assert(result == -1); // Should fail
    assert(head->next == NULL); // List should be unchanged
    printf("  Attempted to insert at position 5. List remains 10->NULL - PASSED\n");

    deleteLinkedList(&head);
    printf("test_insertNodeAtPosition_out_of_bounds PASSED\n");
}


void run_insertion_tests() {
    printf("--- Running Insertion Tests ---\n");
    test_insertNodeAtPosition_empty_list();
    test_insertNodeAtPosition_beginning();
    test_insertNodeAtPosition_middle();
    test_insertNodeAtPosition_end();
    test_insertNodeAtPosition_out_of_bounds();
    printf("--- All Insertion Tests PASSED ---\n\n");
}
