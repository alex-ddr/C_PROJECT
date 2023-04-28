#ifndef PROJECT_C2_MENU_H
#define PROJECT_C2_MENU_H
#include "../shapes/shapes.h"
#include "../area/area.h"


void read_input(char* input);
int compare_string(char* str, Area* draw_zone, LIST l);




void menu(char *choice);
void menu2(int choice2, LIST  *l);
#endif //PROJECT_C2_MENU_H
