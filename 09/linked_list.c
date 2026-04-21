#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} Node;


int main() {
    Node d = { .value = 42, .next = NULL };
    Node c = { .value = 15, .next = &d };
    Node b = { .value = 8, .next = &c };
    Node a = { .value = 4, .next = &b };

    d.next = &a; // Aïe !

    Node *walker = &a;
    if (walker == NULL) abort();
    do {
        printf("%d->", walker->value);
        walker = walker->next;
    } while(walker != NULL);
}