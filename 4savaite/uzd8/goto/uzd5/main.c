#include <stdio.h>

int main() {
    int n, p = 0;
    int min;
    
    scanf("%d", &n);

    if(n <= 0) {
        printf("Array length cannot be less or equal zero\n");
        return 1;
    }

    int i = 0;
    int tmp;
    loop:
        scanf("%d", &tmp);
        if(i == 0) {
            min = tmp;
        }
    
        if(tmp < min) {
            min = tmp;
        }

        p += tmp;

        ++i;
    if (i < n) goto loop;

    printf("avg: %f\n", p/(float)n);
    printf("min: %d", min);

    return 0;
}