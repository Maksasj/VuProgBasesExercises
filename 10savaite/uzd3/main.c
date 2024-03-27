#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

char *strncat(char* dest, const char *src, size_t n) {
    char *out = dest;
    
    while (*dest != '\0') {
        *dest++;
    }
    
    for(int i = 0; i < n; ++i) {
        *(dest + i) = *(src++);
        if((*src) == '\0') break;
    }

    return out;
}

int main() {
    char dest0[50] = "";
    assert(dest0 == strncat(dest0, "pog", 3));
    assert('p' == dest0[0]);
    assert('o' == dest0[1]);
    assert('g' == dest0[2]);
    assert(dest0 == strncat(dest0, "pog", 3));
    assert('p' == dest0[3]);

    char src1[50] = "Ze Warudo!";
    char dest1[50] = "Ze Hando, ";
    strncat(dest1, src1, 15);

    char res1[50] = "Ze Hando, Ze Warudo!";
    for(int i = 0; i < 20; ++i) {
        assert(dest1[i] == res1[i]);
    }

    char src2[50] = "Ze Warudo!";
    char dest2[50] = "Ze Hando, ";
    strncat(dest2, src2, 0);
    assert(dest2[10] == '\0');

    return 0;
}