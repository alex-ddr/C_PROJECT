#include <stdio.h>
#include "stdlib.h"
#include "shapes.h"
#include "string.h"
#include "stdbool.h"
#include "functions_shapes.h"

// Function to get a point from the user
Point *get_point() {
    int x, y;
    printf("Enter the coordinates x y:");
    scanf("%d %d", &x, &y);
    Point *p = create_point(x, y);
    return p;
}
// Function to get a line from the user
Line *get_line() {
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the first point x y:");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point x y:");
    scanf("%d %d", &x2, &y2);
    Point *p1 = create_point(x1, y1);
    Point *p2 = create_point(x2, y2);
    Line *line = create_line(p1, p2);
    return line;
}

// Function to get a square from the user
Square *get_square() {
    int x, y, l;
    printf("Enter the coordinates of the point x y:");
    scanf("%d %d", &x, &y);
    printf("Enter the length of the square:");
    scanf("%d", &l);
    Point *p = create_point(x,y);
    Square *square = create_square(p, l);
    return square;
}

// Function to get a rectangle from the user
Rectangle *get_rectangle() {
    int x, y, width, height;
    printf("Enter the coordinates of the point x y:");
    scanf("%d %d", &x, &y);
    Point *p = create_point(x,y);
    printf("Enter the width of the rectangle:");
    scanf("%d", &width);
    printf("Enter the width of the rectangle:");
    scanf("%d", &height);
    Rectangle *rectangle = create_rectangle(p, width, height);
    return rectangle;
}

// Function to get a circle from the user
Circle *get_circle() {
    int x, y, radius;
    printf("Enter the coordinates of the point x y:");
    scanf("%d %d", &x, &y);
    printf("Enter the radius of the circle:");
    scanf("%d", &radius);
    Point *p = create_point(x,y);
    Circle *circle = create_circle(p, radius);

    return circle;
}

// Function to get a polygon from the user
Polygon* get_polygon() {
    int n;
    printf("Enter the number of points in the polygon: ");
    scanf("%d", &n);

    Polygon* poly = create_polygon(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        printf("point %d: ", i+1);
        scanf("%d %d", &x, &y);
        Point* p = create_point(x, y);
        poly->points[i] = p;
    }
    return poly;
}

// LIST OF SHAPE
NODE* create_node(Shape shp)
{
    NODE * node = (NODE*) malloc(sizeof(NODE));
    node->shape = shp;
    node->succ = NULL;
    return node;
}

bool empty_list(LIST l)
{
    if (l == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

LIST add_tail_list(LIST l , Shape shp)
{
    if (empty_list(l))
    {
        l = create_node(shp);
    }
    else
    {
        NODE * currentNode = l;
        while (currentNode->succ != NULL)
        {
            currentNode = currentNode->succ;
        }
        currentNode-> succ = create_node(shp);
    }
    return l;
}
// Add this function to your code
Shape *get_shape_from_node(NODE *node) {
    return &(node->shape);
}

// Updated print_list function
void print_list(LIST l)
{
    if (empty_list(l))
    {
        printf("Empty list");
    }
    else
    {
        NODE *currentNode = l;
        printf("The list of shapes:\n");
        while (currentNode->succ != NULL)
        {
            print_shape(get_shape_from_node(currentNode));
            currentNode = currentNode->succ;
        }
        print_shape(get_shape_from_node(currentNode));
    }
}


