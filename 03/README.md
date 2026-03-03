# Semaine 03/16

- [x] Structures de données
  - [x] `struct`
  - [x] `typedef`
- [x] Lecture des arguments via une structure options
- [x] Passage d'un point à une fonction de calcul de distance
- [x] Structure plus compliquée contact
- [ ] Taille d'une structure

- [ ] Labo sur Proust

## Structures de données

Une structure de donnée est un conteneur destiné à stocker des informations
de différente nature. On peut le voir comme un carton contenant
des espaces pour y stocker des choses.

On utilise le mot clé `struct`:

```c
struct { double x; double y; } p = { 23, 42 };
struct { double x; double y; } q = { 3, -5 };

printf("%f %f\n", p.x, p.y);
```

On constate de la redondance, on peut simplifier en déclarant 
la structure sans y associer de variable:

```c
struct point { double x; double y; };
struct point r = {1,2};
struct point s = {2,3};
```

Plus tard dans le standard C est apparu le mot clé `typedef`
permettant de déclarer des types, et économiser des frappes au clavier:

```c
typedef unsigned long int size_t;
typedef long double prout;
prout p = 3.141592;

typedef int number;

number add (number a, number b) { return a + b; }
```

On peut profiter de ces deux mots clés, pour déclarer proprement
une structure:

```c
typedef struct point { double x; double y; } Point;

Point point;
```

## Taille d'une structure de donnée

```c
typedef struct point {
    int x; int y
} Point;

Point p; 
printf("%lf\n", sizeof(p)); // 8, soit 2x4
printf("%lf\n", sizeof(Point)); // 8, soit 2x4
printf("%lf\n", sizeof(struct point)); // 8, soit 2x4
```

### Alignement mémoire

Selon l'ordre des membres d'une structure la taille de la structure ne sera pas nécessairement la même en raison de l'alignement mémoire. Le compilateur cherchera toujours un alignement par défaut à 32-bit. Voir exepmle size.c


## Traitement des arguments

La convention POSIX et GNU pour les arguments de ligne de commande est la suivante:

- Les options *courtes* sont précédées d'un tiret (`-`)
- ou de deux tirets (`--`) pour les options *longues*.

```bash
$ my_program -a -b --option=value
```

Le traitement des arguments peut être effectué manuellement en parcourant `argv`:

```c
#include <stdio.h>

typedef struct options {
    bool a;
    bool b;
    char *option_value;
} Options;

Options parse_options(int argc, char *argv[]) {
    Options options = {false, false, NULL};
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            options.a = true;
        } else if (strcmp(argv[i], "-b") == 0) {
            options.b = true;
        } else if (strncmp(argv[i], "--option=", 9) == 0) {
            options.option_value = argv[i] + 9;
        }
    }
    return options;
}

int main(int argc, char *argv[]) {
    Options options = parse_options(argc, argv);
    printf("Option a: %s\n", options.a ? "true" : "false");
    printf("Option b: %s\n", options.b ? "true" : "false");
    if (options.option_value) {
        printf("Option value: %s\n", options.option_value);
    }
}
```

## Choix entrée standard ou fichier

Souvent, un programme peut soit lire à partir d'un fichier, soit à partir de l'entrée standard. Une convention courante est d'utiliser `-` pour indiquer que le programme doit lire à partir de l'entrée standard mais souvent en cas d'absence de fichier, le programme lit automatiquement à partir de l'entrée standard. Voici les deux approches:

```bash
$ my_program input.txt  # Lire à partir d'un fichier
$ cat input.txt | my_program - # Lire à partir de l'entrée standard
$ cat input.txt | my_program   # Lire à partir de l'entrée standard
```

Dans le code, cela peut être géré en vérifiant si un fichier a été spécifié ou non:

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *input = stdin; // Par défaut, lire à partir de l'entrée standard

    if (argc > 1 && strcmp(argv[1], "-") != 0) {
        input = fopen(argv[1], "r");
        if (input == NULL) {
            perror();
            return 1;
        }
    }

    // ... lecture en utilisant `input` ...
    getchar(input);

    if (input != stdin) fclose(input);
}
```
