#include <stdio.h>
#include <stdlib.h>
#include "map.h"
int main() {
    char** b = generateMap(10,10);
    fillMap(b,10,10);
    displayMap(b,10,10);
    freeMap(b,10);
    return 0;
}

