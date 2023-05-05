cmake_minimum_required(VERSION 3.24.2)
project(projet_C4 C)

set(CMAKE_C_STANDARD 23)

add_executable(projet_C4 main.c shapes/shapes.c shapes/shapes.h id/id.c id/id.h functions_shapes/functions_shapes.c functions_shapes/functions_shapes.h area/area.c area/area.h pixel/pixel.h pixel/pixel.c area/area.c area/area.c menu/menu.c menu/menu.h)
