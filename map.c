#include <stdio.h>
#include <stdlib.h>

void displayMap(char** map,int x,int y) {
    int i;
    int j;
    for(i=0;i<y+2;i++) {
        for(j=0;j<x+2;j++) {
            printf("%c",map[j][i]);
        }
        printf("\n");
    }
}

char** generateMap(int x,int y) {
    int sizeX = x+2;
    int sizeY = y+2;
    int i;
    char** map = (char**)malloc(sizeof(char*) * sizeX);
    for(i=0;i<sizeY;i++) {
        map[i] = (char*)malloc(sizeof(char)* sizeY);
    }

    return map;
}

void fillMap(char** map,int x,int y) {
    int i;
    int j;
    int ii;
    int jj;
    for(i=0;i<x+2;i++) {
        map[0][i] = '*';
    }
    for(ii=0;ii<y+2;ii++) {
        for(jj=1;jj<x+2;jj++) {
            if(jj == 0 || jj == x+1) {
                map[jj][ii] = '*';
            }
            else {
                map[jj][ii] = ' ';
            }
        }
    }
    for(j=0;j<x+2;j++) {
        map[y+1][j] = '*';  
    }
}

void freeMap(char** map,int x) {
    int i=0;
    for(;i<x+2;i++){
        free(map[i]);
    }
    free(map);
}