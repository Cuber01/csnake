#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int appleNumber = 0;
const int maxApples = 10;

void PlaceApple(point_t applePos, point_t apples[maxApples])
{
    if (appleNumber <= maxApples) {

        apples[appleNumber] = applePos; 
        appleNumber += 1;

    }  
}

point_t calculateApplePos(void)
{
    int apple_x = rand() % MapWidth + 0;
    int apple_y = rand() % MapHeight + 0;

    return (point_t){ .x = apple_x, .y = apple_y };
}