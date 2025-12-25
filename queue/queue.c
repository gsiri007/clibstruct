#include <stdlib.h>
#include "../singlylinkedlist/singlylinkedlist.h"

typedef struct Queue {
    sll_node_t *front;
    sll_node_t *rear;
} queue_t;

queue_t *create_queue() {
    queue_t *queue = (queue_t *) malloc(sizeof(queue_t));
    if (queue == NULL) {
        return NULL;
    }

    sll_node_t *head = sll_create_linked_list(NULL);

    if (head == NULL) {
        return NULL;
    }

    queue->front = head;
    queue->rear  = head;

    return queue;
}

int enqueue(void *data, queue_t *queue) {
    //TODO:
}

int is_empty_queue(queue_t *queue) {
    if (queue->front->data == NULL && queue->rear->data == NULL) {
        return 1;
    }
    return 0;
}
