#include<curses.h>


int main() {
    
    initscr();

    move(5, 5);
    printw("Hello curses");
    refresh();

    mvprintw(5, 20, "Hello user");
    refresh();

    getch();
    endwin();

    return 0;
}