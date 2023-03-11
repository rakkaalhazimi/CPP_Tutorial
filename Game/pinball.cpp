#include<cmath>
#include<chrono>
#include<curses.h>
#include<panel.h>
#include<string>
#include<thread>
#include<vector>


#define KEYBOARD_ENTER 10

const int FPS = 60;
const int SCREEN_HEIGHT = 40;
const int SCREEN_WIDTH = 70;
const int SCORE_SCREEN_HEIGHT = SCREEN_HEIGHT * 0.1;
const int SCORE_SCREEN_WIDTH = SCREEN_WIDTH;
const int PINBALL_SCREEN_HEIGHT = SCREEN_HEIGHT - SCORE_SCREEN_HEIGHT;
const int PINBALL_SCREEN_WIDTH = SCREEN_WIDTH;
const std::string PINBALL_BAR = "<===>";


inline void sleepFor(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

WINDOW *create_new_win(int height, int width, int start_Y, int start_X) {

    WINDOW *local_win = newwin(height, width, start_Y, start_X);
    box(local_win, 0, 0);
    wrefresh(local_win);
    refresh();

    return local_win;
}


void showStartScreen() {
    int y, x; 
    getmaxyx(stdscr, y, x);
    int key_pressed;
    std::string game_title = "Supa Hot Pinball";
    std::string start_text = "Start";
    std::string quit_text = "Quit";

    int start_y = y / 2;
    int quit_y = y / 1.9;
    int point_y;
    int point_x = x / 2 - 5;

    WINDOW *window = newwin(y, x, 0, 0);
    PANEL *menu_panel = new_panel(window);
    update_panels();
    doupdate();

    mvwprintw(window, y / 2.5, x / 2 - game_title.size() / 2, game_title.c_str());
    mvwprintw(window, start_y, x / 2 - start_text.size() / 2, "Start");
    mvwprintw(window, quit_y, x / 2 - quit_text.size() / 2, "Quit");
    wrefresh(window);

    int current_choice = 0;
    int last_choice = current_choice;
    int n_choice = 2;
    int choices[n_choice] = {start_y, quit_y};
    point_y = choices[current_choice];

    do {
        switch(key_pressed) {
            case KEY_UP:
                last_choice = current_choice;
                current_choice--;
                if (current_choice < 0) {
                    current_choice = n_choice;
                }
                break;

            case KEY_DOWN:
                last_choice = current_choice;
                current_choice++;
                if (current_choice > n_choice - 1) {
                    current_choice = 0;
                }
                break;

            case KEYBOARD_ENTER:
                if (choices[current_choice] == quit_y) {
                    exit(0);
            
                } else if (choices[current_choice] == start_y) {
                    return;
                }
                break;
        }

        mvwprintw(window, choices[last_choice], point_x, " ");
        mvwprintw(window, choices[current_choice], point_x, ">");
        wrefresh(window);

        key_pressed = getch();

    } while (true);

    del_panel(menu_panel);
    update_panels();
    doupdate();
}


void showGameScore(float y, float x, WINDOW *window) {
    mvwprintw(window, 1, 1, "x: %2.2f, y: %2.2f", x, y);
    wrefresh(window);
}


void moveBar(
        int& bar_y, 
        int& bar_x, 
        int& key_pressed, 
        WINDOW *window) {

    // Control bar
    key_pressed = getch();

    switch(key_pressed) {
    case KEY_LEFT:
        if (bar_x <= 1) break;
        bar_x--;
        mvwaddstr(window, bar_y, bar_x + PINBALL_BAR.size(), " ");
        break;

    case KEY_RIGHT:
        if ((bar_x + PINBALL_BAR.size() + 1) >= PINBALL_SCREEN_WIDTH) break;
        bar_x++;
        mvwaddstr(window, bar_y, bar_x - 1, " ");
        break;
    }

    // Render bar
    mvwprintw(window, bar_y, bar_x, PINBALL_BAR.c_str());
    wrefresh(window);
}


void renderBall(
        float ball_y, 
        float ball_x, 
        float last_ball_y, 
        float last_ball_x, 
        WINDOW *window) {

    mvwaddstr(window, last_ball_y, last_ball_x, " ");
    mvwaddstr(window, ball_y, ball_x, "o");
    wrefresh(window);
}


void moveBall(
        float& ball_y, 
        float& ball_x,
        float& last_ball_y, 
        float& last_ball_x,
        float& velocity_y,
        float& velocity_x,
        int& bar_y,
        int& bar_x,
        WINDOW *window) {

    // Ball hit right or left screen
    if (ball_x >= PINBALL_SCREEN_WIDTH - 2 || ball_x <= 1) {
        velocity_x *= -1;
    }

    // Ball hit the ceiling or the bottom of the screen
    if (ball_y >= PINBALL_SCREEN_HEIGHT - 2 || ball_y <= 1) {
        velocity_y *= -1;
    } 

    // Ball hit the bar
    if (ball_x >= bar_x - 1 &&
        ball_x <= bar_x + PINBALL_BAR.size() &&
        ball_y == bar_y - 1) {

        velocity_y *= -1;

        // Change direction based on the tip of the bar hitted
        if (ball_x < bar_x + PINBALL_BAR.size() / 2) {
            if (velocity_x > 0) velocity_x *= -1;
            
        
        } else if (ball_x > bar_x + PINBALL_BAR.size() / 2) {
            if (velocity_x < 0) velocity_x *= -1;
        }  
}

    // Update ball coordinates
    ball_y += velocity_y;
    ball_x += velocity_x;

    // Render ball
    // Use ceiling when velocity is more than 0
    if (velocity_x > 0 && velocity_y > 0) {
        renderBall(std::ceil(ball_y), std::ceil(ball_x), std::ceil(last_ball_y), std::ceil(last_ball_x), window);
    
    } else if (velocity_x > 0) {
        renderBall(ball_y, std::ceil(ball_x), last_ball_y, std::ceil(last_ball_x), window);

    } else if (velocity_y > 0) {
        renderBall(std::ceil(ball_y), ball_x, std::ceil(last_ball_y), last_ball_x, window);

    } else {
        renderBall(ball_y, ball_x, last_ball_y, last_ball_x, window);
    }

    // Update last ball coordinate
    last_ball_y = ball_y;
    last_ball_x = ball_x;
}



int main() {

    int max_pinball_y, max_pinball_x, bar_y, bar_x, key_pressed;
    float ball_y, ball_x, last_ball_y, last_ball_x, ball_direction_y, ball_direction_x, ball_velocity_y, ball_velocity_x;

    initscr();
    nodelay(stdscr, true);                              // Getch won't block the program
    keypad(stdscr, true);                               // Use keypad
    curs_set(0);                                        // Invisible cursor
    resize_term(SCREEN_HEIGHT, PINBALL_SCREEN_WIDTH);   // Resize terminal

    // Start game screen
    showStartScreen();

    // Score and Pinball Panel
    WINDOW *score_win = create_new_win(SCORE_SCREEN_HEIGHT, SCORE_SCREEN_WIDTH, 0, 0);
    PANEL *score_panel = new_panel(score_win);

    WINDOW *pinball_win = create_new_win(PINBALL_SCREEN_HEIGHT, PINBALL_SCREEN_WIDTH, SCORE_SCREEN_HEIGHT, 0);
    PANEL *pinball_panel = new_panel(pinball_win);

    update_panels();
    doupdate();

    // Initial bar position; ball position, direction and velocity.
    getmaxyx(pinball_win, max_pinball_y, max_pinball_x);
    bar_y = max_pinball_y - 4;
    bar_x = max_pinball_x / 2;
    ball_y = max_pinball_y / 2;
    ball_x = max_pinball_x / 2;
    ball_velocity_y = .25;
    ball_velocity_x = .25;


    while (true) {
        
        moveBall(
            ball_y, 
            ball_x, 
            last_ball_y, 
            last_ball_x, 
            ball_velocity_y, 
            ball_velocity_x,
            bar_y, 
            bar_x, 
            pinball_win);

        moveBar(
            bar_y,
            bar_x,
            key_pressed,
            pinball_win
        );
            
        showGameScore(ball_y, ball_x, score_win);

        sleepFor(1000 / FPS);
    }

    getch();
    endwin();

    return 0;
}