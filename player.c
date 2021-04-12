#include <stdio.h>
#include <stdlib.h>
int *x;
int *y;
char *direction;

void create_player(int x,int y) {

}

void change_direction(char new_direction) {
    *direction = new_direction;
}

void update_position(char** map,int new_x,int new_y) {
    *x = new_x;
    *y = new_y;
    map[new_y][new_x];
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
