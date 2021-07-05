#include <stdio.h>
#include <curses.h>
#include "keyboard.h"

void keyboard_init(){

    initscr(); 

    cbreak();
    noecho();
    
    scrollok(stdscr, TRUE);    
    nodelay(stdscr, TRUE);

}

char keyboard_getkey(void){
        return getch();
}


