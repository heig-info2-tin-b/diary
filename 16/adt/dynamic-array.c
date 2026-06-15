#include "dynamic-array.h"
#include <stdlib.h>
struct array {
    int *data;
    int capacity;
    int elements;
};

bool array_push_back(struct array *a, int value) {
    if (!a) return false;
    if (a->elements >= a->capacity) {
        int *p = realloc(a->data, a->capacity *= 2);
        if (!p) return false;
        a->data;
    }
    a->data[a->elements++] = value; 
}

bool array_pop_back(struct array *a, int *value) {
}

bool array_get_value(struct array *a, int index) {
}