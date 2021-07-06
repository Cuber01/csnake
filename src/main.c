#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "main.h"
#include "keyboard.h"
#include "apples.h"

const int MapHeight = 24;
const int MapWidth = 80;

const char* clean = "033[23";
const char* red = "\033[0;31m";
const char* green = "\033[0;32m";
const char* white = "\033[0;37m";
const char* reset = "\033[0m";

const char groundIcon = '.';
const char appleIcon = '@';
const char snakeIcon = '#';


int game = 1;
int frameDelay = 100;

point_t snakePos = {20,20};
int snake_vel_x = 1;
int snake_vel_y = 0;

int snakeElementNumber = 0;


const maxSnakes = 1900;

void handleInput(char input); 
void clearArray(char Map[MapWidth][MapHeight]);



void draw( char Map[MapWidth][MapHeight], point_t apples[MAX_APPLES] ) 
{
    char* currentColor = white;
    
    Map[snakePos.x][snakePos.y] = snakeIcon;


    for (int i = 0; i < MAX_APPLES; i++) 
    {   
        if ( apples[i].x != -1)
        {
            Map[apples[i].x][apples[i].y] = appleIcon; 
        }
    }

    
    for (int y = 0; y < MapHeight; y++) 
    {

        for (int x = 0; x < MapWidth; x++) 
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


void update(char Map[MapWidth][MapHeight], char input, point_t apples[MAX_APPLES])
{


    handleInput(input);

    snakePos.x += snake_vel_x;
    snakePos.y += snake_vel_y;

    for ( int i = 0; i < MAX_APPLES; i++)
    {
        if (apples[i].x == snakePos.x && apples[i].y == snakePos.y) 
        {
            appleDelete(apples[i]);
            appleAdd(calculateApplePos());
        }
    } 

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


void run(char Map[MapWidth][MapHeight], point_t apples[MAX_APPLES]){
    
    applesClear();
    appleAdd(calculateApplePos());

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

    
    point_t* snakeParts[maxSnakes];
    

    char Map[MapWidth][MapHeight];
    srand(time(NULL));
    run(Map, apples);

    return 0;

}




