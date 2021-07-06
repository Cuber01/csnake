#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "main.h"
#include "keyboard.h"
#include "utils.h"

const int MapHeight = 24;
const int MapWidth = 80;
const char* clean = "033[23";

const char groundIcon = '.';
const char appleIcon = '@';
const char snakeIcon = '#';

int game = 1;
int frameDelay = 100;

point_t snakePos = {20,20};
int snake_vel_x = 1;
int snake_vel_y = 0;

int appleNumber = 0;
int snakeElementNumber = 0;

const maxApples = 10;
const maxSnakes = 1900;



void handleInput(char input); 
void clearArray(char Map[MapWidth][MapHeight]);


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


void draw( char Map[MapWidth][MapHeight], point_t apples[maxApples] ) 
{
    
    Map[snakePos.x][snakePos.y] = snakeIcon;


    for (int i = 0; i < appleNumber; i++) 
    {   
        Map[apples[i].x][apples[i].y] = appleIcon;   
    }

    
    for (int y = 0; y < MapHeight; y++) 
    {
        for (int x = 0; x < MapWidth; x++) 
        {
            printf("%c", Map[x][y]);
        };
        printf("\r\n");
    };

}


void update(char Map[MapWidth][MapHeight], char input, point_t apples[maxApples])
{

    PlaceApple(calculateApplePos(), apples);

    handleInput(input);

    snakePos.x += snake_vel_x;
    snakePos.y += snake_vel_y;


}


char getInput(void)
{
    char key = keyboard_getkey();
    
    if( key != NO_KEY ) {
            return key;        
    }

}


void clearArray(char Map[MapWidth][MapHeight])
{
    
    for ( int y = 0; y < MapHeight; y++) 
    {
        for (int x = 0; x < MapWidth; x++ ) 
        {
            Map[x][y] = groundIcon;
        };
    };   

}

void handleInput(char input) 
{
    if (input == 'a') 
    {
        snake_vel_x = -1;
        snake_vel_y = 0;

    } else if (input == 'd')
    {

          snake_vel_x = 1;
          snake_vel_y = 0;

    } else if (input == 'w')
    {

          snake_vel_y = -1;
          snake_vel_x = 0;

    
    } else if (input == 's')
    {

            snake_vel_y = 1;
            snake_vel_x = 0;

    } 

}


void run(char Map[MapWidth][MapHeight], point_t apples[maxApples]){

    while (game) {
       
        clearArray(Map);
        //initscr();
        
        update(Map, getInput(), apples);
        draw(Map, apples);

        napms(frameDelay);

    }

}

int main(void)
{

    initscr();
    keyboard_init();

    point_t apples[maxApples];
    point_t* snakeParts[maxSnakes];
    

    char Map[MapWidth][MapHeight];
    srand(time(NULL));
    run(Map, apples);

    return 0;

}




