#ifndef VU_FILE_H
#define VU_FILE_H

#include <stdlib.h>
#include <stdio.h>

extern unsigned int saveCount;
extern unsigned int loadCount;

void saveToFile(FILE *file, int array[], int n);

void loadFromFile(FILE *file, int **array, int *n);

#endif
