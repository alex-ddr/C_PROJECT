#ifndef PROJECT_C2_PIXEL_H
#define PROJECT_C2_PIXEL_H
#include "../shapes/shapes.h"
#include "../area/area.h"

typedef struct pixel {
    int px;
    int py;
}Pixel;

Pixel *create_pixel(int px, int py);
void delete_pixel(Pixel * pixel);
void pixel_point(Shape* shape, Pixel** pixel);
void pixel_line(Line* line, Pixel** pixel);
int pixel_circle(Circle* shape, Pixel*** pixel);
void pixel_square(Square* square, Pixel** pixel);
void pixel_rectangle(Rectangle* rectangle, Pixel** pixel);
void pixel_polygon(Polygon* polygon, Pixel** pixel);
Pixel** create_shape_to_pixel(Shape * shape);
void delete_pixel_shape(int k, Area * area);

#endif //PROJECT_C2_PIXEL_H