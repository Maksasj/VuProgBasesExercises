#include <stdlib.h>

unsigned char hexToChar(int digit, char type) {
    if(digit < 0 || digit > 15)
        return 48;

    if(digit < 10)
        return digit + 48;

    if(type > 0)
        return 55 + digit;
    
    return 87 + digit;
}

//Assume that 'dezutes talpa 3 baitai'
void *ptr1;
void *ptr2;

void imagine(void) {
    int* array = malloc(6 * 3);
    int* var = malloc(6);

    var = &array;

    array[0] = 4831;
    array[1] = -568;
    array[2] = &var;

    ptr1 = &var;
    ptr1 = &array[2];
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
    (*ptr) = NULL;
}