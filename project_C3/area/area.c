#include "stdlib.h"
#include "stdio.h"
#include "area.h"
#include "../pixel/pixel.h"
#include "../shapes/shapes.h"


Area* create_area(unsigned int width, unsigned int height) {
    Area * area = (Area*) malloc(sizeof(Area));
    if (area == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return NULL;
    }
    area->width = width;
    area->height = height;
    area->nb_shape = 0;

    area->mat = (BOOL**) malloc(height * sizeof(BOOL*));
    if (area->mat == NULL) {
        printf("Error: Failed to allocate memory.\n");
        free(area);
        return NULL;
    }

    for (unsigned int i = 0; i < height; i++) {
        area->mat[i] = (BOOL*) malloc(width * sizeof(BOOL));
        if (area->mat[i] == NULL) {
            printf("Error: Failed to allocate memory.\n");
            for (unsigned int j = 0; j < i; j++) {
                free(area->mat[j]);
            }
            free(area->mat);
            free(area);
            return NULL;
        }
    }

    return area;
}

void add_shape_to_area(Area* area, Shape* shape) {
    if (area->nb_shape < SHAPE_MAX) {
        area->shapes[area->nb_shape] = shape;
        area->nb_shape += 1;
    } else {
        printf("Error: Maximum number of shapes reached.\n");
    }
}

void clear_area(Area* area) {
    for (unsigned int i = 0; i < area->height; i++) {
        for (unsigned int j = 0; j < area->width; j++) {
            area->mat[i][j] = 0;
        }
    }
}

void erase_area(Area* area) {
    for (int i = 0; i < area->nb_shape; i++) {
        free(area->shapes[i]);
        area->shapes[i] = NULL;
    }
    area->nb_shape = 0;
}


void delete_area(Area* area)
{
    if (area == NULL) {
        printf("Error: Area is NULL.\n");
        return;
    }

    erase_area(area);

    for (unsigned int i = 0; i < area->height; i++) {
        free(area->mat[i]);
    }
    free(area->mat);
    free(area);

}

/*void draw_area(Area* area) {
    if (area == NULL) {
        printf("Error: Area is NULL.\n");
        return;
    }

    for (int i = 0; i < area->nb_shape; i++) {
        Shape* current_shape = area->shapes[i];

        Pixel** pixel_list = create_shape_to_pixel(current_shape);

        for (int j = 0; pixel_list[j] != NULL; j++) {
            Pixel* current_pixel = pixel_list[j];
            unsigned int x = current_pixel->x;
            unsigned int y = current_pixel->y;

            if (x < area->height && y < area->width) {
                area->mat[x][y] = 1;
            }

            free(current_pixel);
        }

        free(pixel_list);
    }
}
*/

void print_area(Area* area) {
    if (area == NULL) {
        printf("Error: Area is NULL.\n");
        return;
    }

    for (unsigned int i = 0; i < area->height; i++)
    {
        for (unsigned int j = 0; j < area->width; j++)
        {
            if (area->mat[i][j] == 1) {
                printf("%c", 35);
            } else {
                printf("%c", 46);
            }
        }
        printf("\n");
    }
}
