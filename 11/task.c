#include "task.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Task* create_task(int priority, const char *name) {
    if (name == NULL) return NULL;
    if (priority < 0 || priority > 100) return NULL;
    Task *t = malloc(sizeof(Task));
    if (t == NULL) return NULL;
    strncpy(t->name, name, sizeof(t->name) - 1);
    t->name[63] = '\0';
    t->priority = priority;
    t->next = NULL;
    return t;
}

int add(Task **head, int priority, const char *name) {
    if (head == NULL) return -1;
    Task *t = create_task(priority, name);
    if (t == NULL) return -1;
    Task **cur = head;

    while(*cur != NULL && (*cur)->priority >= priority) cur = &(*cur)->next;
    t->next = *cur;
    *cur = t;
    return 0;
}

void print(Task *head) {
    for (const Task *t = head; t != NULL; t = t->next) 
        printf("%d %s\n", t->priority, t->name);
}

int pop(Task **head, char *dest) {
    strcpy(dest, "");
    if (head == NULL || *head == NULL || dest == NULL) return -1;
    Task *el = *head;
    *head = el->next;
    strcpy(dest, el->name);
    free(el);
    return 0;
}

void clear(Task **head) {
    if (head == NULL || *head == NULL) return;
    Task *walker = *head;
    while (walker != NULL) {
        Task *next = walker->next;
        free(walker);
        walker = next;
    }
    *head = NULL;
}
