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
    stack_t *stack = createStack();
    assert(stack != NULL);
    assert(stack->top == NULL);

    // Test freeStack (shallow free) with non-heap data
    int x = 10;
    pushStack(&x, stack);
    assert(peekStack(stack) == &x);
    freeStack(&stack);
    assert(stack == NULL);
    printf("  Test 'freeStack' (shallow free): PASSED\n");

    // Test destroyStack (deep free) with heap data
    stack = createStack();
    int *y = malloc(sizeof(int));
    *y = 20;
    pushStack(y, stack);
    assert(peekStack(stack) == y);
    destroyStack(&stack);
    assert(stack == NULL);
    printf("  Test 'destroyStack' (deep free): PASSED\n");
}

static void test_push_and_peek() {
    printf("Running 'push_and_peek' tests...\n");
    stack_t *stack = createStack();

    // Test on NULL stack
    assert(pushStack(NULL, NULL) == 0);
    assert(peekStack(NULL) == NULL);
    
    // Test on empty stack
    assert(peekStack(stack) == NULL);

    // Push first item
    int a = 1;
    assert(pushStack(&a, stack) == 1);
    assert(peekStack(stack) == &a);

    // Push second item
    int b = 2;
    assert(pushStack(&b, stack) == 1);
    assert(peekStack(stack) == &b); // Should be LIFO

    // Push NULL data
    assert(pushStack(NULL, stack) == 1);
    assert(peekStack(stack) == NULL);

    freeStack(&stack);
    printf("  Test 'pushStack' and 'peekStack': PASSED\n");
}

static void test_pop() {
    printf("Running 'pop' tests...\n");
    stack_t *stack = createStack();

    // Test on NULL stack
    assert(popStack(NULL) == NULL);

    // Test on empty stack
    assert(popStack(stack) == NULL);

    // Push and pop single item
    int a = 1;
    pushStack(&a, stack);
    int *pop_a = popStack(stack);
    assert(pop_a == &a);
    assert(isEmptyStack(stack) == 1); // now it's empty

    // Push multiple and pop all
    int b = 2, c = 3, d = 4;
    pushStack(&b, stack);
    pushStack(&c, stack);
    pushStack(&d, stack);

    int *pop_d = popStack(stack);
    int *pop_c = popStack(stack);
    int *pop_b = popStack(stack);

    assert(pop_d == &d);
    assert(pop_c == &c);
    assert(pop_b == &b);
    assert(popStack(stack) == NULL); // Should be empty now

    freeStack(&stack);
    printf("  Test 'popStack': PASSED\n");
}

static void test_is_empty() {
    printf("Running 'is_empty' tests...\n");
    stack_t *stack = createStack();

    // Test on NULL stack
    assert(isEmptyStack(NULL) == 1);

    // Test on newly created stack
    assert(isEmptyStack(stack) == 1);

    // Test after push
    int a = 1;
    pushStack(&a, stack);
    assert(isEmptyStack(stack) == 0);

    // Test after pop
    popStack(stack);
    assert(isEmptyStack(stack) == 1);

    freeStack(&stack);
    printf("  Test 'isEmptyStack': PASSED\n");
}
