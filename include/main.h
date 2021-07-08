#ifndef __MAIN_H
#define __MAIN_H


// settings
#define  MAPHEIGHT  (10)
#define  MAPWIDTH   (40)

// consts
#define ANSI_CLEAN  "\033[2J"
#define ANSI_RED    "\033[0;31m"
#define ANSI_GREEN  "\033[0;32m"
#define ANSI_WHITE  "\033[0;37m"
#define ANSI_RESET  "\033[0m"

 
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
