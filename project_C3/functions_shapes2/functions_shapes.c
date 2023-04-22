#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "../shapes/shapes.h"
#include "functions_shapes.h"



// Function to get a point from the user
Point *get_point() {
    char input[256];
    int x, y;

    fgets(input, sizeof(input), stdin);

    int num_spaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_spaces++;
        }
    }

    if (num_spaces != 1) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    if (sscanf(input, "%d %d", &x, &y) != 2) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    Point *p = create_point(x, y);
    if (p == NULL) {
        printf("Error: Failed to allocate memory\n");
        return NULL;
    }

    return p;
}

// Function to get a line from the user
Line *get_line() {
    char input[256];
    int x1, y1, x2, y2;

    fgets(input, sizeof(input), stdin);

    int num_spaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_spaces++;
        }
    }

    if (num_spaces != 3) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    if (sscanf(input, "%d %d %d %d", &x1, &y1, &x2, &y2) != 4) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    Point *p1 = create_point(x1, y1);
    Point *p2 = create_point(x2, y2);
    Line *line = create_line(p1, p2);

    if (line == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }

    return line;
}

// Function to get a square from the user
Square *get_square() {
    char input[256];
    int x, y, l;

    fgets(input, sizeof(input), stdin);

    int num_spaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_spaces++;
        }
    }

    if (num_spaces != 2) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    if (sscanf(input, "%d %d %d", &x, &y, &l) != 3) {
        printf("Error: Invalid input format\n");
        return NULL;
    }
    Point *p = create_point(x,y);
    Square *square = create_square(p, l);
    if (square == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }
    return square;
}

// Function to get a rectangle from the user
Rectangle *get_rectangle() {
    char input[256];
    int x, y, width, height;

    fgets(input, sizeof(input), stdin);

    int num_spaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_spaces++;
        }
    }

    if (num_spaces != 3) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    if (sscanf(input, "%d %d %d %d", &x, &y, &width, &height) != 4) {
        printf("Error: Invalid input format\n");
        return NULL;
    }
    Point *p = create_point(x,y);
    Rectangle *rectangle = create_rectangle(p, width, height);
    if (rectangle == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }
    return rectangle;
}

// Function to get a circle from the user
Circle *get_circle() {
    char input[256];
    int x, y, radius;

    fgets(input, sizeof(input), stdin);

    int num_spaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_spaces++;
        }
    }

    if (num_spaces != 2) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    if (sscanf(input, "%d %d %d", &x, &y, &radius) != 3) {
        printf("Error: Invalid input format\n");
        return NULL;
    }
    Point *p = create_point(x,y);
    Circle *circle = create_circle(p, radius);

    if (circle == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }
    return circle;
}

// Function to get a polygon from the user
Polygon* get_polygon() {
    int n;
    printf("Enter the number of points in the polygon: ");
    scanf("%d", &n);

    Polygon* poly = create_polygon(n);

    if (poly == NULL) {
        printf("Error: failed to allocate memory for polygon.\n");
        return NULL;
    }

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
        printf("Empty list\n");
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


