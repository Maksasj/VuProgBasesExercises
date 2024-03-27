#include <stdio.h>
#include <stdlib.h>

int splitData(int input_array[], unsigned int array_size, unsigned int first_part_size, int** out_a, int** out_b) {
    if(first_part_size > array_size) return -1;
    if(array_size == 0 || first_part_size == 0) return -1;
    
   *out_a = malloc(first_part_size * sizeof(int));
   *out_b = malloc((array_size - first_part_size) * sizeof(int));

    int a_index = 0, b_index = 0;

    for(int i = 0; i < array_size; ++i) {
        if(i < first_part_size) {
            (*out_a)[a_index] = input_array[i];
            a_index++;
        } else {
            (*out_b)[b_index] = input_array[i];
            b_index++;
        }
    }

    return 0;
}

int main() {
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    
    int* array_a;
    int* array_b;

    int res = splitData(array, 12, 5, &array_a, &array_b);

    printf("Input array: ");

    for(int i = 0; i < 12; ++i) {
        printf("%d ", array[i]);
    }

    printf("\nFirst array: ");
    for(int i = 0; i < 5; ++i) {
        printf("%d ", array_a[i]);
    }

    printf("\nSecond array: ");
    for(int i = 0; i < 12 - 5; ++i) {
        printf("%d ", array_b[i]);
    }
}