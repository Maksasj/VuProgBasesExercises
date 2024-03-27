#include <stdio.h>

int count_digit(int i) {
    int o = 0;
    do {  
       i = i/10;  
       o++;  
    } while(i!=0);
    return o;  
}

int main() {
    int d, s;

    int i = 0;
    do {
        int tmp;
        scanf("%d", &tmp);

        if(tmp < 0) break;

        int tmp_d = count_digit(tmp); 
        if(i == 0) {
            d = tmp_d;
            s = tmp;
        } else {
            if(tmp_d > d) {
                d = tmp_d;
                s = tmp;
            }
        }
        ++i;
    } while(1);

    printf("%d", s);

    return 0;
}