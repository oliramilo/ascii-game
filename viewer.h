#ifndef VIEWER_H
#define VIEWER_H
int shooting_animation(char**,int*,int*,int*,char);
int has_bullet(char);
int get_num_frames(char**,char,int,int);
void display_map(char**,int,int);
void display_player_won();
void display_commands();
void delta_x_y(int*,int*,char,char*);
void print_colors(char*,int);
void switch_colors(char*,int);

#endif
