#include<curses.h>


int main() {

    initscr();      // start screen
    noecho();       // suppress typed input
    int c;

    printw("Write something (Press ESC to escape): ");
    while ( (c = getch()) != 27 ) {

        move(10, 0);
        printw("Your key number is: %d, and the char is: %c", c, c);
        move(0, 0);
        printw("Write something (Press ESC to escape)");
        refresh();
    }

    endwin();   // end screen

    return 0;
}