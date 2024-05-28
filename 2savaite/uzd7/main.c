#include <stdio.h>
#include <math.h>

int countDigit(int i) {
    int o = 0;
    while(i!=0) {  
       i = i/10;  
       o++;  
    }
    return o;  
}

long long ipow(long long b, int x) {
    if(x == 0) {
        return 1;
    }

    int k = b;

    for(int i = 0; i < x - 1; i++) {
        b *= k;
    }

    return b;
}

int getDigitByIndex(int i, int index) {
    
    int l = countDigit(i);
    
    index = (l - 1) - index;

    int I = i;
    int p = 0;
    while(i != 0) {  
       i = i / 10;  
       p++;
       if(p - 1 == index) {
            return (I - i * ipow(10, p) )/ (ipow(10, p - 1));
       }
    }
}

int lowestDigitIndex(int n) {
    int s = 10;
    int l = countDigit(n);
    int p = 0;
    int i = 0;
    while (n) {
        int r = n % 10;

        if(r < s) {
            i = p;
        }
        p++;
        s = (r < s ? r : s);
        
        
        n = n / 10;
    }

    return l - i - 1;
}

int deleteDigitByIndex(int i, int index) {
    int s = i;
    int l = countDigit(i);
    int p = i / (ipow(10, l - index));
    p *= (ipow(10, l - index - 1));
    p += s % ipow(10, l - index - 1);
    return p;
}

int sortDigits(int input) {
    int anw = 0;
    int l = countDigit(input);

    int in = input;
    for(int i = 0; i < l; i++) {
        int p = lowestDigitIndex(in);
        int v = getDigitByIndex(in, p);
        in = deleteDigitByIndex(in, p);
        anw += v;

        if(l - 1 != i) {
            anw *= 10;
        }
    }

    return anw;
}

int main(void) {
    int input = 46189458;
    int sorted = sortDigits(input);

    //46189458 -> 14456889
    printf("%d -> %d", input, sorted);
    return 0;
}