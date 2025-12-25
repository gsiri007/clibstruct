/**
 * @file singlylinkedlist.h
 * @brief A library for creating and manipulating singly linked lists of generic data.
 * @note This library stores data using `void*` pointers, allowing it to store
 * any data type. The user is responsible for managing the memory of the data
 * stored in the list. This includes allocating memory for the data before
 * insertion and freeing it after deletion or when the list is destroyed.
 */
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdbool.h>

/**
 * @brief A node in a singly linked list.
 * @ingroup SinglyLinkedList
 */
typedef struct SllNode sll_node_t;

/**
 * @brief A singly linked list structure.
 * @ingroup SinglyLinkedList
 */
typedef struct Sll sll_t;

/**
 * @brief Creates a new, empty linked list.
 * @return A pointer to the new linked list structure, or NULL on failure.
 * @ingroup SinglyLinkedList
 */
sll_t *sll_create_linked_list();

/**
 * @brief Adds a new node to the beginning of the linked list.
 * @param sll A pointer to the linked list.
 * @param data The data for the new node.
 * @return 0 on success, 1 on failure.
 * @ingroup SinglyLinkedList
 */
int sll_add_head_node(sll_t *sll, void *data);

/**
 * @brief Adds a new node to the end of the linked list.
 * @param sll A pointer to the linked list.
 * @param data The data for the new node.
 * @return 0 on success, 1 on failure.
 * @ingroup SinglyLinkedList
 */
int sll_add_tail_node(sll_t *sll, void *data);


/**
 * @brief Inserts a new node at a specific position in the linked list.
 * @param sll A pointer to the linked list.
 * @param pos The position to insert the new node at.
 * @param data The data for the new node.
 * @return 0 on success, 1 on failure.
 * @ingroup SinglyLinkedList
 */
int sll_insert_node(sll_t *sll, int pos, void *data);

/**
 * @brief Deletes the first node of the linked list.
 * @param sll A pointer to the linked list.
 * @return A pointer to the data of the deleted node, or NULL on failure.
 * @note The caller is responsible for freeing the memory of the returned data.
 * @ingroup SinglyLinkedList
 */
void *sll_delete_head_node(sll_t *sll);

/**
 * @brief Deletes the last node of the linked list.
 * @param sll A pointer to the linked list.
 * @return A pointer to the data of the deleted node, or NULL on failure.
 * @note The caller is responsible for freeing the memory of the returned data.
 * @ingroup SinglyLinkedList
 */
void *sll_delete_tail_node(sll_t *sll);

/**
 * @brief Deletes a node at a specific position in the linked list.
 * @param sll A pointer to the linked list.
 * @param pos The 0-based position of the node to delete.
 * @return A pointer to the data of the deleted node, or NULL on failure.
 * @note The caller is responsible for freeing the memory of the returned data.
 * @ingroup SinglyLinkedList
 */
void *sll_delete_node( sll_t *sll, int pos);

/**
 * @brief Reverses the order of the linked list.
 * @param sll A pointer to the linked list.
 * @return 0 on success, 1 on failure.
 * @ingroup SinglyLinkedList
 */
int sll_reverse_linked_list(sll_t *sll);

/**
 * @brief Gets the size of the linked list.
 * @param sll A pointer to the linked list.
 * @return The number of nodes in the linked list.
 * @ingroup SinglyLinkedList
 */
int sll_get_length(sll_t *sll);

/**
 * @brief Gets the head node of the linked list.
 * @param sll A pointer to the linked list.
 * @return A pointer to the head node of the linked list.
 * @ingroup SinglyLinkedList
 */
sll_node_t *sll_get_head(sll_t *sll);

/**
 * @brief Prints a single node.
 * @param node A pointer to the node to print.
 * @ingroup SinglyLinkedList
 */
void sll_print_node(sll_node_t *node);

/**
 * @brief Prints the entire linked list.
 * @param sll A pointer to the linked list.
 * @ingroup SinglyLinkedList
 */
void sll_print_linked_list(sll_t *sll);

#endif // SINGLYLINKEDLIST_H