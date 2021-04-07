#include <stdio.h>
#include <stdlib.h>

int *x;
int *y;

void updatePosition(int newX,int newY) {
    *x = newX;
    *y = newY;
}


int getX() {
    return *x;
}

int getY() {
    return *y;
}