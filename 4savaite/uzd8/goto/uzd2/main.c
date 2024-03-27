#include <stdio.h>
#include <math.h>

#define A input[0]
#define B input[1]
#define C input[2]

int main() {
    int input[3];

    int x = 0;
    in: 
        scanf("%d", &input[x]);
        ++x;
    if(x < 3) goto in;

    if(A >= B) {
        printf("Incorect interval bound provided, A >= B");
        return 0;
    }

    if(C == 0) {
        printf("Cannot divide number by zero, C = 0");
        return 0;
    }

    int i = A + 1;
    loop:
        if( i > 0 && i % C == 1) {
            printf("%d\n", i);
        }
        ++i;
    if(i <= B) goto loop;

    return 0;
}