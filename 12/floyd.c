#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

bool find_loop(Node *node) {
    if (node == NULL) return false;
    
    Node *turtle = node;
    Node *hare = node;

    while (hare != NULL && hare->next != NULL) {
        turtle = turtle->next;
        hare = hare->next->next;
        if (turtle == hare) return true;
    }
    return false;
}

int main() {
    // Création d'une liste avec une boucle
    Node *head = malloc(sizeof(Node));
    head->value = 0;
    head->next = NULL;
    
    Node *prev = head;
    Node *third = NULL; 
    for (int i = 1; i < 10; i++) {
        Node *node = malloc(sizeof(Node));
        node->value = i;
        node->next = NULL;
        prev->next = node;
        prev = node;        
        if (i == 3) third = node;
    }
    prev->next = third;
    
    // Test
    if (find_loop(head))
        printf("Boucle détectée !\n");
    else
        printf("Pas de boucle.\n");
}