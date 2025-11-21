/**
 * @file singlylinkedlist.h
 * @brief A library for creating and manipulating singly linked lists.
 */
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdbool.h>

/**
 * @brief A node in a singly linked list.
 * @ingroup SinglyLinkedList
 */
typedef struct Node {
    int data; /**< The data for the node. */
    struct Node *next; /**< A pointer to the next node in the list. */
} node_t;


/**
 * @brief Creates a new linked list.
 * @param data The data for the first node.
 * @return A pointer to the head of the new linked list, or NULL on failure.
 * @ingroup SinglyLinkedList
 */
node_t *createLinkedList(int data);

/**
 * @brief Adds a new node to the end of the linked list.
 * @param data The data for the new node.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 * @ingroup SinglyLinkedList
 */
int addEndNode(int data, node_t **headPtr);

/**
 * @brief Adds a new node to the beginning of the linked list.
 * @param data The data for the new node.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 * @ingroup SinglyLinkedList
 */
int addBeginNode(int data, node_t **headPtr);

/**
 * @brief Inserts a new node at a specific position in the linked list.
 * @param pos The position to insert the new node at.
 * @param data The data for the new node.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 * @ingroup SinglyLinkedList
 */
int insertNode(int pos, int data, node_t **headPtr);

/**
 * @brief Deletes the last node of the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 * @ingroup SinglyLinkedList
 */
int deleteEndNode(node_t **headPtr);

/**
 * @brief Deletes the first node of the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 * @ingroup SinglyLinkedList
 */
int deleteBeginNode(node_t **headPtr);

/**
 * @brief Deletes a node at a specific position in the linked list.
 * @param pos The 0-based position of the node to delete.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 * @ingroup SinglyLinkedList
 */
int deleteNode(int pos, node_t **headPtr);

/**
 * @brief Deletes the entire linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 * @ingroup SinglyLinkedList
 */
int deleteLinkedList(node_t **headPtr);

/**
 * @brief Reverses a linked list in place.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 * @ingroup SinglyLinkedList
 */
int reverseLinkedList(node_t **headPtr);

/**
 * @brief Gets the size of the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return The number of nodes in the linked list.
 * @ingroup SinglyLinkedList
 */
int sizeLinkedList(node_t *headPtr);

/**
 * @brief Gets the number of bytes occupied by the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return The number of bytes occupied by the linked list.
 * @ingroup SinglyLinkedList
 */
int bytesLinkedList(node_t *headPtr);

/**
 * @brief Prints a single node.
 * @param node A pointer to the node to print.
 * @ingroup SinglyLinkedList
 */
void printNode(node_t *node);

/**
 * @brief Prints the entire linked list.
 * @param head A pointer to the head of the linked list.
 * @ingroup SinglyLinkedList
 */
void printLinkedList(node_t *head);

#endif // SINGLYLINKEDLIST_H
