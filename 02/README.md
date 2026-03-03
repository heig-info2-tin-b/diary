# Semaine 02/16

- [x] Lecture écriture de caractères
- [x] Déterminer la taille d'un fichier
- [x] Différence ASCII et UTF-8
- [x] Détection de mots
- [x] Fichier texte ou binaire ?
- [ ] Sauvegarder mes exemples ?

## Types de fichiers

Un fichier texte est un fichier qui contient des caractères lisibles par l'homme, tandis qu'un fichier binaire contient des données qui ne sont pas destinées à être lues directement par l'homme. Les fichiers texte utilisent généralement un encodage de caractères comme ASCII ou UTF-8, tandis que les fichiers binaires peuvent contenir n'importe quel type de données, y compris des images, des vidéos, des programmes compilés, etc.

Généralement un fichier texte ne comporte jamais le caractère `\0` (null), parce qu'il n'est pas du texte et il n'apparait pas en UTF-8.

1. texte `fopen("fichier.txt", "r")`
2. binaire `fopen("fichier.bin", "rb")`

## Les fichiers

Un flux de données est un flux continu d'informations. En C un flux peut être l'entrée standard (stdin), la sortie standard (stdout) ou la sortie d'erreur standard (stderr). Les fichiers sont des flux de données qui peuvent être lus ou écrits. 

En C, les fichiers sont manipulés à l'aide de pointeurs de type `FILE`, qui sont définis dans la bibliothèque standard `<stdio.h>`. Pour ouvrir un fichier, on utilise la fonction `fopen()`, qui prend en argument le nom du fichier et le mode d'ouverture (lecture, écriture, etc.).

### Ouvrir un fichier

```c
FILE *f = fopen("nom_du_fichier.txt", "r"); // Ouvre le fichier en mode lecture
if (f == NULL) {
    perror("Erreur lors de l'ouverture du fichier");
    return 1;
}
```

Veillez bien à vérifier que le fichier a été ouvert correctement en vérifiant si le pointeur est `NULL`. Si c'est le cas, cela signifie que l'ouverture du fichier a échoué.

Le mode d'ouverture peut être :

- `"r"` : lecture
- `"w"` : écriture (le fichier est créé s'il n'existe pas, ou écrasé s'il existe)
- `"a"` : ajout (le fichier est créé s'il n'existe pas, ou les données sont ajoutées à la fin du fichier s'il existe)
- `"r+"` : lecture et écriture
- `"w+"` : lecture et écriture (le fichier est créé s'il n'existe pas, ou écrasé s'il existe)
- `"a+"` : lecture et ajout (le fichier est créé s'il n'existe pas, ou les données sont ajoutées à la fin du fichier s'il existe)
- `"b"` : mode binaire (peut être ajouté à n'importe quel mode pour indiquer que le fichier est traité comme un fichier binaire)

### Lire des caractères d'un fichier

Pour lire des caractères d'un fichier, on peut utiliser la fonction `fgetc()`, qui lit un caractère à la fois. 

```c
int c;
while ((c = fgetc(f)) != EOF) {
    putchar(c); // Affiche le caractère lu
}
```

### Taille d'un fichier

Pour obtenir la taille d'un fichier, on peut utiliser les fonctions `fseek()` et `ftell()`. 

```c
fseek(f, 0, SEEK_END); // Se positionner à la fin du fichier
long size = ftell(f); // Obtenir la position actuelle (taille du fichier)
fseek(f, 0, SEEK_SET); // Revenir au début du fichier
printf("Taille du fichier : %ld octets\n", size);
```

### Fermer un fichier

Il est important de fermer un fichier après l'avoir utilisé pour libérer les ressources associées. On utilise la fonction `fclose()` pour cela.

```c
fclose(f);
```

### Ecrire dans un fichier

Pour écrire dans un fichier, on peut utiliser la fonction `fprintf()`, qui fonctionne de manière similaire à `printf()`, mais écrit dans un fichier au lieu de la console.

```c
FILE *f = fopen("nom_du_fichier.txt", "w"); // Ouvre le fichier en mode écriture
if (f == NULL) {
    perror("Erreur lors de l'ouverture du fichier");
    return 1;
}
fprintf(f, "Hello, World!\n"); // Écrit une ligne dans le fichier
fclose(f);
```

## Exercice : compter le nombre de mots dans un fichier

1. Réfléchir à un algorithme pour compter le nombre de mots
2. Réfléchir aux cas particulier et comment les traiter
3. Implémenter le programme
4. Le tester
5. Comparer vos résultats au programme `wc`

## Algorithme

1. Ouvrir fichier
2. Créer deux variables `c` et `old_c`
3. compteur = 0
4. Vérifier si le fichier existe
5. Lire une lettre
6. Si elle vaut -1 je m'arrête, sinon:
   1. Si la valeur vaut ' ' ou un '\n et que l'ancienne valeur n'est pas un espace ou un '\n'
      - Incrémenter le compteur 
   2. Mettre c dans old_c
7. Goto 4
8. Fermer le fichier
9. Afficher la valeur de compteur

## Caractère de séparation de mot

- ' '
- '\n'
- '\t'
- '.'
- ','
- ':'
- ';'
- '\''
- '"'
- '?'
- '!'





