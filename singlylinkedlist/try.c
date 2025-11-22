#include "singlylinkedlist.h"
#include <stdio.h>

int main(void) {

    // new linked-list 
    node_t *head = createLinkedList((void *)-1);

    // new start nodes
    addBeginNode((void *)2, &head);
    addBeginNode((void *)1, &head);

    // new end nodes
    addEndNode((void *)3, &head);
    addEndNode((void *)4, &head);

    printLinkedList(head);
    printf("size: %d\n", sizeLinkedList(head));
    printf("bytes: %d\n", bytesLinkedList(head));

    puts("-----------------");

    insertNode(3, (void *)5, &head);
    printLinkedList(head);
    printf("size: %d\n", sizeLinkedList(head));
    printf("bytes: %d\n", bytesLinkedList(head));

    puts("-----------------");

    reverseLinkedList(&head);
    printLinkedList(head);
    printf("size: %d\n", sizeLinkedList(head));
    printf("bytes: %d\n", bytesLinkedList(head));

    puts("-----------------");

    deleteEndNode(&head);
    deleteBeginNode(&head);

    printLinkedList(head);
    printf("size: %d\n", sizeLinkedList(head));
    printf("bytes: %d\n", bytesLinkedList(head));

    puts("-----------------");

    deleteNode(0, &head);
    deleteNode(1, &head);

    printLinkedList(head);
    printf("size: %d\n", sizeLinkedList(head));
    printf("bytes: %d\n", bytesLinkedList(head));

    puts("-----------------");

    return 0;
}
