#include <stdlib.h>
#include <assert.h>

int strlen(const char* in) {
    int out = 0;
    while(*in != '\0') {
        ++out;
        ++in;
    }
    return out;
}

int main() {
    assert(strlen("poggers") == 7);
    assert(strlen("Jojo reference") == 14);
    assert(strlen("") == 0);
    assert(strlen("\0") == 0);
    assert(strlen("\n") == 1);
    assert(strlen(NULL) == 0);
    assert(strlen("123456") == 6);

    return 0;
}