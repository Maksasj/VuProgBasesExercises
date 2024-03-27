#include <stdio.h>

int count_digit(int i) {
    int o = 0;
    for(;i!=0;) {  
       i = i/10;  
       o++;  
    }
    return o;  
}

int main() {
    int d, s;

    for(int i = 0; 1 ; ++i) {
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
    }

    printf("%d", s);

    return 0;
}