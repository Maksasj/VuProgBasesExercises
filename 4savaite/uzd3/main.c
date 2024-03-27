#include <stdio.h>
#include <math.h>

#define A input[0]
#define B input[1]
#define C input[2]

int get_fc(int f0, int f1, int fc) {
    int n = 2;
    int c = f0 + f1;

    while (1) {
        if(n == fc) {
            break;
        }

        c = f0 + f1;
        f0 = f1;
        f1 = c;
        ++n;
    }

    return c;
}

int main() {
    int input[3];

    for(int x = 0; x < 3; ++x) {
        scanf("%d", &input[x]);
        if(input[x] < 0) {
            printf("Expecting a positive integer");
            return 0;
        }
    }

    if(C < 2) {
        printf("C should be bigger then 2");
        return 0;
    }

    printf("%d", get_fc(A, B, C));
    
    return 0;
}