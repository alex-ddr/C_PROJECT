#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pixel.h"

Pixel *create_pixel(int px, int py) {
    Pixel *pixel = (Pixel *)malloc(sizeof(Pixel));
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
    pixel[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels = 1;
}

void pixel_line(Line* line, Pixel** pixel, int* nb_pixels) {
    unsigned int dx = line->p2->pos_x - line->p1->pos_x;
    int dy = line->p2->pos_y - line->p1->pos_y;
    int dmin = fmin(dx, abs(dy)), dmax = fmax(dx, abs(dy));
    int nb_segs = dmin + 1;
    int seg_size = (dmax + 1) / (dmin + 1);

    int *segments = (int *) malloc(sizeof(int) * nb_segs);
    for (int i = 0; i < nb_segs; i++)
        segments[i] = seg_size;

    int *cumuls = (int *) malloc(nb_segs * sizeof(int));
    cumuls[0] = 0;
    int remaining = (dmax + 1) % (dmin + 1);

    for (int i = 1; i < nb_segs; i++) {
        cumuls[i] = ((i * remaining) % (dmin + 1) < (i - 1) * remaining) % (dmin + 1);
        segments[i] = segments[i] + cumuls[i];
    }

    int x = line->p1->pos_x ;
    int y = line->p1->pos_y ;
    int err = 0;

    *nb_pixels = dmax + 1;
    for (int i = 0; i < nb_segs; i++) {
        for (int j = 0; j < segments[i]; j++) {
            pixel[j + i * seg_size] = create_pixel(x, y);

            if (dy < 0) {
                // downward
                if (dx > abs(dy)) {
                    // horizontal
                    x++;
                    err += abs(dy);
                    if (err > dmin) {
                        y--;
                        err -= dmin;
                    }
                } else {
                    // vertical
                    y--;
                    err += dx;
                    if (err > dmin) {
                        x++;
                        err -= dmin;
                    }
                }
            } else {
                // upwards
                if (dx > dy) {
                    // horizontal
                    x++;
                    err += dy;
                    if (err > dmin) {
                        y++;
                        err -= dmin;
                    }
                } else {
                    // vertical
                    y++;
                    err += dx;
                    if (err > dmin) {
                        x++;
                        err -= dmin;
                    }
                }
            }
        }
        // Add the segment transition movement
        if (dy < 0) {
            if (dx > abs(dy)) y--;
            else x++;
        } else {
            if (dx > dy) y++;
            else x++;
        }
    }
    free(segments);
    free(cumuls);
}

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels)
{
    Pixel ** pixel = NULL;
    switch (shape->shape_type) {
        case POINT:
            pixel = (Pixel**) malloc(2 * sizeof(Pixel*));
            pixel_point(shape, pixel, nb_pixels);
            break;
        case LINE:
            pixel = (Pixel**) malloc((*nb_pixels + 1) * sizeof(Pixel));
            pixel_line(shape->ptrShape, pixel, nb_pixels);
            break;
        default:
            printf("Error: Invalid shape\n");
            break;
    }
    pixel[*nb_pixels] = NULL;
    return pixel;
}

void delete_pixel_shape(Pixel** pixel, int nb_pixels)
{
    for (int i = 0; i < nb_pixels; i++) {
        delete_pixel(pixel[i]);
    }
    free(pixel);
}