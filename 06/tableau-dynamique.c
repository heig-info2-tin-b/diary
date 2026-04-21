#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    size_t elements;
    size_t capacity;
    int *data;
} Vector;

int vector_get(const Vector *v, size_t i) {
    if (i >= v->elements) {
        fprintf(stderr, "Indice hors limites\n");
        exit(EXIT_FAILURE);
    }
    return v->data[i];
}

void vector_push_back(Vector *v, int value) {
    if (v->elements == v->capacity) {
        v->capacity *= 2;
        int *tmp = realloc(v->data, v->capacity * sizeof(int));
        if (tmp == NULL) {
            fprintf(stderr, "Erreur realloc\n");
            exit(EXIT_FAILURE);
        }
        v->data = tmp;
    }
    v->data[v->elements] = value;
    v->elements++;
}

int vector_pop_back(Vector *v) {
    if (v->elements == 0) {
        fprintf(stderr, "Vector vide\n");
        exit(EXIT_FAILURE);
    }
    v->elements--;
    return v->data[v->elements];
}

int vector_pop_front(Vector *v) {
    if (v->elements == 0) {
        fprintf(stderr, "Vector vide\n");
        exit(EXIT_FAILURE);
    }

    int first_value = v->data[0];
    for (size_t i = 0; i < v->elements - 1; i++) {
        v->data[i] = v->data[i + 1];
    }
    v->elements--;
    return first_value;
}

void vector_push_front(Vector *v, int value) {
    if (v->elements == v->capacity) {
        v->capacity *= 2;
        int *tmp = realloc(v->data, v->capacity * sizeof(int));
        if (tmp == NULL) {
            fprintf(stderr, "Erreur realloc\n");
            exit(EXIT_FAILURE);
        }
        v->data = tmp;
    }

    for (size_t i = v->elements; i > 0; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[0] = value;
    v->elements++;
}

void vector_init(Vector *v) {
    v->capacity = 1;
    v->elements = 0;
    v->data = malloc(v->capacity * sizeof(int));
    if (v->data == NULL) {
        fprintf(stderr, "Erreur malloc\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    Vector v;
    vector_init(&v);

    vector_push_back(&v, 42);
    vector_push_front(&v, 23);

    printf("Valeur: %d\n", vector_get(&v, 1));

    int x = vector_pop_back(&v);
    int w = vector_pop_front(&v);

    printf("x = %d, w = %d\n", x, w);

    free(v.data);
}