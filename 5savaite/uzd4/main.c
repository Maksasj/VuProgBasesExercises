#include <stdio.h>
#include <stdlib.h>

int prime(int number) {
    int c = 0;

    for (int i = 1; i <= number; ++i)
        if (number % i == 0)
            c++;

    return (c == 2 ? 1 : 0);
}

int main() {
    int n = 0;
    int *array;
    for(n = 0; 1 ;) {
        int tmp;
        scanf("%d", &tmp);

        if(tmp < 0) {
            break;
        }
        
        if(prime(tmp)) {
            int flag = 0;
            for(int i = 0; i < n; ++i) {
                if(array[i] == tmp) {
                    flag = 1;
                    break;
                }
            }

            if(flag == 1) continue;

            int *tmp_array = malloc(sizeof(int) * (n + 1));
            for(int i = 0; i < n; ++i) {
                tmp_array[i] = array[i];
            }
            tmp_array[n] = tmp;

            array = tmp_array; 

            ++n;
        }   

    }

    for(int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }


    return 0;
}