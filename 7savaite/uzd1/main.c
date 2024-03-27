#include <stdio.h>
#include <stdlib.h>

int isInRange(int number, int low, int high) {
    if(number < low) return 0;
    if(number > high) return 0;
    return 1;
}

int main() {
    int k = 45;

    if(isInRange(k, 13, 59)) {
        printf("Number %d is in range", k);
    } else {
        printf("Number %d isn't in range", k);
    }

    return 0;
}
