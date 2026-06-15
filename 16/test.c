#include <stdio.h>
#include <math.h>
#include <string.h>

char char2digit(char digit) {
    if (digit > '9' || digit < '0') return -1;
    return digit - '0';
}

int atoi(const char *s) {
    int n = strlen(s);
    int sum = 0;
    for (int i = 0; i < n; i++) 
        sum += char2digit(s[i]) * (int)pow(10, (n-i-1));
    return sum;
}

int main()  {
    printf("%d\n", atoi("prout"));
}