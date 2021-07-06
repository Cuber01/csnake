#ifndef __APPLES_H
#define __APPLES_H

extern int appleNumber;
extern const int maxApples;

void PlaceApple(point_t applePos, point_t apples[maxApples]);
point_t calculateApplePos(void);

#endif