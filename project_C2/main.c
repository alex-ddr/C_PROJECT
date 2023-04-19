#include <stdio.h>
#include "shapes.h"
#include "functions_shapes.h"

int main() {
    LIST l = NULL;
    Shape * s1= create_point_shape(&l);
    print_shape(s1);

    Shape * s2 = create_line_shape(&l);
    print_shape(s2);

    Shape * s3 = create_square_shape(&l);
    print_shape(s3);

    Shape * s4 = create_rectangle_shape(&l);
    print_shape(s4);

    Shape * s5 = create_circle_shape(&l);
    print_shape(s5);

    Shape * s6 = create_polygon_shape(&l);
    print_shape(s6);


    print_list(l);

    delete_shape(s1);
    delete_shape(s2);
    delete_shape(s3);
    delete_shape(s4);
    delete_shape(s5);
    delete_shape(s6);

    return 0;
}