#include<curses.h>

int main() {

    initscr();

    int max_y, max_x, ratio = 1;
    getmaxyx(stdscr, max_y, max_x);

    int height = max_y / ratio; 
    int width = max_x / ratio;
    int start_y = (max_y - height) / 2;
    int start_x = (max_x - width) / 2;

    WINDOW *localWin = newwin(height, width, start_y, start_x);
    refresh();
    
    box(localWin, 0, 0);
    wprintw(localWin, "Hello World");
    wrefresh(localWin);

    getch();
    endwin();
}