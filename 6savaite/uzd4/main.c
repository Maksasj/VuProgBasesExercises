#include <stdio.h>
#include <stdio.h>

int main() {
    printf("This program calculates day of week from current date \n");
    int d, m, y;

    input:
        do {
            fflush(stdin);
            printf("Please enter date in YYYY-MM-DD format\n");
        } while (scanf("%d-%d-%d",&y,&m,&d) != 3);

    if(d < 0) {
        printf("Days could not be negative \n");
        goto input;
    }

    if(m < 0) {
        printf("Months could not be negative \n");
        goto input;
    }

    if(y < 0) {
        printf("Years could not be negative \n");
        goto input;
    }

    int weekday = (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7; 
    weekday = (weekday == 0 ? 7 : weekday) - 1;

    FILE* file = fopen("week.txt", "r");
    if(file == NULL) {
        printf("Error acquired while trying to open file 'week.txt' \n");
        return 1;
    }
    
    int n = 0;
    char line[256]; 
    char* day_of_week;
    while (fgets(line, sizeof line, file) != NULL) {
        if (n == weekday) {
           day_of_week = line;
           break;
        } else {
            n++;
        }
    }
    printf("Today is a %s", day_of_week);
    fclose(file);
    return 0;
}