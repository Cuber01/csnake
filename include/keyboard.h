#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#define NO_KEY (-1)

// how to share a variable

// hello.c :
//      int hello = 1;

// hello.h :
//      extern int hello;

void keyboard_init();
char keyboard_getkey(void);
void keyboard_sleep(void);

#endif
