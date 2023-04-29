#ifndef PROJECT_C2_FUNCTIONS_SHAPES_H
#define PROJECT_C2_FUNCTIONS_SHAPES_H
#include "stdbool.h"
#include "../area/area.h"

Polygon *get_polygon();

NODE * create_node(Shape);
bool empty_list(LIST);
LIST add_tail_list(LIST , Shape);
void print_list(LIST);
void delete_node(LIST * l, int ID);

#endif //PROJECT_C2_FUNCTIONS_SHAPES_H