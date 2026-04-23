#include <stdio.h> 
#include "linked_list.h"

int main() {
    LinkedList list;

    linked_list_init(&list);
    linked_list_push_back(&list, 4);
    linked_list_push_back(&list, 8);
    linked_list_push_back(&list, 15);
    linked_list_push_back(&list, 16);
    linked_list_push_back(&list, 23);
    linked_list_push_back(&list, 42);

    Node *walker = list.head;
    if (walker == NULL) return 0;
    do {
        printf("%d->", walker->value);
        walker = walker->next;
    } while(walker != NULL);
    printf("NULL\n");
}