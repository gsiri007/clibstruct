#include "singlylinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// node 
typedef struct SllNode {
    void *data;
    struct SllNode *next;
} sll_node_t;

// singlylinkedlist
typedef struct Sll {
    int length;
    sll_node_t *head;
} sll_t;

sll_t *sll_create_linked_list() {
    // initiating a new linked list
    sll_t *sll = (sll_t *) malloc(sizeof(sll_t));
    if (sll == NULL) {
        return NULL;
    }

    sll->length = 0;
    sll->head   = NULL;
    return sll;
}

int sll_add_head_node(sll_t *sll, void *data) {
    // creating a new node
    sll_node_t *new_node = (sll_node_t *) malloc(sizeof(sll_node_t));
    if (new_node == NULL) {
        return 1;
    }

    new_node->data = data;
    new_node->next = sll->head;

    sll->head = new_node;
    (sll->length)++;

    return 0;
}

int sll_add_tail_node(sll_t *sll, void *data) {
    // creating a new node
    sll_node_t *new_node = (sll_node_t *) malloc(sizeof(sll_node_t));

    if (new_node == NULL) {
        return 1;
    }

    new_node->data = data;
    new_node->next = NULL;

    // empty list 
    if (sll->length == 0) {
        sll_add_head_node(sll, data);
        return 0;
    }

    // non-empty list
    sll_node_t *current_node = sll->head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    (sll->length)++;

    return 0;
}


int sll_insert_node(sll_t *sll, int pos, void *data) {
    // lower bound check and upper bound check
    if (pos < 0 || pos > sll->length) {
        return 1;
    }

    // for an empty list can't insert to a pos > 0
    if (pos > 0 && sll->length == 0) {
        return 1;
    }

    // insert at begining and to an empty list
    if (pos == 0) { 
        return sll_add_head_node(sll, data);
    }

    // insert at end of the list
    if (pos == sll->length) {
        return sll_add_tail_node(sll, data);
    }

    // inserting new node at pos
    sll_node_t *current_node = sll->head;
    for (int i = 0; i < pos - 1; ++i) {
        current_node = current_node->next;
    }

    sll_node_t *new_node = (sll_node_t *) malloc(sizeof(sll_node_t));
    if (new_node == NULL) {
        return 1;
    }

    new_node->data = data;
    new_node->next = current_node->next;
    current_node->next = new_node;

    (sll->length)++;

    return 0;
}

void *sll_delete_head_node(sll_t *sll) {
    // empty check
    if (sll->length == 0) {
        return NULL;
    }

    //delete current head node
    sll_node_t *tmp = sll->head;
    sll->head = sll->head->next;

    void *data = tmp->data;
    free(tmp);
    tmp = NULL;

    (sll->length)--;

    return data;
}

void *sll_delete_tail_node(sll_t *sll) {
    // empty check
    if (sll->length == 0) {
        return NULL;
    }

    // single node 
    if (sll->head->next == NULL) {
        void *data = sll->head->data;

        free(sll->head);
        sll->head = NULL;

        (sll->length)--;

        return data;
    }

    // multiple nodes
    sll_node_t *current_node= sll->head;

    while (!(current_node->next->next == NULL)) {
        current_node = current_node->next;
    }

    void *data = current_node->next->data;
    free(current_node->next);
    current_node->next = NULL;

    (sll->length)--;

    return data;
}


void *sll_delete_node( sll_t *sll, int pos) {
    // empty check
    if (sll->length == 0) {
        return NULL;
    }

    // lower bound and upper bound check
    if (pos < 0 || pos >= sll->length) {
        return NULL;
    }

    // delete current head node
    if (pos == 0) {
        return sll_delete_head_node(sll);
    }

    // delete current tail node
    if (pos == (sll->length) - 1) {
        return sll_delete_tail_node(sll);
    }

    // delete node at pos
    sll_node_t *current_node = sll->head;

    for (int i = 0; i < pos - 1; ++i) {
        current_node = current_node->next;
    }

    sll_node_t *tmp = current_node->next;
    current_node->next = current_node->next->next;

    void *data = tmp->data;
    free(tmp);
    tmp = NULL;

    (sll->length)--;

    return data;
}

int sll_reverse_linked_list(sll_t *sll) {
    // empty check
    if (sll->length == 0) {
        return 1;
    }

    sll_node_t *prev_node = NULL;
    sll_node_t *current_node = sll->head;
    sll_node_t *next_node = sll->head->next;

    for (int i = 0; i < sll->length; ++i) {
        if (next_node == NULL) {
            current_node->next = prev_node;
            sll->head = current_node;
            break;
        }

        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
        next_node = next_node->next;
    }

    return 0;

}

int sll_get_length(sll_t *sll) {
    return sll->length;
}

sll_node_t *sll_get_head(sll_t *sll) {
    return sll->head;
}

void sll_print_node(sll_node_t *node) {
    // empty check
    if (node == NULL) {
        return;
    }

    // print node
    printf("data = %p | next = %p\n", node->data, node->next);
}

void sll_print_linked_list(sll_t *sll) {
    // empty check
    if (sll->length == 0) {
        puts("<empty>");
        return;
    }

    // print linkedlist
    sll_node_t *current_node = sll->head;

    while (current_node != NULL) {
        sll_print_node(current_node);
        current_node = current_node->next;
    }

}
