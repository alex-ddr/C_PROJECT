#include <stdio.h>
#include "shapes.h"
#include "functions_shapes.h"
#include "menu.h"
int main() {
    LIST l = NULL;
    while (1) {
        char choice;
        int choice2;
        menu(&choice);

        if (choice == 'A')
        {
            do {
                printf("Please select an action:\n"
                       "1- Add a point\n"
                       "2- Add a line\n"
                       "3- Add square\n"
                       "4- Add a rectangle\n"
                       "5- Add a circle\n"
                       "6- Add a polygon\n"
                       "7- Return to previous menu\n");
                scanf("%d", &choice2);
            } while ((choice2 != 1) && (choice2 != 2) && (choice2 != 3) && (choice2 != 4) && (choice2 != 5) && (choice2 != 6) &&
                    (choice2 != 7));
            menu2(choice2, &l);
            printf("\n");
        }
        else{
            print_list(l);
            printf("\n");
        }
    }
    return 0;
}