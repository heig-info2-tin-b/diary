#include <stdio.h>

int main(int argc, char * argv[]) {
    if (argc < 2) { fprintf(stderr, "Manque le nom du fichier\n"); return 1; }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) { fprintf(stderr, "Erreur\n"); return 1; }
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    printf("Le fichier fait %ld byte%c", size, size > 1 ? 's' : '\0');
    fclose(fp);
} 