#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../stack/stack.h"

// Test function declarations
static void test_create_and_free();
static void test_push_and_peek();
static void test_pop();
static void test_is_empty();

void run_stack_tests() {
    printf("--- Starting Stack Test Suite ---\n");

    test_create_and_free();
    test_push_and_peek();
    test_pop();
    test_is_empty();

    printf("--- Stack Test Suite Completed ---\n");
}

static void test_create_and_free() {
    printf("Running 'create_and_free' tests...\n");
    // Test creation
    stack_t *stack = create_stack();
    assert(stack != NULL);
    assert(is_empty_stack(stack));

    // Test free_stack (shallow free) with non-heap data
    int x = 10;
    push_stack(&x, stack);
    assert(peek_stack(stack) == &x);
    free_stack(&stack);
    assert(stack == NULL);
    printf("  Test 'free_stack' (shallow free): PASSED\n");

    // Test destroy_stack (deep free) with heap data
    stack = create_stack();
    int *y = malloc(sizeof(int));
    *y = 20;
    push_stack(y, stack);
    assert(peek_stack(stack) == y);
    destroy_stack(&stack);
    assert(stack == NULL);
    printf("  Test 'destroy_stack' (deep free): PASSED\n");
}

static void test_push_and_peek() {
    printf("Running 'push_and_peek' tests...\n");
    stack_t *stack = create_stack();

    // Test on NULL stack
    assert(push_stack(NULL, NULL) == 0);
    assert(peek_stack(NULL) == NULL);
    
    // Test on empty stack
    assert(peek_stack(stack) == NULL);

    // Push first item
    int a = 1;
    assert(push_stack(&a, stack) == 1);
    assert(peek_stack(stack) == &a);

    // Push second item
    int b = 2;
    assert(push_stack(&b, stack) == 1);
    assert(peek_stack(stack) == &b); // Should be LIFO

    // Push NULL data
    assert(push_stack(NULL, stack) == 1);
    assert(peek_stack(stack) == NULL);

    free_stack(&stack);
    printf("  Test 'push_stack' and 'peek_stack': PASSED\n");
}

static void test_pop() {
    printf("Running 'pop' tests...\n");
    stack_t *stack = create_stack();

    // Test on NULL stack
    assert(pop_stack(NULL) == NULL);

    // Test on empty stack
    assert(pop_stack(stack) == NULL);

    // Push and pop single item
    int a = 1;
    push_stack(&a, stack);
    int *pop_a = pop_stack(stack);
    assert(pop_a == &a);
    assert(is_empty_stack(stack) == 1); // now it's empty

    // Push multiple and pop all
    int b = 2, c = 3, d = 4;
    push_stack(&b, stack);
    push_stack(&c, stack);
    push_stack(&d, stack);

    int *pop_d = pop_stack(stack);
    int *pop_c = pop_stack(stack);
    int *pop_b = pop_stack(stack);

    assert(pop_d == &d);
    assert(pop_c == &c);
    assert(pop_b == &b);
    assert(pop_stack(stack) == NULL); // Should be empty now

    free_stack(&stack);
    printf("  Test 'pop_stack': PASSED\n");
}

static void test_is_empty() {
    printf("Running 'is_empty' tests...\n");
    stack_t *stack = create_stack();

    // Test on NULL stack
    assert(is_empty_stack(NULL) == 1);

    // Test on newly created stack
    assert(is_empty_stack(stack) == 1);

    // Test after push
    int a = 1;
    push_stack(&a, stack);
    assert(is_empty_stack(stack) == 0);

    // Test after pop
    pop_stack(stack);
    assert(is_empty_stack(stack) == 1);

    free_stack(&stack);
    printf("  Test 'is_empty_stack': PASSED\n");
}
