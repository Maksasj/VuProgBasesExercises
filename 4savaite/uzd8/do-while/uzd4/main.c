#include <stdio.h>

#define A input[0]
#define B input[1]
#define C input[2]

int dbd(int a, int b) {
    do {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    } while (a != 0 && b != 0);

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
    do {
        scanf("%d", &input[x]);
        ++x;
    } while(x < 3);

    printf("DBD: %d\n", dbd(dbd(A, B), C));
    printf("MBK: %d\n", mbk(A, B, C));

    return 0;
}