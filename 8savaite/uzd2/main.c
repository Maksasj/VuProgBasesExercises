#include <stdio.h>
#include <string.h>

char* get_file_name(int argc, char *argv[]) {
    if(argc <= 1) return NULL;

    int leng = 0;

    for(int i = 1; i < argc; ++i) {
        if(strlen(argv[i]) > strlen(argv[leng])) 
            leng = i;
    }
    
    return argv[leng];
}


int main( int argc, char *argv[] )  {
    char* file_name = get_file_name(argc, argv); 

    printf("%s", file_name);

    return 0;
}