#include <stdlib.h>
#include <stdio.h>
#include "doublylinkedlist.h"

dll_node_t *dll_create_linked_list(void *data) {
    dll_node_t *headPtr = (dll_node_t *) malloc(sizeof(dll_node_t));
    if (headPtr == NULL) {
        return NULL;
    }

    headPtr->prev = NULL;
    headPtr->data = data;
    headPtr->next = NULL;

    return headPtr;
}

int dll_add_end_node(void *data, dll_node_t **headPtr) {
    dll_node_t *newNode = (dll_node_t *) malloc(sizeof(dll_node_t));
    if (newNode == NULL) {
        return 0;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*headPtr == NULL) {
        newNode->prev = NULL;
        *headPtr = newNode;
        return 1;
    }

    dll_node_t *ptr = *headPtr;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->prev = ptr;
    return 1;
}

int dll_add_begin_node(void *data, dll_node_t **headPtr) {
    dll_node_t *newNode = (dll_node_t *) malloc(sizeof(dll_node_t));
    if (newNode == NULL) {
        return 0;
    }

    newNode->prev = NULL;
    newNode->data = data;

    if (*headPtr == NULL) {
        newNode->next = NULL;
        *headPtr = newNode;
        return 1;
    }

    newNode->next = *headPtr;
    (*headPtr)->prev = newNode;
    *headPtr = newNode;
    return 1;
}

int dll_insert_node(int pos, void *data, dll_node_t **headPtr) {
    // lower bound check
    if (pos < 0) {
        return 0;
    }

    // insert at begining and to an empty list
    if (pos == 0) { 
        return dll_add_begin_node(data, headPtr);
    }

    // for an empty list can't insert to a pos > 0
    if (pos > 0 && *headPtr == NULL) {
        return 0;
    }

    int size = dll_size_linked_list(*headPtr);

    // upper bound check
    if (pos > size) {
        return 0;
    }

    // insert at given position
    int count = 0;
    dll_node_t *ptr = *headPtr;
    dll_node_t *prevNode = NULL;
    while (count != pos) {
        prevNode = ptr;
        ptr = ptr->next;
        count++;
    }

    dll_node_t *newNode = (dll_node_t *) malloc(sizeof(dll_node_t));
    if (newNode == NULL) {
        return 0;
    }

    prevNode->next = newNode;
    newNode->prev  = prevNode;
    newNode->data  = data;
    newNode->next  = ptr;
    ptr->prev      = newNode;

    return 1;

}

void *dll_delete_end_node(dll_node_t **headPtr) {
    // empty check
    if (*headPtr == NULL) {
        return NULL;
    }

    // single node case
    if ((*headPtr)->next == NULL) {
        void *data = (*headPtr)->data;
        free(*headPtr);
        *headPtr = NULL;
        return data;
    }

    dll_node_t *ptr = *headPtr;
    dll_node_t *prevNode = ptr;

    while (ptr->next != NULL) {
        prevNode = ptr;
        ptr = ptr->next;
    }

    prevNode->next = NULL;
    void *data = ptr->data;
    free(ptr);

    return data;
}

void *dll_delete_begin_node(dll_node_t **headPtr) {
    // empty check
    if (*headPtr == NULL) {
        return NULL;
    }

    dll_node_t *tmp = *headPtr;
    *headPtr = (*headPtr)->next;
    (*headPtr)->prev = NULL;
    void *data = tmp->data;
    free(tmp);

    return data;
}

void *dll_delete_node(int pos, dll_node_t **headPtr) {
    // empty check
    if (*headPtr == NULL) {
        return NULL;
    }

    // lower bound check
    if (pos < 0) {
        return NULL;
    }

    int size = dll_size_linked_list(*headPtr);

    // upper bound check
    if (pos >= size) {
        return NULL;
    }

    if (pos == 0) {
        return dll_delete_begin_node(headPtr);
    }

    int count = 0;
    dll_node_t *ptr = *headPtr;
    dll_node_t *prevPtr = ptr;
    while (count != pos) {
        count++;
        prevPtr = ptr;
        ptr = ptr->next;
    }

    dll_node_t *tmp = ptr;
    ptr = ptr->next;
    prevPtr->next = ptr;
    ptr->prev = prevPtr;
    void *data = tmp->data;
    free(tmp);

    return data;
}

int dll_reverse_linked_list(dll_node_t **headPtr) {
    // empty check
    if (*headPtr == NULL) {
        return 0;
    }

    dll_node_t *ptr = *headPtr;
    dll_node_t *prevNode = NULL;
    dll_node_t *nextNode = ptr->next;

    while (nextNode != NULL) {
        ptr->prev = ptr->next;
        ptr->next = prevNode;
        prevNode = ptr;
        ptr = nextNode;
        nextNode = ptr->next;
    }

    ptr->prev = ptr->next;
    ptr->next = prevNode;
    *headPtr = ptr;
    return 1;
}

int dll_size_linked_list(dll_node_t *headPtr) {
    // empty check
    if (headPtr == NULL) {
        return 0;
    }

    int count = 0;
    dll_node_t *ptr = headPtr;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    return count;
}

int dll_bytes_linked_list(dll_node_t *headPtr) { 
    int numNodes = dll_size_linked_list(headPtr);
    int bytesPerNode =  sizeof(dll_node_t);
    return numNodes * bytesPerNode; 
}

void dll_print_node(dll_node_t *node) {
    // empty check
    if (node == NULL) {
        return;
    }

    printf("prev = %p | data = %p | next = %p\n", (void*)node->prev, node->data, (void*)node->next);
}

void dll_print_linked_list(dll_node_t *headPtr) {
    // empty check
    if (headPtr == NULL) {
        puts("<empty>");
        return;
    }

    dll_node_t *ptr = headPtr;

    while (ptr != NULL) {
        dll_print_node(ptr);
        ptr = ptr->next;
    }
}
