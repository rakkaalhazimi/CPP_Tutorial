#include <iostream>
#include <string>
using namespace std;


class Chef {
    public:
        void makeChicken() {
            cout << "The chef makes chicken" << endl;
        }

        void makeSalad() {
            cout << "The chef makes salad" << endl;
        }

        void makeSpecialDish() {
            cout << "The chef makes special dish" << endl;
        }
};

class ItalianChef: public Chef {
    public:
        void makePasta() {
            cout << "The italian chef makes pasta" << endl;
        }
        // Override
        void makeSpecialDish() {
            cout << "The italian chef makes chicken perm" << endl;
        }
};


int main() {

    Chef myChef;
    myChef.makeChicken();

    ItalianChef myItalianChef;
    myItalianChef.makeChicken();

    return 0;
}