#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
