# Semaine 10/16

- [ ] Liste doublement chaînée

## Exercice

1. On suppose une liste doublement chaînée. Un élément souhaite
se retirer de la liste. Lister les étapes nécessaires.
2. Un autre élément souhaite ajouter un nouvel élément après lui. Quelles sont les étapes nécessaires ? 


```text                                            
   ┌──────┐                                    
   │      +──────────last──────────────────┐     
   │      +─first──┐                       │     
   └──────┘        │        NODE           │     
                ┌──▼─┐      ┌────┐      ┌──▼──┐  
                │    +─────►│    +─────►│     │  
                │    │◄─────+    │◄─────+     │  
                └────┘      └────┘      └─────┘  
```                                               
                                               
```c
/**
 * @param n: A chosen node
 * @return Address of the new element
 */
Node * append_new_after(Node *n) {
    Node *new = calloc(sizeof(Node), 1);
    if (new == NULL) return NULL;

    new->prev = n;
    new->next = n->next;

    n->next = new; 
    new->next.prev = new;

    return new;
}
```                                               