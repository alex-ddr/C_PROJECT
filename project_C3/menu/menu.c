#include "menu.h"
#include "stdio.h"
#include "../shapes/shapes.h"
#include "../functions_shapes/functions_shapes.h"

void menu(char *choice)
{
    do{
        printf("Please select an action:\n"
               "A- Add a shape\n"
               "B- Display the list of shapes\n");
        scanf(" %c", &(*choice));

    }while((*choice!='A') && (*choice!= 'B'));
    printf("\n");

}

void menu2(int choice2, LIST  * l)
{
    Shape *s1;
    switch (choice2) {
        case 1:
            s1= create_point_shape(l);
            print_shape(s1);
            break;
        case 2:
            s1 = create_line_shape(l);
            print_shape(s1);
            break;
        case 3:
            s1 = create_square_shape(l);
            print_shape(s1);
            break;
        case 4:
            s1 = create_rectangle_shape(l);
            print_shape(s1);
            break;
        case 5:
            s1 = create_circle_shape(l);
            print_shape(s1);
            break;
        case 6:
            s1 = create_polygon_shape(l);
            print_shape(s1);
            break;
        default:
            printf("\n");
            break;
    }
}