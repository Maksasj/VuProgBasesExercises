#include <stdio.h>
#include <stdlib.h>

//a
int* createArray(unsigned int size, int lower_bound, int upper_bound) {
    if (upper_bound < lower_bound) return NULL;
    if (size == 0) return NULL;

    int *array = malloc(sizeof(int) * size);
    for(int i = 0; i < size; ++i) {
        array[i] = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
    }
    
    return array;
}

//b
int* generateArray(unsigned int size, int lower_bound, int upper_bound) {
    if (upper_bound < lower_bound) return NULL;
    if (size == 0) return NULL;

    int *array = malloc(sizeof(int) * size);

    for(int i = 0; i < size; ++i) {
        *(array + i) = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
    }
    
    return array;
}

int main() {
    int *array = createArray(8, 2, 15);
    //int *array = generateArray(8, 2, 15);
    
    for(int i = 0; i < 8; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}