#include <stdio.h>

#define A input[0]
#define B input[1]
#define C input[2]

int dbd(int a, int b) {

    loop:
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    if(a != 0 && b != 0) goto loop;

    return a + b;
}

int mbk(int a, int b, int c) {
    int result = (a * b / dbd(a, b));
    result *= c / dbd(result, c);
    return result;
}

int main() {
    int input[3];

    int x = 0;
    in: 
        scanf("%d", &input[x]);
        ++x;
    if(x < 3) goto in;

    printf("DBD: %d\n", dbd(dbd(A, B), C));
    printf("MBK: %d\n", mbk(A, B, C));

    return 0;
}