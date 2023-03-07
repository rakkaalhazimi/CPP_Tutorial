#include<iostream>

class Rect {
    public:
        int w, h;

        // Initialize member in constructor
        Rect(int w = 0, int h = 0): w(w), h(h) {}

        int area() {
            return w * h;
        }

};


int main() {

    Rect myShape(1, 1);

    std::cout << myShape.w << std::endl;
    std::cout << myShape.h << std::endl;
    std::cout << myShape.area() << std::endl;


    return 0;
}