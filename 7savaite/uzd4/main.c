#include <stdio.h>
#include <stdlib.h>

void generateArray(int data[], int size, int low, int high) {
    for(int i = 0; i < size; ++i) {
        data[i] = (rand() % (low - high - 1)) + low;
    }
}

#define ARRAY_SIZE 99

int main() {
    int array[ARRAY_SIZE];
    generateArray(array, ARRAY_SIZE, 14, 39); // [14; 39]

    //for(int i = 0; i < ARRAY_SIZE; ++i) {
    //    printf("%d ", array[i]);
    //}

    return 0;
}