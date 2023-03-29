#include <stdio.h>
#include "stdlib.h"
#include "shapes.h"
#include "functions_shapes.h"


// POINT DEFINITION
Point* create_point(int px, int py)
{
    Point *point = (Point*) malloc(sizeof(Point));
    if (point == NULL) {
        printf("Error: Failed to allocate memory for point.\n");
        return NULL;
    }
    point ->pos_x = px;
    point->pos_y = py;
    return point;
}

void delete_point(Point * point)
{
    free(point);
    point = NULL;
}

void print_point(Point * p)
{
    printf("POINT %d %d\n", p->pos_x, p->pos_y);
}

//LINE DEFINITION
Line *create_line(Point * p1, Point * p2)
{
    Line *line = (Line*) malloc(sizeof(Line));
    if (line == NULL) {
        printf("Error: Failed to allocate memory for line.\n");
        return NULL;
    }
    line->p1 = p1;
    line->p2 = p2;
    return line;
}

void delete_line(Line * line)
{
    free(line);
    line = NULL;
}

void print_line(Line * line)
{
    printf("LINE %d %d %d %d\n", line->p1-> pos_x, line->p1-> pos_y, line->p2-> pos_x, line->p2-> pos_y);

}

//SQUARE DEFINITION
Square *create_square(Point * point, int length)
{
    Square *square = (Square*) malloc(sizeof(Square));
    if (square == NULL) {
        printf("Error: Failed to allocate memory for square.\n");
        return NULL;
    }
    square->top_left = point;
    square->side_length = length;
    return square;
}

void delete_square(Square * square)
{
    free(square);
    square = NULL;
}

void print_square(Square * square) {
    printf("SQUARE %d %d %d %d %d %d %d %d\n",
           square->top_left->pos_x, square->top_left->pos_y,
           square->top_left->pos_x + square->side_length, square->top_left->pos_y,
           square->top_left->pos_x, square->top_left->pos_y + square->side_length,
           square->top_left->pos_x + square->side_length, square->top_left->pos_y + square->side_length);
}

// RECTANGLE DEFINITION
Rectangle *create_rectangle(Point * point, int width, int height)
{
    Rectangle *rectangle = (Rectangle*) malloc(sizeof(Rectangle));
    if (rectangle == NULL) {
        printf("Error: Failed to allocate memory for rectangle.\n");
        return NULL;
    }
    rectangle->top_left = point;
    rectangle->height = height;
    rectangle->width = width;
    return rectangle;
}

void delete_rectangle(Rectangle * rectangle)
{
    free(rectangle);
    rectangle = NULL;
}

void print_rectangle(Rectangle * rectangle)
{
    printf("RECTANGLE %d %d %d %d %d %d %d %d\n",
           rectangle->top_left->pos_x, rectangle->top_left->pos_y,
           rectangle->top_left->pos_x + rectangle->height, rectangle->top_left->pos_y,
           rectangle->top_left->pos_x, rectangle->top_left->pos_y + rectangle->width,
           rectangle->top_left->pos_x + rectangle->height, rectangle->top_left->pos_y + rectangle->width);
}

// CIRCLE DEFINITION
Circle *create_circle(Point * center, int radius)
{
    Circle *circle = (Circle*) malloc(sizeof(Circle));
    if (circle == NULL) {
        printf("Error: Failed to allocate memory for circle.\n");
        return NULL;
    }
    circle->center = center;
    circle->radius = radius;
    return circle;
}

void delete_circle(Circle * circle)
{
    free(circle);
    circle = NULL;
}

void print_circle(Circle * circle)
{
// need to ask what are we supposed to do?
    printf("CIRCLE Center: %d,%d | Radius: %d\n",
           circle->center->pos_x, circle->center->pos_y,
           circle->radius);
}

// POLYGON DEFINITION

Polygon *create_polygon(int n)
{
    Polygon *polygon = malloc(sizeof(Polygon));
    if (polygon == NULL) {
        return NULL;
    }
    Point **points = calloc(n, sizeof(Point *));
    if (points == NULL) {
        free(polygon);
        return NULL;
    }

    polygon->n = n;
    polygon->points = points;

    return polygon;
}

void delete_polygon(Polygon * polygon)
{
    if (polygon == NULL) {
        return;
    }

    for (int i = 0; i < polygon->n; i++) {
        delete_point(polygon->points[i]);
        polygon->points[i] = NULL;
    }

    free(polygon->points);
    polygon->points = NULL;
    free(polygon);
}

void print_polygon(Polygon * polygon)
{
    printf("POLYGON ");
    for (int i = 0; i < polygon->n; i++) {
        if (polygon->points[i] != NULL) {
            printf("%d %d ", polygon->points[i]->pos_x, polygon->points[i]->pos_y);
        } else {
            printf("NULL\n");
        }
    }
}

// CREAT EMPTY SHAPE
Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = shape_type;
    return shp;
}

// SHAPE POINT
Shape *create_point_shape()
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = get_point();
    shp->ptrShape = p;
    return shp;
}

// SHAPE LINE
Shape *create_line_shape()
{
    Shape *shp = create_empty_shape(LINE);
    Line * line = get_line();
    shp->ptrShape = line;
    return shp;
}

// SHAPE SQUARE
Shape *create_square_shape()
{
    Shape *shp = create_empty_shape(SQUARE);
    Square * square= get_square();
    shp->ptrShape = square;
    return shp;
}

// SHAPE RECTANGLE
Shape *create_rectangle_shape()
{
    Shape *shp = create_empty_shape(RECTANGLE);
    Rectangle * rectangle = get_rectangle();
    shp->ptrShape = rectangle;
    return shp;
}

// SHAPE CIRCLE
Shape *create_circle_shape()
{
    Shape *shp = create_empty_shape(CIRCLE);
    Circle * circle= get_circle();
    shp->ptrShape = circle;
    return shp;
}

// SHAPE POLYGON
Shape *create_polygon_shape()
{
    Shape *shp = create_empty_shape(POLYGON);
    Polygon * polygon= get_polygon();
    shp->ptrShape = polygon;
    return shp;
}

// PRINT SHAPE
void print_shape(Shape * shape)
{
    if (shape == NULL) {
        printf("Error: Null shape\n");
        return;
    }

    switch (shape->id) {
        case POINT:
            print_point(shape->ptrShape);
            break;
        case LINE:
            print_line(shape->ptrShape);
            break;
        case SQUARE:
            print_square(shape->ptrShape);
            break;
        case RECTANGLE:
            print_rectangle(shape->ptrShape);
            break;
        case CIRCLE:
            print_circle(shape->ptrShape);
            break;
        case POLYGON:
            print_polygon(shape->ptrShape);
            break;
        default:
            printf("Error: Invalid shape ID\n");
            break;
    }
}

// DELETE SHAPE
void delete_shape(Shape * shape)
{
    free(shape);
    shape = NULL;
}