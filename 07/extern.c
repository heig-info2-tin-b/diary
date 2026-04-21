#include <stdio.h>

extern int i; // Déclare que i est défini dans un autre fichier
extern void help(); // Déclare que help est défini dans un autre fichier

int main() {
    printf("%d\n", i); 
    help();
}