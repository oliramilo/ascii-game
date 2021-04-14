#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viewer.h"
#include "controller.h"
#include "newSleep.h"
#include "boolean.h"
#include "direction.h"

const char* RED = "\033[0;31m";
const char* BLUE = "\033[0;34m";
const char* DEFAULT = "\033[0m";

static int STRING_SIZE = 20;

void display_player_won() {
    system("clear");
    printf("Congratulations, You Won!!!\n");
}

/**pointer integers x and y represent the player's position on the map**/
int shooting_animation(char** map,int* dimensions,int* x,int* y,char direction) {
    int i,num_frames,old_x,old_y,hit_enemy,color;
    int* laser_pos_x;
    int* laser_pos_y;
    int* delta_x = 0;
    int* delta_y = 0;
    char* laser_direction = (char*)malloc(sizeof(char));
    *laser_direction = '-';
    delta_x_y(delta_x,delta_y,direction,laser_direction);
    laser_pos_x = *x + delta_x;
    laser_pos_y = *y + delta_y;
    hit_enemy = FALSE;
    color = 1;
    i = 0;
    num_frames = get_num_frames(map,direction,*laser_pos_x,*laser_pos_y);
    while(check_bounds(*laser_pos_x,*laser_pos_y,dimensions,map) && i < num_frames && hit_enemy == FALSE) {
        system("clear");
        if(map[*laser_pos_y][*laser_pos_y] == ' ') {
            map[*laser_pos_y][*laser_pos_x] = *laser_direction;
            old_x = *laser_pos_x;
            old_y = *laser_pos_y;
            *laser_pos_y+=*delta_x;
            *laser_pos_y+=*delta_y;
        }
        else {
           hit_enemy = TRUE;
           map[*laser_pos_y][*laser_pos_x] = 'X';
        }
        display_map(map,dimensions[1],color);
        color = color == 1 ? 0 : 1;
        map[old_y][old_x] = ' ';
        newSleep(0.5);
    }
    free(laser_direction);
    return hit_enemy;
}

int get_num_frames(char** map, char direction,int x,int y) {
    int i = 0;
    int inc_x = 0;
    int inc_y = 0;
    if(direction == SOUTH || direction == NORTH) {
        inc_y = y+1;
        inc_x = x;
    }
    else {
        inc_y = y;
        inc_x = x+1;
    }
    while(map[inc_y][inc_x] != EOF) {
        i++;
    }
    return i;
}

void display_commands() {
    printf("w to go/face up\n");
    printf("s to go/face down\n");
    printf("a to go/face left\n");
    printf("d to go/face right\n");
    printf("f to shoot laser\n");
}

void display_map(char** map,int size_y,int mode) {
    int i;
    char* wall = (char*)malloc(sizeof(char) * (size_y + 2));

    memset(wall,'*',size_y + 2);
    printf("%s\n",wall);
    for(i=0;i<size_y;i++) {
        printf("*");
        print_colors(map[i], mode);
        printf("*");
        printf("\n");
    }
    printf("%s\n",wall);
    free(wall);
}

void print_colors(char* line,int mode) {
    int i;
    char* color = (char*)malloc(sizeof(char) * STRING_SIZE);
    switch_colors(color, 0);
    for(i=0;i<sizeof(line);i++) {
        if(has_bullet(line[i])) {
            switch_colors(color,mode);
        }
        printf("%s", color);
        printf("%c",line[i]);
        switch_colors(color,0);
        printf("%s", color);
    }
    free(color);
}

int has_bullet(char pos) {
    return pos == '-' || pos == '|' ? TRUE : FALSE;
}

void switch_colors(char* color,int mode) {
    switch(mode) {
        case 1:
            strcpy(color,RED);
        case 2:
            strcpy(color,BLUE);
        case 0:
            strcpy(color,DEFAULT);
    }
}

void delta_x_y(int* delta_x, int* delta_y, char direction,char* laser_direction){
    if(direction == SHOOT) {
        *delta_x = 0;
        *delta_y = 0;
        *laser_direction = ' ';
    }
    else if(direction == NORTH) {
        *delta_x = 0;
        *delta_y = -1;
        *laser_direction = '|';
    }
    else if(direction == SOUTH) {
        *delta_x = 0;
        *delta_y = 1;
        *laser_direction = '|';
    }
    else if(direction == WEST) {
        *delta_x = -1;
        *delta_y = 0;
        *laser_direction = '-';
    }
    else if(direction == EAST) {
        *delta_x = 1;
        *delta_y = 0;
        *laser_direction = '-';
    }
}
