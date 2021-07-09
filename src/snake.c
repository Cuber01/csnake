#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "main.h"
#include "snake.h"
#include "cyclic_buffer.h"
#include "map.h"

int snake_vel_x = 1;
int snake_vel_y = 0;

void snakeClear(void)
{
    snakeInit();
}

point_t SnakeGet(void)
{
    return cbGetHead();
}

void snakeDraw(void)
{
    point_t point;
    int rv;
    

    cbIterateReset();

    while (1)
    {
        rv = cbIterateGet(&point);
        if (rv)
            break;
        mapSet(point.x, point.y, '#');
    }

}

void snakeInit(void)
{
    cbClear();

    cbAdd((point_t){.x = 9, .y = 3});
    cbAdd((point_t){.x = 8, .y = 3});
    cbAdd((point_t){.x = 7, .y = 3});
    cbAdd((point_t){.x = 6, .y = 3});

}

void snakeMove(direction_t direction, bool grow)
{
    

    point_t current_postition = cbGetHead();

    switch (direction)
    {
    case LEFT:
        snake_vel_x = -1;
        snake_vel_y = 0;
        break;
    case RIGHT:
        snake_vel_x = 1;
        snake_vel_y = 0;
        break;
    case UP:
        snake_vel_y = -1;
        snake_vel_x = 0;
        break;
    case DOWN:
        snake_vel_y = 1;
        snake_vel_x = 0;
        break;
    case NONE:
        break;
    default:
        printf("/r/nError");
        exit(1);
    };

    current_postition.x += snake_vel_x;
    current_postition.y += snake_vel_y;

    cbAdd(current_postition);


    if (!grow)
    {
        cbDel();
    } 
        
    
    
}
