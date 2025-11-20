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

int addEndNode(int data, node_t *headPtr) {
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    if (newNode == NULL) {
        return -1;
    }

    node_t *ptr = headPtr;
    while (true) {
        if (ptr->next == NULL) {
            ptr->next  = newNode;
            newNode->data = data;
            newNode->next = NULL;
            return 0;
        }

        ptr = ptr->next;
    }

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
    int size = sizeLinkedList(*headPtr);

    // out of bound check
    if (pos >= size || pos < 0) {
        return -1;
    }

    // insert at begining
    if (pos == 0) { 
        return addBeginNode(data, headPtr);
    }

    // insert at end
    if (pos == size - 1) {
        return addEndNode(data, *headPtr);
    }

    // insert at given position
    int count = 0;
    node_t *ptr = *headPtr;
    //TODO:
    while (count == pos) {
        ptr = ptr->next;
        count++;
    }

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

    while (true) {
        if (ptr->next == NULL) {
            prevNode->next = NULL;
            free(ptr);
            return 0;
        }

        prevNode = ptr;
        ptr = ptr->next;
    }

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

int deleteLinkedList(node_t **headPtr) {
    // empty check
    if (*headPtr == NULL) {
        return 0;
    }

    node_t *ptr = *headPtr;
    while (true) {
        if (ptr->next == NULL) {
            free(ptr);
            *headPtr = NULL;
            return 0;
        }

        node_t *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }

}

int reverseLinkedList(node_t **headPtr) {
    // empty check
    if (*headPtr == NULL) {
        return -1;
    }

    node_t *ptr = *headPtr;
    node_t *prevNode = NULL;
    node_t *nextNode = ptr->next;

    while (true) {
        if (nextNode == NULL) {
            ptr->next = prevNode;
            *headPtr = ptr;
            return 0;
        }

        ptr->next = prevNode;
        prevNode = ptr;
        ptr = nextNode;
        nextNode = ptr->next;
    }

}

int sizeLinkedList(node_t *headPtr) {
    // empty check
    if (headPtr == NULL) {
        return 0;
    }

    int count = 0;

    node_t *ptr = headPtr;

    while (true) {
        count++;
        if (ptr->next == NULL) {
            return count;
        }
        ptr = ptr->next;
    }
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

    while (true) {
        printNode(headPtr);

        if (headPtr->next == NULL) {
            break;
        }

        headPtr = headPtr->next;
    }
}
