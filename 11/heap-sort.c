#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintient la propriété de tas max pour le sous-arbre de racine i
// n est la taille du tas
void heapify(int arr[], int n, int i) {
    int plus_grand = i;
    int gauche = 2 * i + 1;
    int droite = 2 * i + 2;
    
    // Si l'enfant gauche est plus grand que la racine
    if (gauche < n && arr[gauche] > arr[plus_grand])
    plus_grand = gauche;
    
    // Si l'enfant droit est plus grand que le plus grand actuel
    if (droite < n && arr[droite] > arr[plus_grand])
    plus_grand = droite;
    
    // Si le plus grand n'est pas la racine, échanger et continuer
    if (plus_grand != i) {
        swap(&arr[i], &arr[plus_grand]);
        heapify(arr, n, plus_grand);
    }
}

void heapSort(int arr[], int n) {
    // Step 1 : max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Step 2 : Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Tableau initial : ");
    display(arr, n);

    heapSort(arr, n);

    printf("Tableau trié    : ");
    display(arr, n);
}