#include <stdlib.h>

unsigned char hexToChar(int digit, char type) {
    if(digit < 10) 
        return digit;
    
    if(type > 0)
        return 55 + digit;

    return 87 + digit;
}

void *ptr1;
void *ptr2;

void imagine(void) {
    int* array = malloc(6 * 3);
    int* var = malloc(6);

    var = array;

    (*array) = 4831;
    *(array + 6) = -568;
    *(array + 12) = var;

    ptr1 = &var;
    ptr1 = (array + 12);
}

int* getPermutation(int size) {
    if(size <= 0) return NULL;
    int* array = malloc(size * sizeof(int));
    for(int i = 0; i < size; ++i)
        array[i] = -1;
    
    for(int i = 1; i <= size; ++i) {
        while (1) {
            int randIndex = rand() % size;
            if(array[randIndex] != -1) continue;
            array[randIndex] = i;
            break;
        }
    }

    return array;
}

int fun1(int i, int j) {
    if(i == j)
        return 0;
    if(j > i)
        return j;
    
    return i;
}

void fun2(int *a, int *b) {
    int tmp = *b;
    (*b) = *a;
    (*a) = tmp;
}

void fun3(int **ptr) {
    (*ptr) = malloc(sizeof(int));
    (*ptr) = (int*)1;
}