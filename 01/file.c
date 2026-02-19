#include <stdio.h>

int main() {
    FILE* fp = fopen("prout.txt", "w+");
    if (fp == NULL) {
        fprintf(stderr, "Erreur: Impossible d'ouvrir le fichier\n");
    }

    fprintf(fp, "prout");

    if (fclose(fp) != 0) {
        fprintf(stderr, "Erreur: Impossible de fermer le fichier\n");
    } 
}