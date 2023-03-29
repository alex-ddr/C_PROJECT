#include <stdio.h>
#include "shapes.h"
#include "functions_shapes.h"

int main() {
    Shape * f1= create_point_shape();
    print_shape(f1);
    delete_shape(f1);

    Shape * f2 = create_line_shape();
    print_shape(f2);
    delete_shape(f2);


    Shape * f3 = create_square_shape();
    print_shape(f3);
    delete_shape(f3);


    Shape * f4 = create_rectangle_shape();
    print_shape(f4);
    delete_shape(f4);


    Shape * f5 = create_circle_shape();
    print_shape(f5);
    delete_shape(f5);


    Shape * f6 = create_polygon_shape();
    print_shape(f6);
    delete_shape(f6);
    return 0;
}



    /*// Get a point from the user and print it
    Point * point = get_point();
    print_point(point);

    // Get a line from the user and print it
    Line *line = get_line();
    print_line(line);

    // Get a square from the user and print it
    Square *square = get_square();
    print_square(square);

    // Get a rectangle from the user and print it
    Rectangle *rectangle = get_rectangle();
    print_rectangle(rectangle);

    // Get a circle from the user and print it
    Circle *circle = get_circle();
    print_circle(circle);

    // Get a polygon from the user and print it
    Polygon *polygon = get_polygon();
    print_polygon(polygon);

    // Clean up memory
    delete_point(point);
    delete_line(line);
    delete_square(square);
    delete_rectangle(rectangle);
    delete_circle(circle);
    delete_polygon(polygon);*/

