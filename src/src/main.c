#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "main.h"
#include "keyboard.h"

const int MapHeight = 24;
const int MapWidth = 80;
const char* clean = "033[23";

const char groundIcon = '.';
const char appleIcon = '@';
const char snakeIcon = '#';

int game = 1;

int snake_x = 20;
int snake_y = 20;
int snake_vel_x = 1;
int snake_vel_y = 0;

void draw( char Map[MapWidth][MapHeight] ) 
{
    
    for (int y = 0; y < MapHeight; y++) 
    {
        for (int x = 0; x < MapWidth; x++) 
        {
            printf("%c", Map[x][y]);
        };
        printf("\r\n");
    };

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

void update(char Map[MapWidth][MapHeight], point_t applePos, char input)
{

    for ( int y = 0; y < MapHeight; y++) 
    {
        for (int x = 0; x < MapWidth; x++ ) 
        {
            if (x == applePos.x && y == applePos.y)
            {
                Map[x][y] = appleIcon;
            }
        };
    };  

    Map[snake_x][snake_y] = snakeIcon;

    if (input == 'a') {
         snake_x += 1;
    }


}

char getInput(void)
{
    char key = keyboard_getkey();
    
    if( key != NO_KEY ){
            return key;        
    }

}

point_t calculateApplePos(void)
{
    int apple_x = rand() % MapWidth + 0;
    int apple_y = rand() % MapHeight + 0;

    return (point_t){ .x = apple_x, .y = apple_y};
}

void run(char Map[MapWidth][MapHeight]){

    while (game) {
       
        clearArray(Map);
        
        update(Map, calculateApplePos(), getInput());
        draw(Map);

        napms(100);

    }

}

int main(void)
{

    initscr();
    keyboard_init();
    

    char Map[MapWidth][MapHeight];
    srand(time(NULL));
    run(Map);

    return 0;

}




