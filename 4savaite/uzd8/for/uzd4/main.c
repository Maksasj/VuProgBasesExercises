#include <stdio.h>

#define A input[0]
#define B input[1]
#define C input[2]

int dbd(int a, int b) {
    for(;a != 0 && b != 0;) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }

    return a + b;
}

int mbk(int a, int b, int c) {
    int result = (a * b / dbd(a, b));
    result *= c / dbd(result, c);
    return result;
}

int main() {
    int input[3];

    for(int x = 0; x < 3; ++x) {
        scanf("%d", &input[x]);
    }

    printf("DBD: %d\n", dbd(dbd(A, B), C));
    printf("MBK: %d\n", mbk(A, B, C));

    return 0;
}