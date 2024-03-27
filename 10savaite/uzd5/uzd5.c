#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void* memset(void *str, int c, int n) {
    char* tmp = str;

    for(int i = 0; i < n; ++i) {
        *tmp = c;
        tmp++;
    }
    
    return str;
}

int main() {
    char str[50] = "Dio Brando";
    memset(str, 'a', 2);

    assert(str[0] == 'a');
    assert(str[1] == 'a');
    assert(str[2] == 'o');

    memset(str, 'a', 50);
    for(int i = 0; i < 50; ++i) {
        assert(str[i] == 'a');
    }

    memset(str, '\n', 3);

    assert(str[0] == '\n');
    assert(str[1] == '\n');
    assert(str[2] == '\n');
    assert(str[3] == 'a');

    return 0;
}