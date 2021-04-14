#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "viewer.h"
#include "boolean.h"
#include "controller.h"
#include "player.h"
#include "direction.h"
#include "newSleep.h"

void game_func(char**,int*,int*,char*,int*);
int process_action(char**,int*,int*,int*,char*);

int main(int argc, char** argv) {
    char* player_direction;
    int* dimensions;
    char** map;
    int x = 5;
    int y = 5;
    int* player_x = 0;
    int* player_y = 0;
    int p_x,p_y;
    player_direction = (char*)malloc(sizeof(char));
    dimensions = (int*)malloc(sizeof(int) * 2);
    player_x = (int*)malloc(sizeof(int));
    player_y = (int*)malloc(sizeof(int));
    dimensions[0] = x;
    dimensions[1] = y;
    player_x = &p_y;
    player_y = &p_x;
    *player_x = 0;
    *player_y = 0;
    *player_direction = '>';

    map = generate_map(x,y);
    map[*player_y][*player_x] = *player_direction;
    game_func(map,player_x,player_y,player_direction,dimensions);
    free_map(map,y);
    free(dimensions);
    free(player_x);
    free(player_y);
    free(player_direction);
    return 0;
}


void game_func(char** map,int* player_x,int* player_y,char* direction,int* dimensions) {
    int game_won = FALSE;
    int game_loop = TRUE;
    printf("Dimensions of the map is [%d][%d]\n", dimensions[0],dimensions[1]);
    display_map(map,dimensions[1],0);
    while(game_loop) {
        display_commands();
        game_won = process_action(map,dimensions,player_x,player_y,direction);
        display_map(map,dimensions[1],0);
        if(game_won) {
            game_loop = FALSE;
        }
    }
}

int process_action(char** map,int* dimensions,int* x,int* y, char* direction) {
    int win_condition = FALSE;
    char command = get_player_input();
    command = (command >= 97 && command <= 122) ? command - 32 : command;
    newSleep(0.5);
    if( command == WEST || command == EAST || command == NORTH
        || command == SOUTH) {
            move_player(map,x,y,direction,dimensions,command);
    }
    else if(command == SHOOT) {
        printf("Direction is %c", *direction);
       win_condition = shooting_animation(map,dimensions,x,y,*direction);
    }
    else {
        printf("Invalid command, try again.\n");
    }
    return win_condition;
}
