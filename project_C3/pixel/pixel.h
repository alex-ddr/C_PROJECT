#ifndef PROJECT_C2_PIXEL_H
#define PROJECT_C2_PIXEL_H
#include "../shapes/shapes.h"

typedef struct pixel {
    int px;
    int py;
}Pixel;

Pixel *create_pixel(int px, int py);
void delete_pixel(Pixel * pixel);
void pixel_point(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_line(Line* line, Pixel** pixel, int* nb_pixels);
void pixel_circle(Circle* shape, Pixel** pixel, int *nb_pixels);
void pixel_square(Square* square, Pixel** pixel, int* nb_pixels);
void pixel_rectangle(Rectangle* rectangle, Pixel** pixel, int* nb_pixels);
void pixel_polygon(Polygon* polygon, Pixel** pixel, int* nb_pixels);
Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels);
void delete_pixel_shape(Pixel** pixel, int nb_pixels);


#endif //PROJECT_C2_PIXEL_H
