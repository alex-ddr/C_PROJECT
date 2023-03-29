#include <stdio.h>
#include "stdlib.h"
#include "shapes.h"
#include "string.h"

// Function to get a point from the user
Point *get_point() {
    char input[256];
    int x, y;

    fgets(input, sizeof(input), stdin);

    // Count the number of spaces in the input
    int num_spaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_spaces++;
        }
    }

    // Check that there is exactly one space in the input
    if (num_spaces != 1) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    // Parse the input and create a point
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

    // Count the number of spaces in the input
    int num_spaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_spaces++;
        }
    }

    // Check that there is exactly one space in the input
    if (num_spaces != 3) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    // Parse the input and create a line
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

    // Count the number of spaces in the input
    int num_spaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_spaces++;
        }
    }

    // Check that there is exactly one space in the input
    if (num_spaces != 2) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    // Parse the input and create a point
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

    // Count the number of spaces in the input
    int num_spaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_spaces++;
        }
    }

    // Check that there is exactly one space in the input
    if (num_spaces != 3) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    // Parse the input and create a point
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

    // Count the number of spaces in the input
    int num_spaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_spaces++;
        }
    }

    // Check that there is exactly one space in the input
    if (num_spaces != 2) {
        printf("Error: Invalid input format\n");
        return NULL;
    }

    // Parse the input and create a point
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
