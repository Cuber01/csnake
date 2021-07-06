#ifndef __MAIN_H
#define __MAIN_H

typedef struct {
    int x;
    int y;
} point_t;

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)


#endif
