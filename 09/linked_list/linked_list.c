#include "linked_list.h"

void linked_list_init(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}

void linked_list_push_back(LinkedList *list, int value) {
    if (list->head == NULL) {
        // Empty list, add first element
    } else {
        // Append one element at the end
        Node *node = malloc(sizeof(Node));
        if (node == NULL) abort();
    }
}
