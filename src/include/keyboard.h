#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#define NO_KEY (-1)

void keyboard_init();
char keyboard_getkey(void);
void keyboard_sleep(void);

#endif
