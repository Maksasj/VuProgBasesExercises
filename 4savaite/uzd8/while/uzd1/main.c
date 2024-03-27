#include <stdio.h>
#include <math.h>

#define A input[0]
#define B input[1]
#define C input[2]

float D(int a, int b, int c) {
    return (float)b*b - (float)4*a*c;
}

int main() {
    int input[3];

    int x = 0;
    while(x < 3) {
        scanf("%d", &input[x]);
        ++x;
    }

    if(A == 0) {
        printf("0");
        return 0;
    }

    float d = D(A, B, C);
    if(d < 0) {
        printf("0");
        return 0;
    } else if(d == 0) {
        printf("1\n");
        printf("%f", (-(float)B + sqrt(d))/(2.0*A));
        return 0;
    }

    printf("2\n");
    printf("%f\n", (-(float)B + sqrt(d))/(2.0*A));
    printf("%f", (-(float)B - sqrt(d))/(2.0*A));

    return 0;
}