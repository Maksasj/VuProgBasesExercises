#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 15;
    int b = 10;

    printf("Before swap %d, %d \n", a, b);

    swap(&a, &b);

    printf("After swap %d, %d \n", a, b);

    return 0;
}