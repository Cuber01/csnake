#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <stdbool.h>

#include "main.h"
#include "keyboard.h"
#include "apples.h"
#include "snake.h"
#include "map.h"
#include "cyclic_buffer.h"


        // *adres -> value od adresu
        //  &value -> adres zmiennej value

int game = 1;
int frameDelay = 100;


#define APPLE_ICON '@';
#define SNAKE_ICON '#';

int applesEaten;
int framesSurvived;


void handleInput(char input, bool grow); 
void clearArray(char Map[MAP_WIDTH][MAP_HEIGHT]);


unsigned int time_counter=0;

void draw( char Map[MAP_WIDTH][MAP_HEIGHT], point_t apples[MAX_APPLES] ) 
{

    snakeDraw();

    for (int i = 0; i < MAX_APPLES; i++) 
    {   
        if ( apples[i].x != -1)
        {
            Map[apples[i].x][apples[i].y] = APPLE_ICON; 
        }
    }

   mapDraw();

}


void update(char input, point_t apples[MAX_APPLES])
{

    point_t snake_postition = cbGetHead();
    bool grow = false;

    for ( int i = 0; i < MAX_APPLES; i++)
    {
        if (apples[i].x == snake_postition.x && apples[i].y == snake_postition.y) 
        {
            applesEaten += 1;
            appleDelete(apples[i]);
            appleAdd(calculateApplePos());
            grow = true;
        } 
    } 

    

    handleInput(input, grow);

}



char getInput(void)
{
    char key = keyboard_getkey();
    
    if( key != NO_KEY ) {
            return key;        
    }

    return NO_KEY;

}

void handleInput(char input, bool grow) 
{
    
    if (input == 'a') 
    {
        snakeMove( LEFT, grow );

    } else if (input == 'd')
    {
        snakeMove( RIGHT, grow );

    } else if (input == 'w')
    {
        snakeMove( UP, grow );
    
    } else if (input == 's')
    {
        snakeMove( DOWN, grow );
    } else 
    {
        snakeMove( NONE, grow );
    }
    
}


void run(char Map[MAP_WIDTH][MAP_HEIGHT], point_t apples[MAX_APPLES]){
    
    applesClear();
    snakeInit();
    appleAdd(calculateApplePos());

    while (game) {
       
        mapClear();
        
        update(getInput(), apples);

        draw(Map, apples);

        framesSurvived++;
        napms(frameDelay);

    }

}

int main(void)
{
    initscr();
    keyboard_init();
    
  
    srand(time(NULL));
    run(Map, apples);

    return 0;

}




