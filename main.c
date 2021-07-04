#include<stdio.h>
#include <stdlib.h>

const int MapHeight = 24;
const int MapWidth = 80;
const char* clean = "033[23";

const char groundIcon = '.';
const char appleIcon = '@';

typedef struct {
    int x;
    int y;
} point_t;

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

void clear(char Map[MapWidth][MapHeight])
{
    
    for ( int y = 0; y < MapHeight; y++) 
    {
        for (int x = 0; x < MapWidth; x++ ) 
        {
            Map[x][y] = groundIcon;
        };
    };   

}

void modifyMap(char Map[MapWidth][MapHeight], point_t applePos)
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


}



point_t calculateApplePos()
{
    int apple_x = rand() % MapWidth + 0;
    int apple_y = rand() % MapHeight + 0;

    return (point_t){ .x = apple_x, .y = apple_y};
}

int main()
{
   
    char Map[MapWidth][MapHeight];
    srand(time(NULL));
 
    clear(Map);

    modifyMap(Map, calculateApplePos());

    draw(Map);

    return(0);

}

