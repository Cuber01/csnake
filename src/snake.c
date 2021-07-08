#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "main.h"
#include "snake.h"
#include "cyclic_buffer.h"

int snake_vel_x = 1;
int snake_vel_y = 0;

#if 1

void snakeClear(void){
    snakeInit();
}

point_t SnakeGet(void){
    return cb_get_head();
}

void snakeDraw( char Map[MAPWIDTH][MAPHEIGHT] ){
    Map[10][10] = '!';
}

void snakeInit(void){
    cb_clear();
    cb_add( (point_t){ .x = 10, .y = 10 } );
}

void snakeMove( direction_t direction, bool grow ){
    
    //point_t current_postition = cb_get_head();

    point_t next_position;
    switch( direction ){
        case LEFT:
        //uzupelniec
        break;
        case RIGHT:
        //uzupelniec
        break;
        case UP:
        //uzupelniec
        break;
        case DOWN:
        //uzupelniec
        break;        
        default:
            printf("DUPA");        
    };

    cb_add( next_position );
    if( !grow ){
        cb_del();
    }

}




#else

// point_t snakeParts[MAX_SNAKES] = {{10,10}, {11,10}, {12,10}};
// point_t snakePos = {20,20};
point_t empty = {-1, -1};
int snake_vel_x = 1;
int snake_vel_y = 0;





void snakeClear( void )
{

    snake.state.head_index = 0;
    snake.state.tail_index = 0;
     
    for (int i = 0; i < MAX_SNAKES; i++) 
    {
        snake.snakeParts[i] = empty;
    }

}


void snakeAdd( point_t value ){

    snake.state.head_index++;
    snake.snakeParts[snake.state.head_index] = value;

}


void snakeDelete( void ){

    snake.state.tail_index++;
    snake.snakeParts[snake.state.tail_index] = empty;    

}
#endif
