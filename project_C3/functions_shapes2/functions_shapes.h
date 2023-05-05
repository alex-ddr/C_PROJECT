#ifndef PROJECT_C2_FUNCTIONS_SHAPES_H
#define PROJECT_C2_FUNCTIONS_SHAPES_H
#include "stdbool.h"

Point *get_point();
Line *get_line();
Square *get_square();
Rectangle *get_rectangle();
Circle *get_circle();
Polygon *get_polygon();

NODE * create_node(Shape);
bool empty_list(LIST);
LIST add_tail_list(LIST , Shape);
void print_list(LIST);

#endif //PROJECT_C2_FUNCTIONS_SHAPES_H
