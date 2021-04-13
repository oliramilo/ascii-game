#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

int* player_x;
int* player_y;
char* player_direction;
char** map;

int main(int argc, char** argv) {
    int x = 4;
    int y = 5;
    char** b = generate_map(x,y);
    display_map(b,x,y);
    free_map(b,5);
    return 0;
}
