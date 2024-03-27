#include <stdlib.h>
#include <assert.h>

char* strchr(const char *str, char c) {
    char* out = NULL;

    while (*str != '\0') {
        if(c == *str) {
            out = str;
            break;
        }
        str++;
    }

    return out;
}

int main() {
    assert(*strchr("poggers", 'p') == 'p');
    assert(strchr("Kira Yoshikage", 'p') == NULL);
    assert(*strchr("Za warudo", 'w') == 'w');
    assert(strchr("Killer Queen", '\0') == NULL);

    return 0;
}