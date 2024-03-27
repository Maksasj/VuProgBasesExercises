#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

char* strcpy(char* dest, char* source) {
    for(int i = 0; 1; ++i) {
        dest[i] = source[i];
        if(source[i] == '\0') break;
    }
    return dest;
}

int main() {
    char str1[20] = "Za Warudo";
    char str2[20];
    char *str2_ptr = strcpy(str2, str1);
    assert(*str1 == *str2);
    assert(str2_ptr == str2);

    char str3[20] = "Made In Heaven";
    char str4[20] = "Za Warudo";
    char *str3_ptr = strcpy(str3, str4);
    assert(str3_ptr == str3);

    for(int i = 0; i < 9; ++i) {
        assert(*(str1 + i) == *(str2 + i));
    }

    return 0;
}