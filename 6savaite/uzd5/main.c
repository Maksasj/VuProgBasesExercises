#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("This program validates, and stores email addresses in file 'emails.txt'\n");
    
    while (1) {
        char buffer[256];
        scanf("%s", buffer);

        char user[256], site[256], domain[256];

        if( sscanf( buffer, "%[^@ \t\n]@%[^. \t\n].%3[^ \t\n]", user, site, domain ) != 3 ) {
            printf("Error, while parsing email \n");
            fflush(stdin);
            continue;
        }

        if(strlen(user) < 1) {
            printf("Error user could not be shorter than 1 symbol \n");
            fflush(stdin);
            continue;
        }

        if(strlen(site) < 1) {
            printf("Site user could not be shorter than 1 symbol \n");
            fflush(stdin);
            continue;
        }

        if(strlen(domain) < 1) {
            printf("Domain user could not be shorter than 1 symbol \n");
            fflush(stdin);
            continue;
        }

        printf("Entered email: %s \n", buffer);

        FILE* file = fopen("emails.txt", "a+");
        if(file == NULL) {
            printf("Error acquired while trying to open file emails.txt \n");
            fflush(stdin);
            continue;
        }

        fprintf(file, "%s \n", buffer);
        fclose(file);

        break;
    }
    
    return 0;
}