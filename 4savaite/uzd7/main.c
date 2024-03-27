#include <stdio.h>

int main() {
    signed char a = 0;
    signed short b = 0;
    signed int c = 0;
    signed long d = 0;

    unsigned char a1 = 0;
    unsigned short b1 = 0;
    unsigned int c1 = 0;
    unsigned long d1 = 0;

    { //signed char
        signed char a_p;
        while(1) {
            a_p = a;
            a += 1;
            if(a_p > a) {
                break;
            }
        }
        printf("signed char: (%d) -> (%d)\n", a, a_p);
    }
    
    { //signed short
        signed short b_p;
        while(1) {
            b_p = b;
            b += 1;
            if(b_p > b) {
                break;
            }
        }
        printf("signed short: (%d) -> (%d)\n", b, b_p);
    }
    
    { //signed int
        signed int c_p;
        while(1) {
            c_p = c;
            c += 1;
            if(c_p > c) {
                break;
            }
        }
        printf("signed int: (%d) -> (%d)\n", c, c_p);
    }

    { //signed long
        signed long d_p;
        while(1) {
            d_p = d;
            d += 1;
            if(d_p > d) {
                break;
            }
        }
        printf("signed long: (%d) -> (%d)\n", d, d_p);
    }

    { //unsigned char
        unsigned char a1_p;
        while(1) {
            a1_p = a1;
            a1 += 1;
            if(a1_p > a1) {
                break;
            }
        }
        printf("unsigned char: (%d) -> (%d)\n", a1, a1_p);
    }
    
    { //unsigned short
        unsigned short b1_p;
        while(1) {
            b1_p = b1;
            b1 += 1;
            if(b1_p > b1) {
                break;
            }
        }
        printf("unsigned short: (%d) -> (%d)\n", b1, b1_p);
    }
    
    { //unsigned int
        unsigned int c1_p;
        while(1) {
            c1_p = c1;
            c1 += 1;
            if(c1_p > c1) {
                break;
            }
        }
        printf("unsigned int: (%u) -> (%u)\n", c1, c1_p);
    }

    { //unsigned long
        unsigned long d1_p;
        while(1) {
            d1_p = d1;
            d1 += 1;
            if(d1_p > d1) {
                break;
            }
        }
        printf("unsigned long: (%u) -> (%u)\n", d1, d1_p);
    }

    return 0;
}