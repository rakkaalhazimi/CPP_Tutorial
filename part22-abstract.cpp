#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Abstract Classes and Attribute
class Vehicle {
    public:
        virtual void move() = 0;  // Abstract method that the subclass need to implement
        void getDescription() {
            cout << "Vehicle are used for transportation" << endl;
        }
};

class Bicycle: public Vehicle {
    public:
        void move() {
            cout << "The bicycle pedals forward" << endl;
        }
};


class Plane: public Vehicle {
    public:
        void move() {
            cout << "The plane flys through he sky" << endl;
        }
};


int main() {

    Bicycle myBicycle;
    myBicycle.move();

    Plane myPlane;
    myPlane.move();

    return 0;
}