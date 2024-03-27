#include <stdio.h>
#include <math.h>

#define A input[0]
#define B input[1]
#define C input[2]

int main() {
    int input[3];

    for(int x = 0; x < 3; ++x) {
        scanf("%d", &input[x]);
    }

    if(A >= B) {
        printf("Incorect interval bound provided, A >= B");
        return 0;
    }

    if(C == 0) {
        printf("Cannot divide number by zero, C = 0");
        return 0;
    }

    for(int i = A + 1; i <= B; ++i) {
        if( i > 0 && i % C == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}