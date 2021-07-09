#ifndef __MAIN_H
#define __MAIN_H

// settings
#define MAP_HEIGHT (10)
#define MAP_WIDTH (40)

// consts
#define ANSI_CLEAN "\033[2J"
#define ANSI_RED "\033[0;31m"
#define ANSI_GREEN "\033[0;32m"
#define ANSI_WHITE "\033[0;37m"
#define ANSI_RESET "\033[0m"

extern int applesEaten;
extern int framesSurvived;

typedef struct
{
    int x;
    int y;
} point_t;

extern point_t apples[];

#endif
