#include "file.h"

unsigned int saveCount = 0;
unsigned int loadCount = 0;

void saveToFile(FILE *file, int array[], int n) {
    fwrite(&n, sizeof(int), 1, file);
    fwrite(array, sizeof(int), n, file);

    ++saveCount;
}

void loadFromFile(FILE *file, int **array, int *n) {
    fread(n, sizeof(int), 1, file);
    *array = malloc(sizeof(int)*(*n));
    fread(*array, sizeof(int), (*n), file);

    ++loadCount;
}
