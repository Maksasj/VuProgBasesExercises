#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void create_file(const char* file_name) {
    FILE* file = fopen(file_name, "w");
    fclose(file);

    fflush(stdin); //Lets clear error buffer here, because it can cause a lot of pain in the future .P
}

int count_digit(int i) {
    int o = 0;
    while(i!=0) {  
       i = i/10;  
       o++;  
    }
    return o;  
}

void ask_to_enter_new_file_name(FILE* file) {
    printf("Please enter another file name: \n");

    char file_name[20];
    if(scanf("%s", file_name) == 0) {
        printf("Error expected file name\n");
        printf("Please enter file name: \n");
    }

    fclose(file);

    file = fopen(file_name, "r");
    if(file == NULL) {
        printf("Error such file does not exist\n");
        ask_to_enter_new_file_name(file);
    }
}

int main() {
    printf("This program calculates length of provided float number\n");
    create_file("in.txt");
    printf("Created 'in.txt' file\n");
    printf("Please enter real number in to 'in.txt' file, in range from 10 up to 1000, but not more than 3 digits from comma \n");
    printf("Press any button after filling 'in.txt' file\n");
    system("pause");
    
    char* file_name = "in.txt";
    FILE* file = fopen(file_name, "r");

    while(true) {
        if(file == NULL) {
            printf("Error while opening %s, maybe another process already opened this file, or file do not exist\n", file_name);
            printf("Note: if file exist check if maybe another process using it, overwise try to create 'in.txt' file inside this program directory\n");
            ask_to_enter_new_file_name(file);
            continue;
        }

        fseek (file, 0, SEEK_END);
        int size = ftell(file);
        if (0 == size) {
            printf("Error file is empty\n");
            ask_to_enter_new_file_name(file);
            continue;
        }
        fseek (file, 0, SEEK_SET);

        int first_part = -1;
        int second_part = -1;
        char comma;

        if(fscanf(file,"%d", &first_part) == 0) {
            printf("Error expected integer part of a number before comma \n");
            ask_to_enter_new_file_name(file);
            continue;
        }

        if(first_part == -1) {
            printf("Error could not properly read digits before comma \n");
            ask_to_enter_new_file_name(file);
            continue;
        }

        if(first_part < 10 || first_part > 1000) {
            printf("Error expected number in range from 10 up to 1000\n");
            ask_to_enter_new_file_name(file);
            continue;
        }

        if(fscanf(file,"%c", &comma) == 0) {
            printf("Error expected symbol separator before fractional part\n");
            scanf("%s", file_name);
            continue;
        }

        if(comma != ',') {
            printf("Error expected comma symbol as separator before fractional part \n");
            ask_to_enter_new_file_name(file);
            continue;
        }

        if(fscanf(file,"%d", &second_part) == 0) {
            printf("Error could not properly get fractional part of number \n");
            ask_to_enter_new_file_name(file);
            continue;
        }

        if(second_part == -1) {
            printf("Error could not properly read digits after comma \n");
            ask_to_enter_new_file_name(file);
            continue;
        }

        if(count_digit(second_part) > 3) {
            printf("Expected only 3 digit precision \n");
            ask_to_enter_new_file_name(file);
            continue;
        }

        printf("Number length %d", count_digit(first_part) + count_digit(second_part));
        break;    
    }
    
    return 0;
};