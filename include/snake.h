#ifndef __SNAKE_H
#define __SNAKE_H

#include "main.h"

#define MAX_SNAKES 1900

extern point_t snakeParts[MAX_SNAKES];

extern int snake_vel_x;
extern int snake_vel_y;

typedef struct
{
    uint32_t head_index;
    uint32_t tail_index;
} snakeElementState;

struct
{
    snakeElementState state;
    point_t snakeParts[MAX_SNAKES];
} snake;

typedef enum
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
} direction_t;

void snakeInit(void);
void snakeClear(void);
void snakeMove(direction_t direction, bool grow);
void snakeDraw(void);

point_t SnakeGet(void);

#endif