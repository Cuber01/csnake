#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "map.h"

#define GROUND_ICON '.'

static void checkParameters(uint8_t x, uint8_t y, char *file, uint32_t line);

char Map[MAPWIDTH][MAPHEIGHT];

void mapClear(void)
{

    for (int y = 0; y < MAPHEIGHT; y++)
    {
        for (int x = 0; x < MAPWIDTH; x++)
        {
            Map[x][y] = GROUND_ICON;
        };
    };
}

static unsigned int time_counter = 0;

void mapDraw(void)
{

    printf(ANSI_CLEAN);

    printf("\r\ntime:%d\r\n", time_counter++);
    printf("\r\ny\\x:0123456789012345678901234567890123456789\r\n");
    for (int y = 0; y < MAPHEIGHT; y++)
    {
        printf("%02d :", y);
        for (int x = 0; x < MAPWIDTH; x++)
        {

            //if (Map[x][y] == appleIcon) { //TODO COLOR
            //    currentColor = red;
            //} else if (Map[x][y] == snakeIcon) {
            //    currentColor = green;
            //}

            //printf(currentColor);
            printf("%c", Map[x][y]);
            //printf(reset);
        };
        printf("\r\n");
    };
}

void mapSet(uint8_t x, uint8_t y, char value)
{
    checkParameters(x, y, __FILE__, __LINE__);
    Map[x][y] = value;
}

char mapGet(uint8_t x, uint8_t y)
{
    checkParameters(x, y, __FILE__, __LINE__);
    return (Map[x][y]);
}

// private
static void checkParameters(uint8_t x, uint8_t y, char *file, uint32_t line)
{

    if (x > MAPWIDTH - 1 || y > MAPHEIGHT - 1)
    {
        printf("ERROR %s:%d", file, line);
        exit(1);
    }
}
