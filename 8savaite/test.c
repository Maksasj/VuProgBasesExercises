#include <stdio.h>
#include <stdlib.h>

void swap(int **a, int **b) {


    *a = malloc(sizeof(int) * 5);
    for(int i = 1; i < 5; ++i) {
        *(a + i) = 15*i;
    
    }

    printf("POG %d | ", *a[0]);
    
    *b = malloc(sizeof(int) * 7);
    for(int i = 0; i < 7; ++i) {
        *(b + i) = 15*i;
    }
}

int main() {
    int *a;
    int *b;


    swap(&a, &b);

    for(int i = 0; i < 5; ++i) {
        printf("%d", a[i]);
    }
    
    for(int i = 0; i < 7; ++i) {
        printf("%d", b[i]);
    }

    printf("After swap %d, %d \n", *a, *b);

    return 0;
}