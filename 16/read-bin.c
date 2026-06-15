#include <stdio.h>

typedef struct person {
    int age;
    char name[5];
    int length;
} Person;

int main() {
    FILE *fp = fopen("file.bin", "rb");
    if (!fp) return 1;

    Person data_char[5];
    fread(data_char, sizeof(Person), 5, fp);

    for (int i = 0; i < 5; i++) 
        printf("%d ", data_char[i].age);
}