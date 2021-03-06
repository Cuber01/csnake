#ifndef __MAP_H
#define __MAP_H

#include "main.h"
#include <stdint.h>

#define APPLE_ICON '@'

extern char Map[MAP_WIDTH][MAP_HEIGHT];

void mapClear(void);
void mapDraw(void);
void mapSet(uint8_t x, uint8_t y, char value);
char mapGet(uint8_t x, uint8_t y);

#endif