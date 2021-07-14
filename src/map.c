#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "snake.h"
#include "main.h"
#include "map.h"

#define GROUND_ICON ' '

static void checkParameters(uint8_t x, uint8_t y);

char Map[MAP_WIDTH][MAP_HEIGHT];

void mapClear(void)
{

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            Map[x][y] = GROUND_ICON;
        };
    };
}



void mapDraw(void)
{

    char* currentColor = ANSI_WHITE;
    printf(ANSI_CLEAN);

    printf("\r\ntime:%d\r\n", framesSurvived);
    printf("\r\napples:%d\r\n", applesEaten);
    printf("\r\ny\\x:0123456789012345678901234567890123456789\r\n");
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        printf("%02d :", y);
        for (int x = 0; x < MAP_WIDTH; x++)
        {

            if (Map[x][y] == APPLE_ICON) { 
               currentColor = ANSI_RED;
            } else if (Map[x][y] == SNAKE_ICON) {
               currentColor = ANSI_GREEN;
            }

            printf("%s", currentColor);
            printf("%c", Map[x][y]);
            printf(ANSI_WHITE);
        };
        printf("\r\n");
    };
}

void mapSet(uint8_t x, uint8_t y, char value)
{
    checkParameters(x, y);
    Map[x][y] = value;
}

char mapGet(uint8_t x, uint8_t y)
{
    checkParameters(x, y);
    return (Map[x][y]);
}

// private
static void checkParameters(uint8_t x, uint8_t y)
{

    if (x > MAP_WIDTH - 1 || y > MAP_HEIGHT - 1)
    {
        printf("Game over, bumped into wall");
        exit(0);
    }
}
