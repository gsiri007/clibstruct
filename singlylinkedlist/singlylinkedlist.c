#include "singlylinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

node_t *createLinkedList(int data) {
    node_t *headPtr = (node_t *) malloc(sizeof(node_t));
    if (headPtr == NULL) {
        return NULL;
    }

    headPtr->data = data;
    headPtr->next = NULL;
    return headPtr;
}

int addEndNode(int data, node_t **headPtr) {
    node_t *newNode = (node_t *) malloc(sizeof(node_t));

    if (newNode == NULL) {
        return -1;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*headPtr == NULL) {
        *headPtr = newNode;
        return 0;
    }

    node_t *ptr = *headPtr;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    return 0;
}

int addBeginNode(int data, node_t **headPtr) {
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    if (newNode == NULL) {
        return -1;
    }

    newNode->data = data;
    newNode->next = *headPtr;

    *headPtr = newNode;

    return 0;
}

int insertNode(int pos, int data, node_t **headPtr) {
    // lower bound check
    if (pos < 0) {
        return -1;
    }

    // insert at begining and to an empty list
    if (pos == 0) { 
        return addBeginNode(data, headPtr);
    }

    // for an empty list can't insert to a pos > 0
    if (pos > 0 && *headPtr == NULL) {
        return -1;
    }

    int size = sizeLinkedList(*headPtr);

    // upper bound check
    if (pos > size) {
        return -1;
    }

    // insert at given position
    int count = 0;
    node_t *ptr = *headPtr;
    node_t *prevNode = NULL;
    while (count != pos) {
        prevNode = ptr;
        ptr = ptr->next;
        count++;
    }

    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    if (newNode == NULL) {
        return -1;
    }

    prevNode->next = newNode;
    newNode->next  = ptr;
    newNode->data  = data;
    return 0;
}

int deleteEndNode(node_t **headPtr) {
    // empty check
    if (*headPtr == NULL) {
        return -1;
    }

    // single node case
    if ((*headPtr)->next == NULL) {
        free(*headPtr);
        *headPtr = NULL;
        return 0;
    }

    node_t *ptr = *headPtr;
    node_t *prevNode = ptr;

    while (ptr->next != NULL) {
        prevNode = ptr;
        ptr = ptr->next;
    }

    prevNode->next = NULL;
    free(ptr);
    return 0;
}

int deleteBeginNode(node_t **headPtr) {
    // empty check
    if (*headPtr == NULL) {
        return -1;
    }

    node_t *temp = *headPtr;
    *headPtr = (*headPtr)->next;
    free(temp);
    return 0;
}

int deleteNode(int pos, node_t **headPtr) {
    // empty check
    if (*headPtr == NULL) {
        return -1;
    }

    // lower bound check
    if (pos < 0) {
        return -1;
    }

    int size = sizeLinkedList(*headPtr);

    // upper bound check
    if (pos >= size) {
        return -1;
    }

    if (pos == 0) {
        return deleteBeginNode(headPtr);
    }

    int count = 0;
    node_t *ptr = *headPtr;
    node_t *prevPtr = ptr;
    while (count != pos) {
        count++;
        prevPtr = ptr;
        ptr = ptr->next;
    }

    node_t *tmp = ptr;
    ptr = ptr->next;
    prevPtr->next = ptr;
    free(tmp);

    return 0;
}

int deleteLinkedList(node_t **headPtr) {
    // empty check
    if (*headPtr == NULL) {
        return 0;
    }

    node_t *ptr = *headPtr;
    while (ptr->next != NULL) {
        node_t *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }

    free(ptr);
    *headPtr = NULL;
    return 0;

}

int reverseLinkedList(node_t **headPtr) {
    // empty check
    if (*headPtr == NULL) {
        return -1;
    }

    node_t *ptr = *headPtr;
    node_t *prevNode = NULL;
    node_t *nextNode = ptr->next;

    while (nextNode != NULL) {
        ptr->next = prevNode;
        prevNode = ptr;
        ptr = nextNode;
        nextNode = ptr->next;
    }

    ptr->next = prevNode;
    *headPtr = ptr;
    return 0;

}

int sizeLinkedList(node_t *headPtr) {
    // empty check
    if (headPtr == NULL) {
        return 0;
    }

    int count = 0;
    node_t *ptr = headPtr;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    return count;
}

int bytesLinkedList(node_t *headPtr) { 
    int numNodes = sizeLinkedList(headPtr);
    int bytesPerNode =  sizeof(node_t);
    return numNodes * bytesPerNode; 
}


void printNode(node_t *node) {
    // empty check
    if (node == NULL) {
        return;
    }

    printf("data = %d | next = %p\n", node->data, node->next);
}

void printLinkedList(node_t *headPtr) {
    // empty check
    if (headPtr == NULL) {
        puts("<empty>");
        return;
    }

    node_t *ptr = headPtr;

    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
}
