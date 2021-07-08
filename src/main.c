#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "main.h"
#include "keyboard.h"
#include "apples.h"
#include "snake.h"
#include "map.h"

int game = 1;
int frameDelay = 100;

// const char groundIcon = '.';
const char appleIcon = '@';
const char snakeIcon = '#';

int applesEaten;
int framesSurvived;


void handleInput(char input); 
void clearArray(char Map[MAPWIDTH][MAPHEIGHT]);


unsigned int time_counter=0;

void draw( char Map[MAPWIDTH][MAPHEIGHT], point_t apples[MAX_APPLES] ) 
{
    //char* currentColor = white;
    
    //Map[snakePos.x][snakePos.y] = snakeIcon;


    //snakeDraw( Map );

    int x = 3;
    int y = 12;
    Map[y][x] = 'X';

    for (int i = 0; i < MAX_APPLES; i++) 
    {   
        if ( apples[i].x != -1)
        {
            Map[apples[i].x][apples[i].y] = appleIcon; 
        }
    }

    for (int i = 0; i < MAX_SNAKES; i++) 
    {   
        if ( snake.snakeParts[i].x != -1)
        {
            Map[snake.snakeParts[i].x][snake.snakeParts[i].y] = snakeIcon; 
        }
    }

   // printf("\r\ntime:%d\r\n", time_counter++);
   // printf("\r\ny\\x:0123456789012345678901234567890123456789\r\n");

   // mapDraw();

    // for (int y = 0; y < MAPHEIGHT; y++) 
    // {
    //     printf("%02d :",  y);
    //     for (int x = 0; x < MAPWIDTH; x++) 
    //     {


    //         //if (Map[x][y] == appleIcon) { //TODO COLOR
    //         //    currentColor = red;
    //         //} else if (Map[x][y] == snakeIcon) {
    //         //    currentColor = green;
    //         //} 

    //         //printf(currentColor);
    //         printf("%c", Map[x][y]);
    //         //printf(reset);
            
    //     };
    //     printf("\r\n");
    // };


}

//void update(char Map[MAPWIDTH][MAPHEIGHT], char input, point_t apples[MAX_APPLES])
void update(char input, point_t apples[MAX_APPLES])
{

    handleInput(input);

    // snakePos.x += snake_vel_x;
    // snakePos.y += snake_vel_y;

    point_t snake_head = SnakeGet();

    for ( int i = 0; i < MAX_APPLES; i++)
    {
        if (apples[i].x == snake_head.x && apples[i].y == snake_head.y) 
        {
            applesEaten += 1;
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

    return NO_KEY;

}


// void clearArray(char Map[MAPWIDTH][MAPHEIGHT])
// {
    
//     for ( int y = 0; y < MAPHEIGHT; y++) 
//     {
//         for (int x = 0; x < MAPWIDTH; x++ ) 
//         {
//             Map[x][y] = groundIcon;
//         };
//     };   

// }

void handleInput(char input) 
{
    if (input == 'a') 
    {
        snake_vel_x = -1;
        snake_vel_y = 0;
        snakeMove( LEFT, 0 );

    } else if (input == 'd')
    {

        snake_vel_x = 1;
        snake_vel_y = 0;
        snakeMove( RIGHT, 0 );

    } else if (input == 'w')
    {

        snake_vel_y = -1;
        snake_vel_x = 0;
        snakeMove( UP, 0 );
    
    } else if (input == 's')
    {

        snake_vel_y = 1;
        snake_vel_x = 0;
        snakeMove( DOWN, 0 );
    } 
    
}


void run(char Map[MAPWIDTH][MAPHEIGHT], point_t apples[MAX_APPLES]){
    
    applesClear();
    snakeClear();
    appleAdd(calculateApplePos());

    while (game) {
       
//        clearArray(Map);
        
        //update(Map, getInput(), apples);
        update(getInput(), apples);

        draw(Map, apples);

        framesSurvived += 1;
        napms(frameDelay);

    }

}

int main(void)
{
    mapClear();
    mapSet(0,0, 'A');
    mapSet(MAPWIDTH-1, 0, 'B');
    mapSet(0, MAPHEIGHT-1, 'C');
    mapSet(MAPWIDTH-1,MAPHEIGHT-1, 'D');

    
    printf("%c",mapGet(MAPWIDTH-1, 0));
    printf("%c",mapGet(0, MAPHEIGHT-1));

    mapDraw();
    // initscr();
    // keyboard_init();
  
    // srand(time(NULL));
    // run(Map, apples);

    return 0;

}




