#include <iostream>
#include <string>
using namespace std;


class Book {
    private:
        string title;
        string author;

    public:
        Book(string title, string author) {
            this -> title = title;
            this -> author = author;
        }
        // Getter
        string getTitle() {
            return this -> title;
        }
        // Setter
        void setTitle(string title) {
            this -> title = title;
        }

        void readBook() {
            cout << "Reading " << this -> title + " by " + this -> author << endl;
        }
};

int main() {

    Book book1("Harry Potter", "JK Rowling");
    cout << book1.getTitle() << endl;

    book1.setTitle("C++ for beginner");
    cout << book1.getTitle() << endl;


    return 0;
}