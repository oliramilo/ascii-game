#include <stdio.h>
#include <stdlib.h>
#include "map.h"
int main() {
    int x = 4;
    int y = 5;
    char** b = generateMap(x,y);
    fillMap(b,x,y);
    displayMap(b,x,y);
    freeMap(b,10);
    return 0;
}