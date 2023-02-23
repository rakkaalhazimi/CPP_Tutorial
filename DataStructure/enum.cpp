#include<iostream>


enum Fruits {
    Apple, Banana, Orange
};


int main() {

    Fruits myFruit = Banana;
    std::cout << myFruit << std::endl;
    std::cout << bool(Fruits::Orange == myFruit) << std::endl;
    std::cout << sizeof(Fruits) << std::endl;
    return 0;
}