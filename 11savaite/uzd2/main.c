#include <stdio.h>
#include <time.h>
#include "file.h"

int main() {
    srand(time(NULL));

    int m1[10];
    int m2[10];
    int m3[10];

    for(int i = 0; i < 10; ++i) {
        m1[i] = rand() % 100;
        m2[i] = rand() % 100;
        m3[i] = rand() % 100;
    }

    FILE* file1 = fopen("file1.bin", "wb");

    saveToFile(file1, m1, 10);
    saveToFile(file1, m3, 10);

    int m1_size;
    int *m1_load;

    loadFromFile(file1, &m1_load, &m1_size);

    FILE* file2 = fopen("file2.bin", "wb");

    saveToFile(file2, m2, 10);

    int m3_size;
    int *m3_load;

    loadFromFile(file2, &m3_load, &m3_size);

    int m2_size;
    int *m2_load;

    loadFromFile(file1, &m2_load, &m2_size);

    fclose(file1);
    fclose(file2);

    if(saveCount == 3 && loadCount == 3) {
        printf("all good");
    } else {
        printf("something’s wrong");
    }

    return 0;
}