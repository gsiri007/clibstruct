#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "singlylinkedlist.h"

// Helper to create a heap-allocated float
static float* float_ptr(float value) {
    float* p = malloc(sizeof(float));
    assert(p != NULL);
    *p = value;
    return p;
}

// Helper to create a heap-allocated double
static double* double_ptr(double value) {
    double* p = malloc(sizeof(double));
    assert(p != NULL);
    *p = value;
    return p;
}

// Helper to create a heap-allocated char
static char* char_ptr(char value) {
    char* p = malloc(sizeof(char));
    assert(p != NULL);
    *p = value;
    return p;
}

// Helper to create a heap-allocated string
static char* string_ptr(const char* value) {
    char* p = malloc(strlen(value) + 1);
    assert(p != NULL);
    strcpy(p, value);
    return p;
}

// Helper to create a heap-allocated integer array
static int* int_array_ptr(const int* arr, size_t size) {
    int* p = malloc(size * sizeof(int));
    assert(p != NULL);
    memcpy(p, arr, size * sizeof(int));
    return p;
}

static void cleanup_list(node_t **head) {
    node_t *current = *head;
    node_t *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current->data);
        free(current);
        current = next_node;
    }
    *head = NULL;
}

void test_float_data() {
    printf("  - Testing float data...");
    node_t *head = NULL;
    addEndNode(float_ptr(10.5f), &head);
    addEndNode(float_ptr(20.5f), &head);
    addEndNode(float_ptr(-30.5f), &head);

    assert(head != NULL);
    assert(*(float*)head->data == 10.5f);
    assert(*(float*)head->next->data == 20.5f);
    assert(*(float*)head->next->next->data == -30.5f);
    assert(sizeLinkedList(head) == 3);

    cleanup_list(&head);
    printf(" PASSED\n");
}

void test_double_data() {
    printf("  - Testing double data...");
    node_t *head = NULL;
    addEndNode(double_ptr(10.555), &head);
    addEndNode(double_ptr(20.555), &head);
    addEndNode(double_ptr(-30.555), &head);

    assert(head != NULL);
    assert(*(double*)head->data == 10.555);
    assert(*(double*)head->next->data == 20.555);
    assert(*(double*)head->next->next->data == -30.555);
    assert(sizeLinkedList(head) == 3);

    cleanup_list(&head);
    printf(" PASSED\n");
}

void test_char_data() {
    printf("  - Testing char data...");
    node_t *head = NULL;
    addEndNode(char_ptr('a'), &head);
    addEndNode(char_ptr('b'), &head);
    addEndNode(char_ptr('Z'), &head);

    assert(head != NULL);
    assert(*(char*)head->data == 'a');
    assert(*(char*)head->next->data == 'b');
    assert(*(char*)head->next->next->data == 'Z');
    assert(sizeLinkedList(head) == 3);

    cleanup_list(&head);
    printf(" PASSED\n");
}

void test_string_data() {
    printf("  - Testing string data...");
    node_t *head = NULL;
    addEndNode(string_ptr("hello"), &head);
    addEndNode(string_ptr("world"), &head);
    addEndNode(string_ptr("testing"), &head);

    assert(head != NULL);
    assert(strcmp((char*)head->data, "hello") == 0);
    assert(strcmp((char*)head->next->data, "world") == 0);
    assert(strcmp((char*)head->next->next->data, "testing") == 0);
    assert(sizeLinkedList(head) == 3);

    cleanup_list(&head);
    printf(" PASSED\n");
}

void test_int_array_data() {
    printf("  - Testing int array data...");
    node_t *head = NULL;
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6, 7};
    int arr3[] = {8, 9};

    addEndNode(int_array_ptr(arr1, 3), &head);
    addEndNode(int_array_ptr(arr2, 4), &head);
    addEndNode(int_array_ptr(arr3, 2), &head);

    assert(head != NULL);
    assert(memcmp(head->data, arr1, 3 * sizeof(int)) == 0);
    assert(memcmp(head->next->data, arr2, 4 * sizeof(int)) == 0);
    assert(memcmp(head->next->next->data, arr3, 2 * sizeof(int)) == 0);
    assert(sizeLinkedList(head) == 3);

    cleanup_list(&head);
    printf(" PASSED\n");
}

void test_insertion_with_various_types() {
    printf("  - Testing insertNode with various types...");
    // Test with floats
    node_t *head_f = NULL;
    addEndNode(float_ptr(10.0f), &head_f);
    addEndNode(float_ptr(30.0f), &head_f);
    insertNode(1, float_ptr(20.0f), &head_f); // Insert in middle
    assert(sizeLinkedList(head_f) == 3);
    assert(*(float*)head_f->next->data == 20.0f);
    cleanup_list(&head_f);

    // Test with strings
    node_t *head_s = NULL;
    addEndNode(string_ptr("apple"), &head_s);
    addEndNode(string_ptr("cherry"), &head_s);
    insertNode(0, string_ptr("apricot"), &head_s); // Insert at beginning
    insertNode(3, string_ptr("date"), &head_s); // Insert at end
    assert(sizeLinkedList(head_s) == 4);
    assert(strcmp((char*)head_s->data, "apricot") == 0);
    assert(strcmp((char*)head_s->next->next->next->data, "date") == 0);
    cleanup_list(&head_s);
    printf(" PASSED\n");
}

void test_deletion_with_various_types() {
    printf("  - Testing deletion with various types...");
    // Test with floats
    node_t *head_f = NULL;
    addEndNode(float_ptr(10.0f), &head_f);
    addEndNode(float_ptr(20.0f), &head_f);
    addEndNode(float_ptr(30.0f), &head_f);
    deleteBeginNode(&head_f);
    assert(sizeLinkedList(head_f) == 2);
    assert(*(float*)head_f->data == 20.0f);
    deleteEndNode(&head_f);
    assert(sizeLinkedList(head_f) == 1);
    assert(*(float*)head_f->data == 20.0f);
    cleanup_list(&head_f);

    // Test with strings
    node_t *head_s = NULL;
    addEndNode(string_ptr("a"), &head_s);
    addEndNode(string_ptr("b"), &head_s);
    addEndNode(string_ptr("c"), &head_s);
    addEndNode(string_ptr("d"), &head_s);
    deleteNode(1, &head_s); // Delete 'b'
    assert(sizeLinkedList(head_s) == 3);
    assert(strcmp((char*)head_s->next->data, "c") == 0);
    cleanup_list(&head_s);
    printf(" PASSED\n");
}


void run_data_types_tests() {
    printf("\n--- Running Singly Linked List Data Type Tests ---\n");
    test_float_data();
    test_double_data();
    test_char_data();
    test_string_data();
    test_int_array_data();
    test_insertion_with_various_types();
    test_deletion_with_various_types();
    printf("--- All Data Type Tests Completed ---\n");
}
