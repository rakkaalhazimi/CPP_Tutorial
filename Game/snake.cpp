#include<curses.h>
#include<thread>
#include<chrono>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<unistd.h>



void sleepFor(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}


int main() {

    int x, y;
    int keyPressed;

    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    // wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');

    move(1, 1);
    getyx(stdscr, y, x);
    getmaxyx(stdscr, y, x);

    int pos = 0;

    while ( (keyPressed = getch()) != 27) {

        // move(y, x);
        // wclrtoeol(stdscr);
        if (pos > x) {
            pos = 0;
            // mvdelch(0, pos);
            // refresh();
            // pos--;
            // sleepFor(500);
            // mvdelch(0, pos);
            // refresh();
            // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            // mvdelch(0, pos--);
            // refresh();
            // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            // break;
        }

        mvaddstr(0, pos, "xxx");
        refresh();
        mvaddstr(0, pos, " ");
        move(0, pos + 1);
        // mvaddstr(0, pos + 1, "x");
        pos++;

        switch (keyPressed) {
            case KEY_UP:
                printw("Pressed up");
                refresh();
                break;

            case KEY_DOWN:
                printw("Pressed down");
                refresh();
                break;

            case KEY_LEFT:
                printw("Pressed left");
                refresh();
                break;

            case KEY_RIGHT:
                printw("Pressed right");
                refresh();
                break;
            
            default:
                break;
        }

        sleepFor(90);
    }

    getch();
    endwin();

    return 0;
}