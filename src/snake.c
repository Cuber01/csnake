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

#if 1

void snakeClear(void){
    snakeInit();
}

point_t SnakeGet(void){
    return cb_get_head();
}

void snakeDraw(void){
    point_t point;
    int rv;

    cb_iterate_reset();
    while(1){
          rv = cb_iterate_get( &point );
          if( rv ) break;
          mapSet( point.x, point.y, '#' );
    }
    
}

void snakeInit(void){
    cb_clear();

    cb_add( (point_t){ .x = 9, .y = 3 } );
    cb_add( (point_t){ .x = 8, .y = 3 } );    
    cb_add( (point_t){ .x = 7, .y = 3 } );
    cb_add( (point_t){ .x = 6, .y = 3 } );    
    cb_add( (point_t){ .x = 5, .y = 3 } );        
    cb_add( (point_t){ .x = 5, .y = 4 } );
    cb_add( (point_t){ .x = 5, .y = 5 } );    
    cb_add( (point_t){ .x = 5, .y = 6 } );        
    cb_add( (point_t){ .x = 5, .y = 6 } );
    cb_add( (point_t){ .x = 4, .y = 6 } );    
    cb_add( (point_t){ .x = 3, .y = 6 } );        
    

}

void snakeMove( direction_t direction, bool grow ){
    
    point_t current_postition = cb_get_head();

    //point_t next_position;

    switch( direction ){
        case LEFT:
            current_postition.x -= 1;
        break;
        case RIGHT:
            current_postition.x += 1;
        break;
        case UP:
            current_postition.y -= 1;
        break;
        case DOWN:
            current_postition.y += 1;
        break;        
        default:
            printf("/r/nError");
            exit(1);
    };

    cb_add( current_postition );
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
