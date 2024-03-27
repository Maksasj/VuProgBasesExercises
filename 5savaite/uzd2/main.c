#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int array[1000];

    int a, b, c;
    printf("Enter 3 numbers(a, b, c): ");
    scanf("%d %d %d", &a, &b, &c);
    if(b < a) {
        printf("\nIncorrectly entered value boundary\n");
        return 1;
    }
    if(c >= 1000) {
        printf("\nC cannot be more than 1000\n");
        return 1;
    }

    for(int i = 0; i < c; ++i) {
        array[i] = rand() % (b + 1 - a) + a;
    }

    for(int i = 0; i < c; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}