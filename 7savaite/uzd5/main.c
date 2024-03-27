#include <stdio.h>
#include <stdlib.h>

long getFileSize(char *fileName) {
    FILE* file = fopen(fileName, "r");
    
    if(file == NULL)
        return -1;

    if(fseek(file, 0L, SEEK_END) != 0)
        return -1;
        
    return ftell(file);
}

int main() {
    long file_size = getFileSize("test_file.txt");
    printf("file size: %ld", file_size);

    return 0;
}