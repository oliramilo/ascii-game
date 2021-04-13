#include <stdio.h>
#include <stdlib.h>
#include "controller.h"

void create_player(int* x,int* y) {
    x = (int*)malloc(sizeof(int));
    y = (int*)malloc(sizeof(int));
}

void change_direction(char* direction, char new_direction) {
    if(new_direction == *direction) {
        update_position();
    }
    if(check_direction(direction,new_direction)) {
        update_direction(direction,new_direction);
    }
}

void update_direction(char* direction,char new_direction) {
    *direction = new_direction;
}

void update_position(char** map,int new_x,int new_y) {
    int size_y = sizeof(map) / sizeof(map[0]);
    int size_x = sizeof(map[0]) / size_y;
    if(check_bounds(new_x,new_y,size_x,size_y)) {
        *x = new_x;
        *y = new_y;
        map[new_y][new_x];
    }
}


int get_x() {
    return *x;
}

int get_x() {
    return *y;
}

char get_direction() {
    return *direction;
}
