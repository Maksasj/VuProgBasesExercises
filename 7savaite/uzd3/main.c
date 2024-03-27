#include <stdio.h>
#include <stdlib.h>

int getPositiveNumber(char *msg) {
    printf(msg);
    int a;

    while (1) {
        char tmp;
        fflush(stdin);
        int res = scanf("%d%c", &a, &tmp);

        if(res == 2 && tmp == '\n') {
            return a;
        }

        printf("Something went wrong \n");
        printf(msg);
    }
}

int main() {
    int input = getPositiveNumber("Please enter a number:\n");
    printf("Entered number: %d", input);

    return 0;
}