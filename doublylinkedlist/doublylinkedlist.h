/**
 * @file doublylinkedlist.h
 * @brief A library for creating and manipulating doubly linked lists of generic data.
 * @note This library stores data using `void*` pointers, allowing it to store
 * any data type. The user is responsible for managing the memory of the data
 * stored in the list. This includes allocating memory for the data before
 * insertion and freeing it after deletion or when the list is destroyed.
 */
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

/**
 * @addtogroup DoublyLinkedList
 * @{
 */

/**
 * @brief A node in a doubly linked list.
 */
typedef struct DllNode {
    struct DllNode *prev; /**< A pointer to the previous node in the list. */
    struct DllNode *next; /**< A pointer to the next node in the list. */
    void *data; /**< The data for the node. */
} dll_node_t;

/**
 * @brief Creates a new linked list.
 * @param data The data for the first node.
 * @return A pointer to the head of the new linked list, or NULL on failure.
 */
dll_node_t *dll_create_linked_list(void *data);

/**
 * @brief Adds a new node to the end of the linked list.
 * @param data The data for the new node.
 * @param headPtr A pointer to the head of the linked list.
 * @return 1 on success, 0 on failure.
 */
int dll_add_end_node(void *data, dll_node_t **headPtr);

/**
 * @brief Adds a new node to the beginning of the linked list.
 * @param data The data for the new node.
 * @param headPtr A pointer to the head of the linked list.
 * @return 1 on success, 0 on failure.
 */
int dll_add_begin_node(void *data, dll_node_t **headPtr);

/**
 * @brief Inserts a new node at a specific position in the linked list.
 * @param pos The position to insert the new node at.
 * @param data The data for the new node.
 * @param headPtr A pointer to the head of the linked list.
 * @return 1 on success, 0 on failure.
 */
int dll_insert_node(int pos, void *data, dll_node_t **headPtr);

/**
 * @brief Deletes the last node of the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return A pointer to the data of the deleted node, or NULL on failure.
 * @note The caller is responsible for freeing the memory of the returned data.
 */
void *dll_delete_end_node(dll_node_t **headPtr);

/**
 * @brief Deletes the first node of the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return A pointer to the data of the deleted node, or NULL on failure.
 * @note The caller is responsible for freeing the memory of the returned data.
 */
void *dll_delete_begin_node(dll_node_t **headPtr);

/**
 * @brief Deletes a node at a specific position in the linked list.
 * @param pos The 0-based position of the node to delete.
 * @param headPtr A pointer to the head of the linked list.
 * @return A pointer to the data of the deleted node, or NULL on failure.
 * @note The caller is responsible for freeing the memory of the returned data.
 */
void *dll_delete_node(int pos, dll_node_t **headPtr);

/**
 * @brief Reverses the order of the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return 1 on success, 0 on failure.
 */
int dll_reverse_linked_list(dll_node_t **headPtr);

/**
 * @brief Gets the size of the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return The number of nodes in the linked list.
 */
int dll_size_linked_list(dll_node_t *headPtr);

/**
 * @brief Gets the number of bytes occupied by the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return The number of bytes occupied by the linked list.
 */
int dll_bytes_linked_list(dll_node_t *headPtr);

/**
 * @brief Prints a single node.
 * @param node A pointer to the node to print.
 */
void dll_print_node(dll_node_t *node);

/**
 * @brief Prints the entire linked list.
 * @param head A pointer to the head of the linked list.
 */
void dll_print_linked_list(dll_node_t *head);

/** @} */

#endif //DOUBLYLINKEDLIST_H