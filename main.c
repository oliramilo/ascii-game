#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
int main() {
    int x = 4;
    int y = 5;
    char** b = generate_map(x,y);
    display_map(b,x,y);
    free_map(b,5);
    return 0;
}
