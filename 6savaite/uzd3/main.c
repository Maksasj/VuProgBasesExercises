#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A input[0]
#define B input[1]
#define C input[2]

int str_ends_with(char *str, char *suffix) {
    size_t slen = strlen(str);
    size_t suffix_len = strlen(suffix);

    return suffix_len <= slen && !strcmp(str + slen - suffix_len, suffix);
}

int main() {
    printf("This program calculates average between 3 numbers\n");
    int input[3];

    while(1) {
        fflush(stdin);
        printf("Please enter 3 numbers separated by ';' symbol\n");
        
        char tmp_s_1;
        char tmp_s_2;
        
        int n = scanf("%d%c%d%c%d", &A, &tmp_s_1, &B, &tmp_s_2, &C);

        printf("MARKER\n");

        if( n == 5 &&
            tmp_s_1 == ';' &&
            tmp_s_2 == ';') {
            printf("Successfully parsed input\n");
            break;
        }

        printf("Wrong format type provided \n");
    }

    float avg = ((float)A + (float)B + (float)C) / 3.0;

    while (1) {
        printf("Please enter file name: \n");
        fflush(stdin);
        char* file_name;

        if(scanf("%s", file_name) == 0) {
            printf("Expected file name \n");
            continue;
        }
        
        if(!str_ends_with(file_name, ".txt")) {
            printf("Expected file name to end with '.txt' \n");
            continue;
        }

        FILE* file = fopen(file_name,"w");

        if(file == NULL) {
            printf("Could not open file \n");
        }

        fprintf(file, "%f", avg);
        printf("Successfully saved result in to %s", file_name);
        fclose(file);
        break;
    }
    
    
    return 0;
}