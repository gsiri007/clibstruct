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

static void cleanup_list(sll_node_t **head) {
    sll_node_t *current = *head;
    sll_node_t *next_node;
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
    sll_node_t *head = NULL;
    sll_add_end_node(float_ptr(10.5f), &head);
    sll_add_end_node(float_ptr(20.5f), &head);
    sll_add_end_node(float_ptr(-30.5f), &head);

    assert(head != NULL);
    assert(*(float*)head->data == 10.5f);
    assert(*(float*)head->next->data == 20.5f);
    assert(*(float*)head->next->next->data == -30.5f);
    assert(sll_size_linked_list(head) == 3);

    cleanup_list(&head);
    printf(" PASSED\n");
}

void test_double_data() {
    printf("  - Testing double data...");
    sll_node_t *head = NULL;
    sll_add_end_node(double_ptr(10.555), &head);
    sll_add_end_node(double_ptr(20.555), &head);
    sll_add_end_node(double_ptr(-30.555), &head);

    assert(head != NULL);
    assert(*(double*)head->data == 10.555);
    assert(*(double*)head->next->data == 20.555);
    assert(*(double*)head->next->next->data == -30.555);
    assert(sll_size_linked_list(head) == 3);

    cleanup_list(&head);
    printf(" PASSED\n");
}

void test_char_data() {
    printf("  - Testing char data...");
    sll_node_t *head = NULL;
    sll_add_end_node(char_ptr('a'), &head);
    sll_add_end_node(char_ptr('b'), &head);
    sll_add_end_node(char_ptr('Z'), &head);

    assert(head != NULL);
    assert(*(char*)head->data == 'a');
    assert(*(char*)head->next->data == 'b');
    assert(*(char*)head->next->next->data == 'Z');
    assert(sll_size_linked_list(head) == 3);

    cleanup_list(&head);
    printf(" PASSED\n");
}

void test_string_data() {
    printf("  - Testing string data...");
    sll_node_t *head = NULL;
    sll_add_end_node(string_ptr("hello"), &head);
    sll_add_end_node(string_ptr("world"), &head);
    sll_add_end_node(string_ptr("testing"), &head);

    assert(head != NULL);
    assert(strcmp((char*)head->data, "hello") == 0);
    assert(strcmp((char*)head->next->data, "world") == 0);
    assert(strcmp((char*)head->next->next->data, "testing") == 0);
    assert(sll_size_linked_list(head) == 3);

    cleanup_list(&head);
    printf(" PASSED\n");
}

void test_int_array_data() {
    printf("  - Testing int array data...");
    sll_node_t *head = NULL;
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6, 7};
    int arr3[] = {8, 9};

    sll_add_end_node(int_array_ptr(arr1, 3), &head);
    sll_add_end_node(int_array_ptr(arr2, 4), &head);
    sll_add_end_node(int_array_ptr(arr3, 2), &head);

    assert(head != NULL);
    assert(memcmp(head->data, arr1, 3 * sizeof(int)) == 0);
    assert(memcmp(head->next->data, arr2, 4 * sizeof(int)) == 0);
    assert(memcmp(head->next->next->data, arr3, 2 * sizeof(int)) == 0);
    assert(sll_size_linked_list(head) == 3);

    cleanup_list(&head);
    printf(" PASSED\n");
}

void test_insertion_with_various_types() {
    printf("  - Testing sll_insert_node with various types...");
    // Test with floats
    sll_node_t *head_f = NULL;
    sll_add_end_node(float_ptr(10.0f), &head_f);
    sll_add_end_node(float_ptr(30.0f), &head_f);
    sll_insert_node(1, float_ptr(20.0f), &head_f); // Insert in middle
    assert(sll_size_linked_list(head_f) == 3);
    assert(*(float*)head_f->next->data == 20.0f);
    cleanup_list(&head_f);

    // Test with strings
    sll_node_t *head_s = NULL;
    sll_add_end_node(string_ptr("apple"), &head_s);
    sll_add_end_node(string_ptr("cherry"), &head_s);
    sll_insert_node(0, string_ptr("apricot"), &head_s); // Insert at beginning
    sll_insert_node(3, string_ptr("date"), &head_s); // Insert at end
    assert(sll_size_linked_list(head_s) == 4);
    assert(strcmp((char*)head_s->data, "apricot") == 0);
    assert(strcmp((char*)head_s->next->next->next->data, "date") == 0);
    cleanup_list(&head_s);
    printf(" PASSED\n");
}

void test_deletion_with_various_types() {
    printf("  - Testing deletion with various types...");
    // Test with floats
    sll_node_t *head_f = NULL;
    sll_add_end_node(float_ptr(10.0f), &head_f);
    sll_add_end_node(float_ptr(20.0f), &head_f);
    sll_add_end_node(float_ptr(30.0f), &head_f);
    sll_delete_begin_node(&head_f);
    assert(sll_size_linked_list(head_f) == 2);
    assert(*(float*)head_f->data == 20.0f);
    sll_delete_end_node(&head_f);
    assert(sll_size_linked_list(head_f) == 1);
    assert(*(float*)head_f->data == 20.0f);
    cleanup_list(&head_f);

    // Test with strings
    sll_node_t *head_s = NULL;
    sll_add_end_node(string_ptr("a"), &head_s);
    sll_add_end_node(string_ptr("b"), &head_s);
    sll_add_end_node(string_ptr("c"), &head_s);
    sll_add_end_node(string_ptr("d"), &head_s);
    sll_delete_node(1, &head_s); // Delete 'b'
    assert(sll_size_linked_list(head_s) == 3);
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
