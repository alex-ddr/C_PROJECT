cmake_minimum_required(VERSION 3.24)
project(project_C2 C)

set(CMAKE_C_STANDARD 23)

add_executable(project_C2 main.c shapes/shapes.c shapes/shapes.h id/id.c id/id.h functions_shapes/functions_shapes.c functions_shapes/functions_shapes.h area/area.c area/area.h pixel/pixel.h pixel/pixel.c area/area.c area/area.c)
