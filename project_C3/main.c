#include <stdio.h>
#include "shapes/shapes.h"
#include "menu/menu.h"
#include "area/area.h"
int main() {
    Area* draw_zone = create_area(15, 15);
    LIST l = NULL;

    while (1) {
        char input[50];
        read_input(&input);
        compare_string(&input, draw_zone, &l);
        printf("\n");
    }
}