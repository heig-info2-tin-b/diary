# Semaine 01/16

## Résumé de Info1

- Types
  - Vide (`void`) 
  - Boolean (`#include <stdbool.h>`) 
  - Entiers
    - `char`, `short int`, `int`, `long int`, `long long int`
    - `uint16_t`, `uint_least16_t`, `uint_fast16_t`
    - `int16_t`, `int_least16_t`, `int_fast16_t`
    - `size_t` (unsigned long int)
  - Flottants
    - `float` (32-bits), 5-6 chiffres significatifs
    - `double` (64-bits) 12-13 chiffres significatifs
- Structure de contrôle
  - Boucles
    - for
    - while
    - do while
  - if, else, else if 
  - switch
  - goto
- Opérateurs
  - Opérateur ternaire (`?:`)
  - Modulo `%`
  - Arithmétiques `+`, `-`, `*`, `/`
  - Logiques `&&`, `||`
  - Binaires `&`, `|`, `^`, `~`
  - Décalages `>>`, `<<`
  - Comparaison `==`, `!=`, `>`, `>=`, `<`, `<=`
  - Affectations `=`, `^=`, `%=`...
  - Pré `++()`, `--()`
  - Post `()++`, `()--`
- Tableau
  - `int t[12]` Déclarer un tableau de 12 entiers, non initialisé
  - `int t[12] = {0}` J'initialise le premier à 0 et le reste à 0
  - `int t[12] = {1, 2}` J'initialise le premier à 1, le second à 2 et le reste à 0
  - `t[4]` récupère la valeur à la cinquième position du tableau
  - `int t[3][4]`
- Pointeur
  - `&` L'adresse de
  - `int *p` Déclare un pointeur p sur un entier
  - `*p` Déférence l'adresse pour récupérer la valeur
  - `a[b]` `*(a + b)`
- Fonctions
  - `int func(int p1, int p2, int *p3) { return 42; }`
- Préprocesseur
  - `#include <stdio.h>`
  - `#define FOO 42`
  - `#define ADD(a,b) (a+b)`
  - `#ifdef FOO`, `#ifndef` 

## Fichiers

- `fopen("nom du fichier", "rw")` Ouvrir et créer un fichier
- `fclose(fp)` Ferme un fichier
- `fprintf(fp, "Format", ...)` Écrit du texte dans le fichier
- `ftell(fp)` Retourne la position du curseur
- `fseek(fp, 3, SEEK_SET)` Déplace le curseur par rapport à une référence
  - `SEEK_SET` Le début du fichier
  - `SEEK_CUR` La position actuelle du curseur
  - `SEEK_END` La position de la fin du fichier 
