#include <stdio.h>
#include <stdlib.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg) {
    printf("%s \n", menuTitle);

    for(int i = 0; i < menuSize; ++i) {
        printf("%d) %s \n", i + 1, menuOptions[i]);
    }

    printf(inputMsg);

    while (1) {
        char tmp;
        int dish;

        fflush(stdin);
        int res = scanf("%d%c", &dish, &tmp);

        if(res != 2 || tmp != '\n') {
            printf("Sorry, query should contain only ONE number\n");
            printf("%s \n", inputMsg);
            continue;
        }

        if(dish > 0 && dish < menuSize + 1) {
            return dish - 1;
        }

        printf("Sorry, Query should be in range from 1 up to %d \n", menuSize);
        printf("%s \n", inputMsg);
    }
    
    return 0;
}

int main() {
    char *menuOptions[] = {
        "Salad",
        "Salmon",
        "Fries",
        "Milk shake",
        "Zeppelin",
        "Water"
    };

    int a = showMenu(
        "Maksim's 5-star restaurant",
        menuOptions,
        6,
        "Please choose your dish: "
    );

    printf("You have choosen dish number %d, %s", a + 1, menuOptions[a]);

    return 0;
}