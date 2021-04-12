#ifndef PLAYER_H
#define PLAYER_H 1
int get_x();
int get_y();
int get_direction();
int move_player(int,int);
void update_position(int,int);
void change_direction(char);
#endif
