#include "menu.h"
#include "stdio.h"
#include "stdlib.h"
#include "../shapes/shapes.h"
#include "../functions_shapes/functions_shapes.h"
#include "string.h"
#include "../area/area.h"

void read_input(char* input) {
    printf("--> ");

    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
}


int compare_string(char* str, Area* draw_zone, LIST l){
    int x, y, z, w;

    if (strcmp(str, "clear") == 0) {
        system("cls");
        return 0;
    }

    else if (strcmp(str, "exit") == 0)
        exit(0);

    else if (strcmp(str, "plot") == 0)
        0; //we do nothing because at the end we eventually display the zone

    else if (strcmp(str, "list") == 0) {
        print_list(l);
        return 0;
    }

    else if (strcmp(str, "help") == 0) {
        printf("\n   - clear : clear the screen\n"
               "   - exit :  exit the program\n"
               "   - point x y :  add a point\n"
               "   - line x1 y1 x2 y2 :  add a segment connecting two points (x1, y1) and (x2, y2)\n"
               "   - circle x y radius :  add a circle of centre (x, y) and a radius radius\n"
               "   - square x y length :  add a square whose upper left corner is (x, y) and whose side is length.\n"
               "   - rectangle x y width height :  add a rectangle whose upper left corner is (x, y), whose width\n"
               "         is width and whose height is height\n"
               "   - polygon x1 y1 x2 y2 x3 y3 ... ... :  add a polygon with the list of given points\n"
               "   - plot :  refresh the screen to display all the geometric shapes in the image (depending on the\n"
               "         isplay rules)\n"
               "   - list :  display a list of all the geometric shapes that make up the image and all their information\n"
               "   - delete id :  delete a shape from its identifier id.\n"
               "   - erase :  remove all shapes from an image.\n\n"
        );
        return 0;
    }

    else if (sscanf(str, "point %d %d", &x, &y) == 2) {
        Shape* shape = create_point_shape(&l, x, y);
        add_shape_to_area(draw_zone, shape);
    }

    else if (sscanf(str, "line %d %d %d %d", &x, &y, &z, &w) == 4) {
        Shape* shape = create_line_shape(&l, x, y, z, w);
        add_shape_to_area(draw_zone, shape);
    }

    else if (sscanf(str, "circle %d %d %d", &x, &y, &z) == 3) {
        Shape* shape = create_circle_shape(&l, x, y, z);
        add_shape_to_area(draw_zone, shape);
    }

    else if (sscanf(str, "square %d %d %d", &x, &y, &z) == 3) {
        Shape* shape = create_square_shape(&l, x, y, z);
        add_shape_to_area(draw_zone, shape);
    }

    else if (sscanf(str, "rectangle %d %d %d %d", &x, &y, &z, &w) == 4) {
        Shape* shape = create_rectangle_shape(&l, x, y, z, w);
        add_shape_to_area(draw_zone, shape);
    }

    else{
        printf("Unidentified input");
        return 0;
    }


    draw_area(draw_zone);
    print_area(draw_zone);
}








/*
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
}*/