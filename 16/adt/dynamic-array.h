#pragma once // Éviter la réentrence d'un fichier d'en-tête

#include <stdbool.h>

typedef struct array Array;

bool array_push_back(Array *a, int value);
bool array_pop_back(Array *a, int *value); 
bool array_get_value(Array *a, int index); // a[k]