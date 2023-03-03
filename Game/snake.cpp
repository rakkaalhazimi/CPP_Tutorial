#include<curses.h>
#include<thread>
#include<chrono>
#include<string>
#include<queue>
#include<iostream>
#include<algorithm>
#include<typeinfo>


struct BodyPart {
    int y;
    int x;
};


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

void renderSnake(int& y, int& x, int& length, std::queue<BodyPart>& body) {

    BodyPart limb = {.y=y, .x=x};
    body.push(limb);
    mvaddstr(limb.y, limb.x, "x");
    refresh();

    if (body.size() >= length) {
        BodyPart tail = body.front();
        mvaddstr(tail.y, tail.x, " ");
        body.pop();
    }
}


int main() {

    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    // wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');

    int x, y, snakeLength = 10;
    int keyPressed;
    std::queue<BodyPart> snakeBody;
    
    getmaxyx(stdscr, y, x);
    y /= 2;
    x /= 2;

    void (*lastMove)(int&, int&) = &moveRight;

    while ( (keyPressed = getch()) != 27) {

        mvprintw(1, 1, "x: %d, y: %d", x, y);

        switch (keyPressed) {
            case KEY_UP:
                if (lastMove == moveDown) {
                    lastMove(y, x);
                    break;
                }
                moveUp(y, x);
                lastMove = moveUp;
                refresh();
                break;

            case KEY_DOWN:
                if (lastMove == moveUp) {
                    lastMove(y, x);
                    break;
                }
                moveDown(y, x);
                lastMove = moveDown;
                break;

            case KEY_LEFT:
                if (lastMove == moveRight) {
                    lastMove(y, x);
                    break;
                }
                moveLeft(y, x);
                lastMove = moveLeft;
                break;

            case KEY_RIGHT:
                if (lastMove == moveLeft) {
                    lastMove(y, x);
                    break;
                }
                moveRight(y, x);
                lastMove = moveRight;
                break;
            
            default:
                lastMove(y, x);
                break;
        }

        
        renderSnake(y, x, snakeLength, snakeBody);
        
        // mvaddstr(0, pos + 1, "x");
        sleepFor(50);
    }

    getch();
    endwin();

    return 0;
}