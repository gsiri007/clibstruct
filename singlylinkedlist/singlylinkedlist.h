#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdbool.h>

/**
 * @brief A node in a singly linked list.
 */
typedef struct Node {
    int data; /**< The data for the node. */
    struct Node *next; /**< A pointer to the next node in the list. */
} node_t;


/**
 * @brief Creates a new linked list.
 * @param data The data for the first node.
 * @return A pointer to the head of the new linked list, or NULL on failure.
 */
node_t *createLinkedList(int data);

/**
 * @brief Adds a new node to the end of the linked list.
 * @param data The data for the new node.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 */
int addEndNode(int data, node_t *headPtr);

/**
 * @brief Adds a new node to the beginning of the linked list.
 * @param data The data for the new node.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 */
int addBeginNode(int data, node_t **headPtr);

/**
 * @brief Inserts a new node at a specific position in the linked list.
 * @param pos The position to insert the new node at.
 * @param data The data for the new node.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 */
int insertNode(int pos, int data, node_t **headPtr);

/**
 * @brief Deletes the last node of the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 */
int deleteEndNode(node_t **headPtr);

/**
 * @brief Deletes the first node of the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 */
int deleteBeginNode(node_t **headPtr);

/**
 * @brief Deletes the entire linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return 0 on success, -1 on failure.
 */
int deleteLinkedList(node_t **headPtr);

int reverseLinkedList(node_t **headPtr);

/**
 * @brief Gets the size of the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return The number of nodes in the linked list.
 */
int sizeLinkedList(node_t *headPtr);

/**
 * @brief Gets the number of bytes occupied by the linked list.
 * @param headPtr A pointer to the head of the linked list.
 * @return The number of bytes occupied by the linked list.
 */
int bytesLinkedList(node_t *headPtr);

/**
 * @brief Prints a single node.
 * @param node A pointer to the node to print.
 */
void printNode(node_t *node);

/**
 * @brief Prints the entire linked list.
 * @param head A pointer to the head of the linked list.
 */
void printLinkedList(node_t *head);

#endif // SINGLYLINKEDLIST_H
