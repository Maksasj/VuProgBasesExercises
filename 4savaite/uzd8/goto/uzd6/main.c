#include <stdio.h>

int count_digit(int i) {
    int o = 0;

    loop:  
       i = i/10;  
       o++;  
    if(i!=0) goto loop;

    return o;  
}

int main() {
    int d, s;

    int i = 0;
    loop:
        int tmp;
        scanf("%d", &tmp);

        if(tmp < 0) goto br;

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
    goto loop;
    br:

    printf("%d", s);

    return 0;
}