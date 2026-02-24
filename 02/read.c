#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    FILE *fp = fopen("mal.txt", "r");
    if (fp == NULL) return 1;
    const char *letters = "aeiouy"; // char letters[6] = {'a', 'e', 'i'...}
    const size_t size = strlen(letters);
    size_t counts[size];
    memset(counts, 0, size*sizeof(counts[0]));
    char c;

    while((c = fgetc(fp)) && c != EOF) {
        for (int i = 0; i < size; i++) {
            counts[i] += tolower(c) == letters[i];
        }
    }
    for (int i = 0; i < size; i++)
        printf("Nombre de %c: %ld\n", letters[i], counts[i]);
    fclose(fp);
}