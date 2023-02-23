#include<curses.h>
#include<string>


int main() {

    initscr();
    char username[30];
    char password[30];
    std::string realPassword = "rakka";

    while (password != realPassword) {
        echo();
        printw("Enter your username: ");
        getstr(username);

        noecho();
        printw("Enter your password: ");
        getstr(password);

    }

    printw("You are loged in as %s, press any key to exit.", username);
    getch();

    endwin();

    return 0;
}