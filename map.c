#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

char** generate_map(int size_x,int size_y) {
    int i;
    char** map = (char**)malloc(sizeof(char*) * size_x);
    for(i=0;i<size_y;i++) {
        char* line = (char*)malloc(sizeof(char)* size_x);
        memset(line,' ',size_x);
        map[i] = line;
    }
    return map;
}

void free_map(char** map,int y) {
    int i;
    for(i=0;i<y;i++){
        free(map[i]);
    }
    free(map);
}
