#include "file.h"

void saveToFile(FILE *file, int array[], int n) {
    fwrite(&n, sizeof(int), 1, file);
    fwrite(array, sizeof(int), n, file);
}

void loadFromFile(FILE *file, int **array, int *n) {
    fread(n, sizeof(int), 1, file);
    *array = malloc(sizeof(int)*(*n));
    fread(*array, sizeof(int), (*n), file);
}
