#include <stdio.h>
#include <stdlib.h>

int opened_lockers(int n) {
    int i;
    for (i = 1; i * i <= n; i++);
    return i - 1;
}

int main(int argc, char *argv[]) {
    printf("%d\n", opened_lockers(atoi(argv[1])));
}
