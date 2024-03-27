#include <stdio.h>
#include <math.h>

#define X input[0]
#define Y input[1]
#define Z input[2]

int main(void) {
    

    double input[3];
    printf("Enter x, y and z values: \n");


    for(int i = 0; i < 3; i++)
        scanf("%lf", &input[i]);
    

    double A = X + 4*Y + pow(Z, 3);
    printf("A) %.2f + 4*%.2f + (%.2f)^3 = %.2f \n", X, Y, Z, A);

    double B = (X + sqrt(Y))*(pow(Z, 4) - fabs(Z) + 46.3);
    printf("B) (%.2f + sqrt(%.2f))*(%.2f^4 - |%.2f| + 46.3) = %.2f", X, Y, Z, Z, B);

    return 0;
} 

const char* name[11] = { 'A', 'L','E','K','S','A','N','D','R','A','S' };

