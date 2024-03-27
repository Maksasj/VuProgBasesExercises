#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

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


int main() {


    return 0;
}