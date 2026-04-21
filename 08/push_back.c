#include <stdlib.h>

typedef struct data {
    int *data; // Un pointeur sur les données
    size_t elements; // Nombre actuel d'éléments
    size_t capacity; // L'espace mémoire du tableau
} Data;

void push_back(Data *data, int value) {
    if (data->elements >= data->capacity)
        data = realloc(data, (data->capacity *= 1.5) * sizeof(data[0]));
    assert(data);
    data->data[data->elements++] = value;
}