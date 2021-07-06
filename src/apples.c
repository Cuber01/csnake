#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int appleNumber = -1;
const int maxApples = 10;

void PlaceApple(point_t applePos, point_t apples[maxApples])
{
    if (appleNumber <= maxApples) {

        appleNumber += 1;
        apples[appleNumber] = applePos; 
        

    }  
}

point_t calculateApplePos(void)
{
    int apple_x = rand() % MapWidth + 0;
    int apple_y = rand() % MapHeight + 0;

    return (point_t){ .x = apple_x, .y = apple_y };
}