#include <stdio.h>
#include <stdlib.h>

#define RGB(r,g,b) ((r)+((g)<<5)+((b)<<10))

int main()
{
    int t = RGB(255, 255, 255);
    printf("%016X", t);
    return 0;
}
