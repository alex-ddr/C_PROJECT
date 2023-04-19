#include "stdlib.h"
#include "stdio.h"
#include "pixel.h"
#include "../shapes/shapes.h"

Pixel *create_pixel(int px, int py) {
    Pixel *pixel = (Pixel *)malloc(sizeof(Pixel)); // Correction : utiliser sizeof(Pixel) au lieu de sizeof(pixel)
    if (pixel == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return NULL;
    }

    pixel->px = px;
    pixel->py = py;

    return pixel;
}

void delete_pixel(Pixel * pixel)
{
    free(pixel);
    pixel = NULL;
}

void pixel_point(Shape* shape, Pixel** pixel, int* nb_pixels) {
    Point *pt = (Point *) shape->ptrShape;
    Pixel **pixel_tab = (Pixel **) malloc(sizeof(Pixel *));
    pixel_tab[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels = 1;
}


