#include <stdio.h>

int main() {
    //a
    int array[10] = { 0 };

    //b
    for(int i = 0; i < 10; ++i) {
        printf("%d ", array[i]);
    }

    //c
    array[0] = 1;
    array[3] = 2;
    array[9] = 3;
    
    //d
    int a = 0;
    for(int i = 0; i < 10; ++i) {
        if(i + a < 10)
            array[i] = array[i + a];
        else
            array[i] = 0;
        if(i == 2) ++a;
    }

    //e
    array[6] = 4;

    //f
    printf("\n");
    for(int i = 0; i < 10; ++i) {
        printf("%d ", array[i]);
    }

    //g
    int x, y;
    printf("\nEnter two numbers, X and Y: ");
    scanf("%d %d", &x, &y);
    if(x < 0 || x > 9) {
        printf("\nX out of bounds [0; 9]");
        return 1;
    }
    array[x] = y;

    //h
    printf("\nEnter index of the element that you want to erase from an array\n");
    scanf("%d", &x);
    if(x < 0 || x > 9) {
        printf("\nX out of bounds [0; 9]");
        return 1;
    }
    a = 0;
    for(int i = 0; i < 10; ++i) {
        if(i == x - 1) ++a;
        if(i + a < 10)
            array[i] = array[i + a];
        else
            array[i] = 0;
    }

    //i
    printf("\nEnter two numbers, X and Y: ");
    scanf("%d %d", &x, &y);
    if(x < 0 || x > 9) {
        printf("\nX out of bounds [0; 9]");
        return 1;
    }
    a = -1;
    for(int i = 9; i >= 0; --i) {
        array[i] = array[i + a];
        if(x == i) {
            a++;
        }
    }
    array[x] = y;

    //j
    printf("\n");
    for(int i = 0; i < 10; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}