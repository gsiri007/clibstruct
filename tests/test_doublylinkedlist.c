#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "doublylinkedlist.h"

// Helper to create a heap-allocated integer
static int* int_ptr(int value) {
    int* p = malloc(sizeof(int));
    assert(p != NULL);
    *p = value;
    return p;
}

// Helper function to clean up memory
static void cleanup_dll(dll_node_t **head) {
    dll_node_t *current = *head;
    dll_node_t *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current->data); // Free the dynamically allocated data
        free(current);       // Free the node itself
        current = next_node;
    }
    *head = NULL;
}

void test_dll_create_linked_list() {
    printf("  - Testing dll_create_linked_list...");
    dll_node_t *head = dll_create_linked_list(int_ptr(10));
    assert(head != NULL);
    assert(*(int*)head->data == 10);
    assert(head->next == NULL);
    assert(head->prev == NULL);
    cleanup_dll(&head);
    printf(" PASSED\n");
}

void test_dll_add_end_node() {
    printf("  - Testing dll_add_end_node...");
    dll_node_t *head = dll_create_linked_list(int_ptr(10));
    dll_add_end_node(int_ptr(20), &head);
    
    assert(head->next != NULL);
    assert(*(int*)head->next->data == 20);
    assert(head->next->prev == head);
    
    cleanup_dll(&head);
    printf(" PASSED\n");
}

void test_dll_add_begin_node() {
    printf("  - Testing dll_add_begin_node...");
    dll_node_t *head = dll_create_linked_list(int_ptr(10));
    dll_add_begin_node(int_ptr(5), &head);
    
    assert(*(int*)head->data == 5);
    assert(head->next != NULL);
    assert(*(int*)head->next->data == 10);
    assert(head->next->prev == head);
    
    cleanup_dll(&head);
    printf(" PASSED\n");
}

void test_dll_insert_node() {
    printf("  - Testing dll_insert_node...");
    dll_node_t *head = dll_create_linked_list(int_ptr(10));
    dll_add_end_node(int_ptr(30), &head);
    
    // Insert at position 1 (between 10 and 30)
    dll_insert_node(1, int_ptr(20), &head);
    
    assert(*(int*)head->next->data == 20);
    assert(head->next->prev == head);
    assert(head->next->next->data != NULL);
    assert(*(int*)head->next->next->data == 30);
    assert(head->next->next->prev == head->next);
    
    cleanup_dll(&head);
    printf(" PASSED\n");
}

void test_dll_delete_end_node() {
    printf("  - Testing dll_delete_end_node...");
    dll_node_t *head = dll_create_linked_list(int_ptr(10));
    dll_add_end_node(int_ptr(20), &head);
    
    int *deleted_data = (int*)dll_delete_end_node(&head);
    assert(*deleted_data == 20);
    free(deleted_data);
    
    assert(head->next == NULL);
    
    cleanup_dll(&head);
    printf(" PASSED\n");
}

void test_dll_delete_begin_node() {
    printf("  - Testing dll_delete_begin_node...");
    dll_node_t *head = dll_create_linked_list(int_ptr(10));
    dll_add_end_node(int_ptr(20), &head);
    
    int *deleted_data = (int*)dll_delete_begin_node(&head);
    assert(*deleted_data == 10);
    free(deleted_data);
    
    assert(*(int*)head->data == 20);
    assert(head->prev == NULL);
    
    cleanup_dll(&head);
    printf(" PASSED\n");
}

void test_dll_reverse_linked_list() {
    printf("  - Testing dll_reverse_linked_list...");
    dll_node_t *head = dll_create_linked_list(int_ptr(1));
    dll_add_end_node(int_ptr(2), &head);
    dll_add_end_node(int_ptr(3), &head);
    
    dll_reverse_linked_list(&head);
    
    assert(*(int*)head->data == 3);
    assert(*(int*)head->next->data == 2);
    assert(*(int*)head->next->next->data == 1);
    
    assert(head->prev == NULL);
    assert(head->next->prev == head);
    assert(head->next->next->prev == head->next);
    
    cleanup_dll(&head);
    printf(" PASSED\n");
}

void run_doublylinkedlist_tests() {
    printf("\n--- Running Doubly Linked List Tests ---\\n");
    test_dll_create_linked_list();
    test_dll_add_end_node();
    test_dll_add_begin_node();
    test_dll_insert_node();
    test_dll_delete_end_node();
    test_dll_delete_begin_node();
    test_dll_reverse_linked_list();
    printf("--- All Doubly Linked List Tests Completed ---\\n");
}
