#include <stdlib.h>
#include <stdio.h>
#include "pixel.h"
#include "math.h"

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

void pixel_point(Shape* shape, Pixel** pixel) {
    Point *pt = (Point *) shape->ptrShape;
    pixel[0] = create_pixel(pt->pos_x, pt->pos_y);
}

void pixel_line(Line * line, Pixel ** pixel) {
    int x1 = line->p1->pos_x;
    int y1 = line->p1->pos_y;
    int x2 = line->p2->pos_x;
    int y2 = line->p2->pos_y;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steps = (dx > dy ? dx : dy) + 1;

    float x_inc = (float)(x2 - x1) / (float)(steps - 1);
    float y_inc = (float)(y2 - y1) / (float)(steps - 1);

    float x = (float)x1;
    float y = (float)y1;

    for (int i = 0; i < steps; ++i) {
        pixel[i] = create_pixel((int)(x + 0.5), (int)(y + 0.5));
        x += x_inc;
        y += y_inc;
    }
}

int pixel_circle(Circle* shape, Pixel*** pixel){
    int p_x = shape->center->pos_x, p_y = shape->center->pos_y;
    int radius = shape->radius;
    int max_pixels = (int)(2 * M_PI * radius) * 2; // Estimation du nombre maximum de pixels nécessaires

    *pixel = (Pixel **) malloc(max_pixels * sizeof(Pixel *));
    int i = -1;

    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (x <= y) {
        (*pixel)[++i] = create_pixel(p_x + x, p_y + y);
        (*pixel)[++i] = create_pixel(p_x + y, p_y + x);
        (*pixel)[++i] = create_pixel(p_x - x, p_y + y);
        (*pixel)[++i] = create_pixel(p_x - y, p_y + x);
        (*pixel)[++i] = create_pixel(p_x + x, p_y - y);
        (*pixel)[++i] = create_pixel(p_x + y, p_y - x);
        (*pixel)[++i] = create_pixel(p_x - x, p_y - y);
        (*pixel)[++i] = create_pixel(p_x - y, p_y - x);

        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }

    return i + 1;
}

void pixel_square(Square* square, Pixel** pixel){
    int l = square->side_length;
    int x = square->top_left->pos_x, y = square->top_left->pos_y;
    int k = -1;

    // top
    for (int i = 0; i < l; i++) {
        pixel[++k] = create_pixel(x + i, y);
    }

    // right
    for (int i = 1; i < l - 1; i++) {
        pixel[++k] = create_pixel(x + l - 1, y + i);
    }

    // bottom
    for (int i = 0; i < l; i++) {
        pixel[++k] = create_pixel(x + i, y + l - 1);
    }

    // left
    for (int i = 1; i < l - 1; i++) {
        pixel[++k] = create_pixel(x, y + i);
    }
}

void pixel_rectangle(Rectangle* rectangle, Pixel** pixel){
    int w = rectangle->width, h = rectangle->height;
    int x = rectangle->top_left->pos_x, y = rectangle->top_left->pos_y;
    int k = -1; // Change the initialization here

    // top
    for (int i=0; i < w; i++)
        pixel[++k] = create_pixel(x + i, y);

    // right
    for (int i=1; i < h-1; i++)
        pixel[++k] = create_pixel(x + w - 1, y + i);

    // bottom
    for (int i=0; i < w; i++)
        pixel[++k] = create_pixel(x + i, y + h - 1);

    // left
    for (int i=1; i < h - 1; i++)
        pixel[++k] = create_pixel(x, y + i);
}

void pixel_polygon(Polygon* polygon, Pixel** pixel){
int nb_vertex = polygon->n;
for(int i = 0; i < nb_vertex -1; i++)
{
    pixel_line(create_line(polygon->points[i], polygon->points[i+1]), pixel);
}
}

Pixel** create_shape_to_pixel(Shape * shape) {
    Pixel **pixel = NULL;
    int nb_pixels;
    switch (shape->shape_type) {
        case POINT:
            nb_pixels = 1;
            pixel = (Pixel **) malloc(nb_pixels * sizeof(Pixel *));
            pixel_point(shape, pixel);
            break;
        case LINE: {
            Line *line = shape->ptrShape;
            int dx = abs(line->p2->pos_x - line->p1->pos_x);
            int dy = abs(line->p2->pos_y - line->p1->pos_y);
            nb_pixels = (dx > dy ? dx : dy) + 1;
            pixel = (Pixel **) malloc((nb_pixels + 1) * sizeof(Pixel *));
            pixel_line(line, pixel);
            break;
        }
        case SQUARE: {
            Square *square = shape->ptrShape;
            nb_pixels = 4 * square->side_length - 4;
            pixel = (Pixel **) malloc((nb_pixels + 1) * sizeof(Pixel *));
            pixel_square(square, pixel);
            break;
        }
        case CIRCLE: {
            Circle *circle = shape->ptrShape;
            nb_pixels = pixel_circle(circle, &pixel);
            break;
        }
        case RECTANGLE: {
            Rectangle *rectangle = shape->ptrShape;
            nb_pixels = 2 * rectangle->width + 2 * rectangle->height - 4;
            pixel = (Pixel **) malloc((nb_pixels + 1) * sizeof(Pixel *));
            pixel_rectangle(rectangle, pixel);
            break;
        }
        default:
            printf("Error: Invalid shape\n");
        break;
    }
    pixel = realloc(pixel, (nb_pixels + 1) * sizeof(Pixel *));
    pixel[nb_pixels] = NULL;
    return pixel;
}

void delete_pixel_shape(Pixel** pixel, int nb_pixels)
{
    for (int i = 0; i < nb_pixels; i++) {
        delete_pixel(pixel[i]);
    }
    free(pixel);
}