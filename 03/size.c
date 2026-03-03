#include <stdio.h>

int main() {
    struct foo {
        char x;
        short y;
        char u;
        int z;
    } f;

    struct bar {
        char x;
        char u;
        short y;
        int z;
    } b;

    # pragma pack(1)
    struct baz {
        char x;
        short y;
        char u;
        int z;
    } z;
    # pragma pack()



    printf("Size of struct foo: %zu\n", sizeof(f));
    printf("Size of struct bar: %zu\n", sizeof(b));
    printf("Size of struct baz: %zu\n", sizeof(z));
}