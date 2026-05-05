# Semaine 11/16

- [ ] Algorithmes de tri
  
## Algorithmes de tri

Trois catégories: 

1. Nuls: O(n^2) [Bubble Sort]
2. Optimums: O(n log n) [HeapSort, QuickSort, MergeSort...]
3. Sans comparaisons: (O(n+k)) [CountingSort]

## Arbre binaire

C'est une sorte de liste chaînée mais avec deux enfants. 
Enfant de gauche et de droite

## Représenter un arbre sous forme d'un tableau

Enfant de gauche: 2*k + 1 
Enfant de droite: 2*k + 2

## Max-Heap

Tas binaire maximum c'est un arbre binaire qui respecte la propriété que
chaque enfant est plus petit ou égal au parent direct. 

## Heap Sort

On défini une fonction `heapify` qui à partir d'un max-heap extrait
la valeur la plus grande en début de liste.

1. On commence par créer max-heap en répetant l'appel à `heapify`
2. On répète récursivement `heapify` après avoir échangé le premier et  
   le dernier élément, puis réduit le tableau de 1 élément 


## Stabilité d'un algorithme de tri

C'est la possibilité de répéter plusieurs fois un tri sans casser ce
qui a déjà été trié.
