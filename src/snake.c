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

bool snakeCollision( point_t value, bool head_omit);

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

void snakeMove(direction_t direction, bool grow )
{
    static direction_t current_direction = NONE;

    point_t current_postition = cbGetHead();
    point_t next_postition = current_postition;

    if( direction == NONE ){
        direction = current_direction;
    }

    switch (direction)
    {
    case LEFT:
        next_postition.x -= 1;        
        // snake_vel_x = -1;
        // snake_vel_y = 0;
        break;
    case RIGHT:
        next_postition.x += 1;
        // snake_vel_x = 1;
        // snake_vel_y = 0;
        break;
    case UP:
        next_postition.y -= 1;
        // snake_vel_y = -1;
        // snake_vel_x = 0;
        break;
    case DOWN:
        next_postition.y += 1;    
        // snake_vel_y = 1;
        // snake_vel_x = 0;
        break;
    case NONE:    
        break;
    default:
        printf("/r/nError");
        exit(1);
    };

    if( current_direction != NONE ){
        bool col = snakeCollision( next_postition, false );

        if (col)
        {
              exit(0);
        }    
    }

    cbAdd(next_postition);


    if (!grow)
    {
        cbDel();
    } 
        
    current_direction = direction;
    
}

bool snakeCollision( point_t value, bool head_omit )
{
    point_t current_value;
    bool stop;       
    bool head_flag = head_omit;

    cbIterateReset();

    while (1)
    {
        stop = cbIterateGet( &current_value );
        if( stop ){
            return false;
        }
        if( ! head_flag ){
            if( current_value.x == value.x && current_value.y == value.y) 
            {
                return true;
            } 
            head_flag = false;
        }

    }

    return false;
}
