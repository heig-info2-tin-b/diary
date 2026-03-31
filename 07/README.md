# Semaine 07/16

- [x] Classes de stockage

## Variable

```c
{
   int i = 42; // Modifiable
   printf("Valeur de i: %d\n", i);
   printf("Adresse de i: %p\n", &i);
} // Scope de i se termine ici, i n'est plus accessible
```

- Nom
- Type
- Valeur
- Adresse
- Durée de vie
- Portée
- Classe de stockage

## Toutes les classes de stockage

- [x] const
- [x] static
- [x] register
- [x] extern
- [x] volatile (qui se prononce "volataïle")
- [x] auto 
- [x] restrict

### Const

Indique qu'une variable ne peut pas être modifiée après son initialisation.

```c
const int x = 10; // x est une constante, sa valeur ne peut pas être modifiée

// Hack !
int *ptr = (int *)&x; // Contourne la constance
*ptr = 20; // Modifie la valeur de x malgré la constance
printf("Valeur de x: %d\n", x); // Affiche 20, pas 10
```

Important: Modifier une variable déclarée comme `const` est un comportement indéfini en C. Cela peut entraîner des résultats imprévisibles, y compris des plantages du programme ou des données corrompues. Il est fortement déconseillé de contourner la constance d'une variable, car cela viole les garanties de sécurité et de stabilité du code.

#### Cas des Pointeurs


```c
int x;

const int *ptr1 = &x; // Rend la valeur pointée constante, pas le pointeur
// Interdit: *ptr1 = 10;
// Autorisé: ptr1 = &y;

int *const ptr2 = &x; // Rend le pointeur constant, pas la valeur pointée
const int *const ptr3 = &x; // Rend à la fois le pointeur et la valeur pointée constants
```

### Static

1. Déclare la variable comme globale, mais réduite au scope local
2. Rend la variable locale à l'unité de traduction (fichier source)

```c
// Pas exportable, uniquement dans ce fichier source
static int i = 42; 

// Exportable, accessible depuis d'autres fichiers source
int j = 23;

int count() {
    static int counter = 0; // Accessible que dans cette fonction, 
                            // mais devient persistante entre les appels
    return ++counter;
}

static int help() {
    return 42;
}

int main() {
    printf("Compteur: %d\n", count()); // Affiche 1
    printf("Compteur: %d\n", count()); // Affiche 2
    printf("Compteur: %d\n", count()); // Affiche 3
}
```

### Register

Suggère au compilateur de stocker la variable dans un registre pour un accès plus rapide

```c
// C89
int main() {
    register int i; // Pour les variables fréquemment utilisées
                    // Stockées dans un registre CPU

    for (i = 0; i < 10; i++) {
    }
}
```

### Extern 

Permet de déclarer une variable ou une fonction qui est définie dans un autre fichier source.

Dans le standard, le mot clé est optionnel pour les fonctions, mais il est nécessaire pour les variables globales définies dans un autre fichier.

```c
// foo.c
int i = 42;
void help() { }

// main.c
extern int i; // Déclare que i est défini dans un autre fichier
extern void help(); // Déclare que help est défini dans un autre fichier
void help(); // Préférée moins verbeuse, puisque le extern est optionnel

int main() {
    printf("%d\n", i); 
    help();
}
```

### Volatile

Indique que la valeur d'une variable peut être modifiée de manière imprévisible, par exemple par du matériel ou un autre thread.

Indique donc au compilateur de ne pas optimiser l'accès à cette variable, car sa valeur peut changer à tout moment.

```c
int i = 0;
i = 1;
i = 0;
i = 1; 
i = 0;
```

### Auto

Le mot-clé `auto` est utilisé pour déclarer des variables locales à une fonction. Cependant, en C, les variables locales sont automatiquement de type `auto` par défaut, ce qui rend l'utilisation explicite de `auto` redondante et rarement utilisée.

```c
auto int i = 42; // Déclare une variable locale de type int
```

Comme plus personne ne l'utilise, en C26 le mot-clé `auto` a été retiré du langage, et remplacé par `auto` en C++ pour la déduction de type automatique.


### Restrict

Le mot-clé `restrict` est utilisé pour indiquer au compilateur qu'une variable est la seule manière d'accéder à une zone de mémoire. Cela permet au compilateur d'optimiser le code en supposant que les accès à cette zone de mémoire ne sont pas effectués via une autre variable.

```c
void swap(int *a, int *b) {
    int temp = *a; // Accès à la mémoire pointée par a
    *a = *b;       // Accès à la mémoire pointée par b
    *b = temp;     // Accès à la mémoire pointée par a
}

// Ne fonctionne que si a et b ne pointent pas vers la même adresse mémoire
void swap(int restrict *a, int restrict *b) {
    *a ^= *b; 
    *b ^= *a; 
    *a ^= *b; 
}

int a = 42;
swap(&a, &a); // Comportement indéfini, car a et b pointent vers la même adresse
```