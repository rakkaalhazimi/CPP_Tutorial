#include<algorithm>
#include<chrono>
#include<ctime>
#include<curses.h>
#include<iostream>
#include<queue>
#include<random>
#include<string>
#include<typeinfo>
#include<thread>
#include<vector>


struct Coordinate {
    int y;
    int x;
};


WINDOW *createWindow(int height, int width, int starty, int startx) {
    
    WINDOW *localWin;
    localWin = newwin(height, width, starty, startx);
    refresh();

    box(localWin, 0, 0);
    wrefresh(localWin);

    return localWin;
}

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

bool isCollide(int& y, int& x, std::vector<Coordinate> body) {

    for (Coordinate limb: body) {
        if (x == limb.x && y == limb.y) return true;
    }
    return false;
}

Coordinate summonFood(
        std::uniform_int_distribution<int>& distributionY, 
        std::uniform_int_distribution<int>& distributionX,
        std::mt19937& generator,
        WINDOW *window) {
    
    int y = distributionY(generator);
    int x = distributionX(generator);
    mvwprintw(window, y, x, "o");
    Coordinate food = {.y=y, .x=x};
    return food;
}

void renderSnake(
        int& y, 
        int& x, 
        int& length, 
        std::vector<Coordinate>& body,
        WINDOW *window) {

    Coordinate head = {.y=y, .x=x};
    body.push_back(head);
    mvwaddstr(window, head.y, head.x, "x");
    wrefresh(window);

    if (body.size() >= length) {
        Coordinate tail = body[0];
        mvwaddstr(window, tail.y, tail.x, " ");
        body.erase(body.begin());
    }
}


int main() {

    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    // wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');

    int y, x, maxY, maxX, height, width, startY, startX, keyPressed, snakeLength = 1;
    std::vector<Coordinate> snakeBody;
    
    // Get max y and x
    getmaxyx(stdscr, maxY, maxX);

    // Create new window
    height = maxY / 2;
    width = maxX / 2;
    startY = (maxY - height) / 2;
    startX = (maxX - width) / 2;
    WINDOW *snakeWin = createWindow(height, width, startY, startX);

    // Obtain a random number from hardware
    std::random_device rd; 

    // Seed the generator
    std::mt19937 generator(rd()); 

    // Define the range
    std::uniform_int_distribution<int> distributionY(1, height - 2);
    std::uniform_int_distribution<int> distributionX(1, width - 2);

    // Summon first food
    Coordinate foodCoor = summonFood(distributionY, distributionX, generator, snakeWin);

    // Save last move
    void (*lastMove)(int&, int&) = &moveRight;

    // Starts from this coordinate
    y = height / 2;
    x = width / 2;

    while ( (keyPressed = getch()) != 27) {

        mvprintw(1, 1, "x: %2d, y: %2d, score: %2d", x, y, snakeLength);

        switch (keyPressed) {
            case KEY_UP:
                if (lastMove == moveDown) {
                    lastMove(y, x);
                    break;
                }
                moveUp(y, x);
                lastMove = moveUp;
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

        // Game Over if snake head collide with its body.
        if (isCollide(y, x, snakeBody)) {
            nodelay(stdscr, false);
            mvprintw(maxY / 2 + height / 2 + 3, maxX / 2 + height / 2 + 3, "Game Over, Press Esc to Exit");
            break;
        }

        // Move snake on the reverse side when out of bound.
        if (y > height - 2) {
            y = 1;

        } else if (y < 1) {
            y = height - 2;
        }

        if (x > width - 2) {
            x = 1;
        
        } else if (x < 1) {
            x = width - 2;
        }

        
        renderSnake(y, x, snakeLength, snakeBody, snakeWin);

        if (foodCoor.y == y && foodCoor.x == x) {
            snakeLength++;
            foodCoor = summonFood(distributionY, distributionX, generator, snakeWin);
        }

        refresh();
        
        sleepFor(100);
    }

    getch();
    endwin();

    return 0;
}