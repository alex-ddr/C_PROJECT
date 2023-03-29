#ifndef SHAPES_H
#define SHAPES_H

// POINT DEFINITION
typedef struct point {
    int pos_x;
    int pos_y;
} Point;

Point *create_point(int px, int py);
void delete_point(Point *point);
void print_point(Point *p);

// LINE DEFINITION
typedef struct line {
    Point *p1;
    Point *p2;
} Line;

Line *create_line(Point *p1, Point *p2);
void delete_line(Line *line);
void print_line(Line *line);

// SQUARE DEFINITION
typedef struct square{
    Point *top_left;
    int side_length;
} Square;

Square *create_square(Point *point, int length);
void delete_square(Square *square);
void print_square(Square *square);

// RECTANGLE DEFINITION
typedef struct rectangle {
    Point *top_left;
    int width;
    int height;
}Rectangle;
Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

// CIRCLE DEFINITION
typedef struct circle {
   Point *center;
   int radius;
}Circle;
Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

// POLYGON DEFINITION
typedef struct polygon {
    int n;
    Point ** points;
}Polygon;
Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);

// OTHER
typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;
typedef struct shape {
    int id; // unique identifier of the shape
    SHAPE_TYPE shape_type; // type of the shape pointed
    void *ptrShape; // pointer to any shape
}Shape;

Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape();
Shape *create_line_shape();
Shape *create_square_shape();
Shape *create_rectangle_shape();
Shape *create_circle_shape();
Shape *create_polygon_shape();
void delete_shape(Shape * shape);
void print_shape(Shape * shape);

#endif // SHAPES_H

