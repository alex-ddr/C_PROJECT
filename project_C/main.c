#include <stdio.h>
#include "shapes/shapes.h"
#include "menu/menu.h"
#include "area/area.h"
#include "stdlib.h"

int main() {
    Area* draw_zone = create_area(40, 40);

    LIST l = NULL;
    int* current_ids = (int*) malloc(sizeof(int)*SHAPE_MAX);


    while (1) {
        char input[50];
        read_input(&input);
        compare_string(&input, draw_zone, &l, current_ids);
        printf("\n");
    }
}