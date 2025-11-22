#include <stdlib.h>
#include "stack.h"

stack_t *createStack() {
    stack_t *stack = (stack_t *) malloc(sizeof(stack_t));
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

int pushStack(void *data, stack_t *stack) {
    if (stack == NULL) {
        return 0;
    }
    return addBeginNode(data, &(stack->top));
}

void *popStack(stack_t *stack) {
    if (stack == NULL) {
        return NULL;
    }
    return deleteBeginNode(&(stack->top));
}

void *peekStack(stack_t *stack) {
    if (stack == NULL || stack->top == NULL) {
        return NULL;
    }
    return stack->top->data;
}

int isEmptyStack(stack_t *stack) {
    if (stack == NULL || stack->top == NULL) {
        return 1;
    }
    return 0;
}

int freeStack(stack_t **stack) {
    if (*stack == NULL || stack == NULL) {
        return 0;
    }

    while ((*stack)->top != NULL) {
        popStack(*stack);
    }

    free(*stack);
    *stack = NULL;
    return 1;

}

int destroyStack(stack_t **stack) {
    if (*stack == NULL || stack == NULL) {
        return 0;
    }

    while ((*stack)->top != NULL) {
        void *data = popStack(*stack);
        free(data);
    }

    free(*stack);
    *stack = NULL;
    return 1;
}
