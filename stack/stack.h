/**
 * @file stack.h
 * @brief A simple stack data structure implementation.
 *
 * This implementation uses a singly linked list as the underlying data structure.
 */

#ifndef STACK_H
#define STACK_H

#include "../singlylinkedlist/singlylinkedlist.h"

/**
 * @brief The main stack structure.
 * @ingroup Stack
 */
typedef struct Stack {
    node_t *top; /**< Pointer to the top node of the stack. */
} stack_t;

/**
 * @brief Creates a new, empty stack.
 * @return A pointer to the newly created stack, or NULL if memory allocation fails.
 * @ingroup Stack
 */
stack_t *createStack();

/**
 * @brief Pushes a new data element onto the top of the stack.
 * @param data A pointer to the data to be stored.
 * @param stack A pointer to the stack.
 * @return 1 on success, 0 on failure.
 * @ingroup Stack
 */
int pushStack(void *data, stack_t *stack);

/**
 * @brief Pops the top element from the stack.
 *
 * This function removes the top node from the stack and returns the data stored in it.
 * The node itself is freed, but the data is not. The caller is responsible for the data.
 *
 * @param stack A pointer to the stack.
 * @return A pointer to the data from the top of the stack, or NULL if the stack is empty.
 * @ingroup Stack
 */
void *popStack(stack_t *stack);

/**
 * @brief Peeks at the top element of the stack without removing it.
 * @param stack A pointer to the stack.
 * @return A pointer to the data from the top of the stack, or NULL if the stack is empty.
 * @ingroup Stack
 */
void *peekStack(stack_t *stack);

/**
 * @brief Checks if the stack is empty.
 * @param stack A pointer to the stack.
 * @return 1 (true) if the stack is empty or NULL, 0 (false) otherwise.
 * @ingroup Stack
 */
int isEmptyStack(stack_t *stack);

/**
 * @brief Frees the stack structure and all its nodes (shallow free).
 *
 * This function performs a "shallow" free. It deallocates the stack container and all of its
 * internal nodes, but it does **not** free the `data` pointers held within each node.
 * This is the correct function to use when:
 * - You are storing pointers to local (stack) variables or static variables.
 * - You have a separate system for managing the memory of the data.
 * - You need to pop items from the stack to process them before deallocation.
 *
 * @warning Calling `freeStack()` will *not* deallocate any dynamically allocated `data` pushed onto the stack.
 *          The caller is solely responsible for managing the lifecycle of such data to prevent memory leaks.
 *
 * @param stack A double pointer to the stack to be freed. The pointer will be set to NULL.
 * @return 1 on success, 0 on failure.
 * @ingroup Stack
 */
int freeStack(stack_t **stack);

/**
 * @brief Frees the stack, its nodes, and the data in each node (deep free).
 *
 * This function performs a "deep" free. It deallocates the stack container, all of its
 * internal nodes, AND it calls `free()` on every `data` pointer it contains.
 *
 * @warning This function is convenient but should **only** be used when you are certain that
 * every item pushed onto the stack is a pointer to heap-allocated memory (e.g., from `malloc`).
 * Using this on data that is not heap-allocated will result in a program crash or
 * undefined behavior.
 *
 * @param stack A double pointer to the stack to be destroyed. The pointer will be set to NULL.
 * @return 1 on success, 0 on failure.
 * @ingroup Stack
 */
int destroyStack(stack_t **stack);


#endif //STACK_H
