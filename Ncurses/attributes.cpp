#include<curses.h>


int main() {

    initscr();      // start screen
    
    int x, y;
    getmaxyx(stdscr, x, y);
    move(x/2, y/2);
    printw("Hello center");

    endwin();   // end screen

    return 0;
}