

typedef struct linked_list {
    int data;
    struct linked_list *next;
} LinkedList;

typedef struct double_linked_list {
    int data;
    struct double_linked_list *next;
    struct double_linked_list *prev;
} DoubleLinkedList;

