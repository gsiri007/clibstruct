#ifndef QUEUE_H
#define QUEUE_H 

typedef struct Queue queue_t;

queue_t *create_queue();
int enqueue(void *data, queue_t *queue);
void *dequeue(queue_t *queue);
void *peek_queue(queue_t *queue);
int is_empty_queue(queue_t *queue);

#endif //QUEUE_H
