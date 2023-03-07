#include<chrono>
#include<curses.h>
#include<string>
#include<thread>
#include<vector>


#define KEYBOARD_ENTER 10


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

    mvwprintw(stdscr, y / 2.5, x / 2 - game_title.size() / 2, game_title.c_str());
    mvwprintw(stdscr, start_y, x / 2 - start_text.size() / 2, "Start");
    mvwprintw(stdscr, quit_y, x / 2 - quit_text.size() / 2, "Quit");

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

        mvprintw(choices[last_choice], point_x, " ");
        mvprintw(choices[current_choice], point_x, ">");
        refresh();

        key_pressed = getch();

    } while (true);
}


void showGameScore(int y, int x, WINDOW *window) {
    mvwprintw(window, y, x, "x: %2d, y: %2d", x, y);
    wrefresh(window);
}


void controlBar(
        int& y, 
        int& x,
        int& screen_height,
        int& screen_width,
        int& key_pressed, 
        std::string *bar, 
        WINDOW *window) {

    switch(key_pressed) {
        case KEY_LEFT:
            if (x <= 1) break;
            x--;
            mvwaddstr(window, y, x + bar->size(), " ");
            break;

        case KEY_RIGHT:
            if ((x + bar->size() + 1) >= screen_width) break;
            x++;
            mvwaddstr(window, y, x - 1, " ");
            break;
    }
}


void pinballBarEvent(
        int *bar_y, 
        int *bar_x, 
        int *screen_height, 
        int *screen_width, 
        int *key_pressed, 
        std::string *bar, 
        WINDOW *window) {

    do {
        // Control bar
        switch(*key_pressed) {
        case KEY_LEFT:
            if (*bar_x <= 1) break;
            (*bar_x)--;
            mvwaddstr(window, *bar_y, *bar_x + bar->size(), " ");
            break;

        case KEY_RIGHT:
            if ((*bar_x + bar->size() + 1) >= *screen_width) break;
            (*bar_x)++;
            mvwaddstr(window, *bar_y, *bar_x - 1, " ");
            break;
        }
        
        // Render bar
        mvwprintw(window, *bar_y, *bar_x, bar->c_str());
        wrefresh(window);

    } while ( (*key_pressed = getch()) != 27);
}


void pinballBallEvent(
        int *ball_y, 
        int *ball_x,
        int *bar_y,
        int *bar_x,
        std::string *bar,
        int *screen_height, 
        int *screen_width, 
        WINDOW *window) {

    int last_y;
    int last_x;
    int direction_y = 1;
    int direction_x = 1;
    float increment_y = 0;

    while (true) {
        // Render ball
        mvwaddstr(window, last_y, last_x, " ");
        mvwaddstr(window, *ball_y, *ball_x, "o");
        wrefresh(window);

        last_y = *ball_y;
        last_x = *ball_x;

        // Ball hit right or left screen
        if (*ball_x >= *screen_width - 2) {
            direction_x = -1;
        
        } else if (*ball_x <= 1) {
            direction_x = 1;
        }

        // Ball hit the bar
        if (*ball_x >= *bar_x - 1 &&
            *ball_x <= *bar_x + bar->size() &&
            *ball_y == *bar_y - 1) {

            direction_y = -1;

            // Change direction based on the tip of the bar hitted
            if (*ball_x < *bar_x + bar->size() / 2) {
                direction_x = -1;
            
            } else if (*ball_x > *bar_x + bar->size() / 2) {
                direction_x = 1;
            }
        }  

        
        // Ball hit the ceiling
        if (*ball_y <= 1) {
            direction_y = 1;
        }

        // Velocity of vertical movement
        // if (ball_x % 3 == 2) {
            // ball_y++;
        // }
        
        *ball_y += (direction_y * 1);
        *ball_x += (direction_x * 1);

        sleepFor(200);
    }
}



int main() {

    int bar_y, bar_x, ball_y, ball_x;
    int key_pressed;
    int screen_height = 40;
    int screen_width = 70;
    int score_screen_height = screen_height * 0.1;
    int score_screen_width = screen_width;
    int pinball_screen_height = screen_height - score_screen_height;
    int pinball_screen_width = screen_width;
    std::string pinball_bar = "<===>";

    initscr();
    nodelay(stdscr, false);                     // Getch will block the program
    keypad(stdscr, true);                       // Use keypad
    curs_set(0);                                // Invisible cursor
    resize_term(screen_height, screen_width);   // Resize terminal

    // Start game screen
    showStartScreen();

    WINDOW *score_win = create_new_win(score_screen_height, screen_width, 0, 0);
    WINDOW *pinball_win = create_new_win(pinball_screen_height, pinball_screen_width, score_screen_height, 0);

    bar_y = pinball_screen_height - 4;
    bar_x = pinball_screen_width / 2;

    // Thread for bar event
    std::thread bar_event(
        pinballBarEvent, 
        &bar_y, 
        &bar_x, 
        &pinball_screen_height, 
        &pinball_screen_width, 
        &key_pressed, 
        &pinball_bar,
        pinball_win
    );

    ball_y = pinball_screen_height / 2;
    ball_x = pinball_screen_width / 2;

    // Thread for ball event
    std::thread ball_event(
        pinballBallEvent, 
        &ball_y, 
        &ball_x,
        &bar_y,
        &bar_x,
        &pinball_bar,
        &pinball_screen_height, 
        &pinball_screen_width, 
        pinball_win
    );

    showGameScore(1, 1, score_win);
    bar_event.join();

    getch();
    endwin();

    return 0;
}