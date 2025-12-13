#include <stdlib.h>
#include "stack.h"
#include "../singlylinkedlist/singlylinkedlist.h"

// The full definition of the stack is private to the implementation file.
// TODO: review this
struct Stack {
    sll_node_t *top;
};

stack_t *create_stack() {
    stack_t *stack = (stack_t *) malloc(sizeof(stack_t));
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

int push_stack(void *data, stack_t *stack) {
    if (stack == NULL) {
        return 0;
    }
    return sll_add_begin_node(data, &(stack->top));
}

void *pop_stack(stack_t *stack) {
    if (stack == NULL) {
        return NULL;
    }
    return sll_delete_begin_node(&(stack->top));
}

void *peek_stack(stack_t *stack) {
    if (stack == NULL || stack->top == NULL) {
        return NULL;
    }
    return stack->top->data;
}

int is_empty_stack(stack_t *stack) {
    if (stack == NULL || stack->top == NULL) {
        return 1;
    }
    return 0;
}

int free_stack(stack_t **stack) {
    if (*stack == NULL || stack == NULL) {
        return 0;
    }

    while ((*stack)->top != NULL) {
        pop_stack(*stack);
    }

    free(*stack);
    *stack = NULL;
    return 1;

}

int destroy_stack(stack_t **stack) {
    if (*stack == NULL || stack == NULL) {
        return 0;
    }

    while ((*stack)->top != NULL) {
        void *data = pop_stack(*stack);
        free(data);
    }

    free(*stack);
    *stack = NULL;
    return 1;
}
