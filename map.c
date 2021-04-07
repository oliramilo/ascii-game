#include <stdio.h>
#include <stdlib.h>

void displayMap(char** map,int x,int y) {
    int i = 0;
    int j = 0;
    for(;i<y+2;i++) {
        for(;j<x+2;j++) {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

char** generateMap(int x,int y) {
    int sizeX = x+2;
    int sizeY = y+2;
    int i = 0;
    char** map = (char**)malloc(sizeof(char*) * sizeY);
    for(;i<sizeX;i++) {
        map[i] = (char*)malloc(sizeof(char)* sizeX);
    }

    return map;
}

void fillMap(char** map,int x,int y) {
    int i = 0;
    int j = 0;
    int ii = 1;
    int jj = 0;
    for(;i<y+2;i++) {
        map[0][i] = '*';
    }
    for(;ii<y+2;ii++) {
        for(;jj<x+2;jj++) {
            if(ii == 0 || ii == x+1) {
                map[ii][jj] = '*';
            }
            else {
                map[ii][jj] = ' ';
            }
        }
    }
    for(;j<x+2;j++) {
        map[y+2][j] = '*';  
    }
}

void freeMap(char** map,int x) {
    int i=0;
    for(;i<x+2;i++){
        free(map[i]);
    }
    free(*map);
}