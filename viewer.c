#include <stdio.h>
#include "sleep.h"

void shooting_animation(char** map, int x,int y) {

}

void display_map(char** map,int x,int y) {
    int i;
    char* wall = (char*)malloc(sizeof(char) * x+2);
    memset(wall,'*',x+2);
    printf("%s\n",wall);
    for(i=0;i<y;i++) {
        printf("*%s*\n",map[i]);
    }
    printf("%s\n",wall);
    free(wall);
}
