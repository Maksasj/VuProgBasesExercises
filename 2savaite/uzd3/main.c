#include <stdio.h>

int main(void) {
    int input;
    scanf("%d", &input);
    const char* out = (input % 2 == 0 ? "\nNumber is even \n" : "\nNumber is not even \n");
    printf("%s", out);
    
    return 0;
}