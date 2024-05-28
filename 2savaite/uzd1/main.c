#include <stdio.h>

void printAsASCICode(const char* text, int length) {
    int i;

    for(i = 0; i < length; ++i)
        printf("%d", (int)text[i]);
}

int main(void) {
    const char* name = "maksim";
    
    printAsASCICode(name, 6);
    
    return 0;
}