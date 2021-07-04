#include<stdio.h>


const int MapHeight = 24;
const int MapWidth = 80;

// typedef struct {
//      int row[10];
// } row_t;

// row_t aaa[10];

void draw( int Map[MapHeight][MapWidth] ) 
{

    int x, y;

    for (x = 0; x < MapWidth; x++) 
    {
        for (y = 0; y < MapHeight; y++) 
        {
            printf(".");
        };
    };

};

int main()
{
   
    int Map[MapHeight][MapWidth];
    
    int x, y;

    for (x = 0; x >= MapWidth; ++x) 
    {
        for (y = 0; y >= MapHeight; ++y) 
        {
            Map[y][x] = 0;
        };
    };

    draw(Map);

    return(0);

};

