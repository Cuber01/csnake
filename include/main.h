#ifndef __MAIN_H
#define __MAIN_H


// settings
#define  MAPHEIGHT  (10)
#define  MAPWIDTH   (40)

// consts
#define clean  "\033[23"
#define red    "\033[0;31m"
#define green  "\033[0;32m"
#define white  "\033[0;37m"
#define reset  "\033[0m"

 
typedef struct {
    int x;
    int y;
} point_t;

extern point_t apples[];

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)


#endif
