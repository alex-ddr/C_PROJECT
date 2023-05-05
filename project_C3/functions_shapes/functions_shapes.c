#include <stdio.h>
#include "stdlib.h"
#include "../shapes/shapes.h"
#include "stdbool.h"
#include "functions_shapes.h"
#include "../id/id.h"

// Function to get a polygon from the user
Polygon* get_polygon(int n) {
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


Shape *get_shape_from_node(NODE *node) {
    return &(node->shape);
}

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

