#include <stdio.h>
#include "file.h"

int main() {
    int m1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for(int i = 0; i < 10; ++i) {
        printf("%d ", m1[i]);
    }

    printf("\n");

    FILE* file;
    file = fopen("test.bin","wb");
    saveToFile(file, m1, 10);
    fclose(file);

    int n;
    int *m2;

    file = fopen("test.bin","rb");
    loadFromFile(file, &m2, &n);
    printf("%d \n", n);

    for(int i = 0; i < n; ++i) {
       printf("%d ", m2[i]);
    }

    fclose(file);

    for(int i = 0; i < 10; ++i) {
        if(m1[i] != m2[i]) {
            printf("\nsomething’s wrong");
            return 0;
        }
    }

    printf("\nall good");

    return 0;
}