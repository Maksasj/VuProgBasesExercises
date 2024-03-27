#include <stdio.h>

int main() {
    int n, p = 0;
    int min;
    
    scanf("%d", &n);

    if(n <= 0) {
        printf("Array length cannot be less or equal zero\n");
        return 1;
    }

    for(int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if(i == 0) {
            min = tmp;
        }
    
        if(tmp < min) {
            min = tmp;
        }

        p += tmp;
    }

    printf("avg: %f\n", p/(float)n);
    printf("min: %d", min);

    return 0;
}