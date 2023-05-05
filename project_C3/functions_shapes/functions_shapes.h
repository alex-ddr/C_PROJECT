#ifndef PROJECT_C2_FUNCTIONS_SHAPES_H
#define PROJECT_C2_FUNCTIONS_SHAPES_H
#include "stdbool.h"
#include "../area/area.h"

Polygon *get_polygon(int n);

NODE * create_node(Shape);
bool empty_list(LIST);
LIST add_tail_list(LIST , Shape);
Shape *get_shape_from_node(NODE *node);
void print_list(LIST);

#endif //PROJECT_C2_FUNCTIONS_SHAPES_H