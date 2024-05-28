#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
# (2) -> (10)
- 11011             -> 27
- 10010100          -> 148
- 11001011010101    -> 13013

# (10) -> (2)
- 37    -> 100101
- 241   -> 11110001
- 2487  -> 100110110111

# (16) -> (10)
- 6E2   -> 1762
- ED33  -> 60723
- 123456-> 1193046

# (10) -> (16)
- 243   -> F3 
- 2483  -> 9B3
- 4612  -> 1204
*/

char* decToBinary(int n) {
    int binary[32], i = 0;

    for(i = 0; n > 0; i++) {
        binary[i] = n % 2;
        n = n / 2;
    }

    char* out = malloc(sizeof(char) * (i + 1));
    for(int j = i - 1; j >= 0; j--) 
        out[(i - 1) - j] = (binary[j] == 1 ? '1' : '0');
    
    out[i] = '\0';
    return out;
}

int main(void) {
    // (2) -> (10)
    uintptr_t a1 = 0b0;
    printf("11011 -> %d \n", a1);
    uintptr_t a2 = 0b10010100;
    printf("10010100 -> %d \n", a2);
    uintptr_t a3 = 0b11001011010101;
    printf("11001011010101 -> %d \n \n", a3);

    // (10) -> (2)
    uintptr_t b1 = 37;
    printf("37 -> %s \n", decToBinary(b1));
    uintptr_t b2 = 241;
    printf("241 -> %s \n", decToBinary(b2));
    uintptr_t b3 = 2487;
    printf("2487 -> %s\n \n", decToBinary(b3));

    // (16) -> (10)
    uintptr_t c1 = 0x6E2;
    printf("6E2 -> %d \n", c1);
    uintptr_t c2 = 0xED33;
    printf("ED33 -> %d \n", c2);
    uintptr_t c3 = 0x123456;
    printf("123456 -> %d \n \n", c3);

    // (10) -> (16)
    printf("243 -> %x \n", 243);
    printf("2483 -> %x \n", 2483);
    printf("4612 -> %x \n", 4612);

    return 0;
}