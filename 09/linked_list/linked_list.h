#pragma once
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct linked_list {
    Node *head;
    Node *tail; 
} LinkedList;


void linked_list_init(LinkedList *list);
void linked_list_push_back(LinkedList *list, int value);
void linked_list_push_front(LinkedList *list, int value);
void linked_list_pop_back(LinkedList *list, int *value);
void linked_list_pop_front(LinkedList *list, int *value);
void linked_list_get(LinkedList *list, size_t index, int *value);
void linked_list_insert_after(LinkedList *list, Node *node, int *value);
void linked_list_delete(LinkedList *list, Node *node);
