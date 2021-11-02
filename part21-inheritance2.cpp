#include <iostream>
#include <string>
using namespace std;


class Chef {


    public:

        string name;
        int age;

        Chef(string name, int age) {
            this -> name = name;
            this -> age = age;
        }

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
    
        string origin;

        ItalianChef(string name, int age, string origin): Chef(name, age) {
            this -> origin = origin;
        }

        void makePasta() {
            cout << "The italian chef, " + this->name + ", makes pasta" << endl;
        }
        // Override
        void makeSpecialDish() {
            cout << "The italian chef, " + this->name + ", makes chicken perm" << endl;
        }
};


int main() {

    Chef myChef("Gustav", 40);
    myChef.makeSpecialDish();

    ItalianChef myItalianChef("Maqcuino", 22, "Italia");
    myItalianChef.makeSpecialDish();

    return 0;
}