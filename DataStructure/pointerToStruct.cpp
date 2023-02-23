#include <iostream>


struct Car {
    char type;
    int release;
};


int main() {

    // Arrow -> is used to access an attribute through "a pointer of object".

    Car toyota;
    Car *pointer;
    pointer = &toyota;


    toyota.type = 'a';
    toyota.release = 2001;

    std::cout << pointer->release << std::endl;
    std::cout << pointer->type << std::endl;

    return 0;
}