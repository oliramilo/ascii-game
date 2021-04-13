#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "viewer.h"
#include "boolean.h"
#include "controller.h"
#include "player.h"

int size_x,size_y;
int* player_x;
int* player_y;
char* player_direction;
char** map;

int game_func();
void process_action(char);
int main(int argc, char** argv) {

    int x = 5;
    int y = 5;
    create_player(player_x,player_y);
    char** b = generate_map(x,y);
    display_map(b,x,y);
    free_map(b,5);
    return 0;
}


int game_func() {
    char command;
    int player_win = FALSE;
    int game_loop = TRUE;
    while(game_loop) {
        command = get_player_input();
        process_action();
    }
    return player_win;
}

void process_action(char command) {
    switch(command) {
        case WEST:
        case EAST:
        case NORTH:
        case SOUTH:
            move_player(map,player_x,player_y,player_direction,command);
            break;
        case SHOOT:
            shooting_animation(map,size_x,size_y);
            break;
    }
}
