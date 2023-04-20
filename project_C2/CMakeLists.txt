cmake_minimum_required(VERSION 3.24)
project(project_C2 C)

set(CMAKE_C_STANDARD 23)

add_executable(project_C2 main.c shapes.c shapes.h id.c id.h functions_shapes.c functions_shapes.h menu.c menu.h)
