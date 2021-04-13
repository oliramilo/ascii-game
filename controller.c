#include <stdio.h>
#include "controller.h"
#include "boolean.h"
static char WEST = 'L';
static char EAST = 'D';
static char NORTH = 'W';
static char SOUTH = 'S';
static char SHOOT = 'F';
static char UNKNOWN = 'U';


char get_player_input() {
    char direction;
    scanf("%c",direction);
    if(!check_direction(direction)) {
        direction = UNKNOWN;
    }
    return direction;
}


int check_bounds(int x,int y,int size_x,int size_y){
    int bool = (x >= 0 && x <= size_x && y >= 0 && y <= size_y) ? TRUE : FALSE;
    return bool;
}


int check_direction(char direction) {
    int bool = FALSE;
    switch(direction) {
        case WEST:
        case EAST:
        case NORTH:
        case SOUTH:
        case SHOOT:
            bool = TRUE;
            break;
    }
    return bool;
}
