#include<curses.h>
#include<thread>
#include<chrono>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<typeinfo>



inline void sleepFor(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

inline void moveLeft(int& y, int& x) {
    x--;
}

inline void moveRight(int& y, int& x) {
    x++;
}

inline void moveUp(int& y, int& x) {
    y--;
}

inline void moveDown(int& y, int& x) {
    y++;
}

void renderSnake(int& y, int& x) {
    mvaddstr(y, x, "x");
    refresh();
    mvaddstr(y, x, " ");
    // move(0, x + 1);
}


int main() {

    int x, y;
    int keyPressed;

    void (*lastMove)(int&, int&) = &moveRight;

    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    // wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');

    getyx(stdscr, y, x);
    // getmaxyx(stdscr, y, x);

    while ( (keyPressed = getch()) != 27) {

        switch (keyPressed) {
            case KEY_UP:
                moveUp(y, x);
                lastMove = moveUp;
                refresh();
                break;

            case KEY_DOWN:
                moveDown(y, x);
                lastMove = moveDown;
                refresh();
                break;

            case KEY_LEFT:
                moveLeft(y, x);
                lastMove = moveLeft;
                refresh();
                break;

            case KEY_RIGHT:
                moveRight(y, x);
                lastMove = moveRight;
                refresh();
                break;
            
            default:
                lastMove(y, x);
                break;
        }

        
        renderSnake(y, x);
        
        // mvaddstr(0, pos + 1, "x");

        sleepFor(50);
    }

    getch();
    endwin();

    return 0;
}