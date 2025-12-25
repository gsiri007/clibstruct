/**
 * @file stack.h
 * @brief A simple stack data structure implementation.
 *
 * This implementation uses a singly linked list as the underlying data structure.
 */

#ifndef STACK_H
#define STACK_H

/**
 * @brief A handle to a stack data structure. The internal structure is hidden.
 * @ingroup Stack
 */
typedef struct Stack stack_t;

/**
 * @brief Creates a new, empty stack.
 * @return A pointer to the newly created stack, or NULL if memory allocation fails.
 * @ingroup Stack
 */
stack_t *create_stack();

/**
 * @brief Pushes a new data element onto the top of the stack.
 * @param data A pointer to the data to be stored.
 * @param stack A pointer to the stack.
 * @return 1 on success, 0 on failure.
 * @ingroup Stack
 */
int push_stack(void *data, stack_t *stack);

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
void *pop_stack(stack_t *stack);

/**
 * @brief Peeks at the top element of the stack without removing it.
 * @param stack A pointer to the stack.
 * @return A pointer to the data from the top of the stack, or NULL if the stack is empty.
 * @ingroup Stack
 */
void *peek_stack(stack_t *stack);

/**
 * @brief Checks if the stack is empty.
 * @param stack A pointer to the stack.
 * @return 1 (true) if the stack is empty or NULL, 0 (false) otherwise.
 * @ingroup Stack
 */
int is_empty_stack(stack_t *stack);

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
 * @warning Calling `free_stack()` will *not* deallocate any dynamically allocated `data` pushed onto the stack.
 *          The caller is solely responsible for managing the lifecycle of such data to prevent memory leaks.
 *
 * @param stack A double pointer to the stack to be freed. The pointer will be set to NULL.
 * @return 1 on success, 0 on failure.
 * @ingroup Stack
 */
int free_stack(stack_t **stack);

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
int destroy_stack(stack_t **stack);

//TODO: function to find the size of the stack

#endif //STACK_H
