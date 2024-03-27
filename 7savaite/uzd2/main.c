#include <stdio.h>
#include <stdlib.h>

//Function return 0 then something went wrong
int getFactorial(int number) {
    if(number > 12) return 0; //Factorial more then 12 will not fit in integer limit
    if(number < 0) return 0; //Factorial of non positive integer
    
    if(number == 0) return 1;

    int k = 1;
    for(int i = 1; i <= number; ++i) {
        k *= i;
    }

    return k;
}

int main() {
    int k = 5;

    printf("Factorial of %d id %d", k, getFactorial(k));

    return 0;
}