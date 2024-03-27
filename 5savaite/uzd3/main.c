#include <stdio.h>
#include <stdlib.h>

int main() {
    int s, n;
    scanf("%d %d", &s, &n);
    if(n < 0) {
        printf("Array could not have size equal to 0 or less");
        return 1;
    }

    int *array = malloc(sizeof(int) * n);
    for(int i = 0; i < n;) {
        int tmp;
        scanf("%d", &tmp);
        if(tmp < 0) {
            printf("Value cannot be less then zero, please try again: \n");
        } else {
            array[i] = tmp;
            ++i;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(array[i] * array[j] == s) {
                printf("%d %d\n", array[i], array[j]);
            }
        }
    }
    
    return 0;
}