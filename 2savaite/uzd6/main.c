#include <stdio.h>

#define A input[0]
#define B input[1]
#define C input[2]

int findMax(int input[3]) {
    int tmp = A;
    tmp = (tmp < B ? B : tmp);
    tmp = (tmp < C ? C : tmp);
    return tmp;
}

int main(void) {
    int input[3];

    for(int i = 0; i < 3; i++)
        scanf("%d", &input[i]);
    
    printf("%d", findMax(input));

    return 0;
} 