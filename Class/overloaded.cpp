#include<iostream>

class Rect {
    public:
        int w, h;

        Rect(int w = 0, int h = 0) {
            this -> w = w;
            this -> h = h;
        }

        int area() {
            return w * h;
        }

        // Method to define + operator for this class
        Rect operator+ (const Rect& other) {
            Rect temp;
            temp.w = w + other.w;
            temp.h = h + other.h;
            return temp;
        }

        Rect operator- (const Rect& other) {
            Rect temp;
            temp.w = w - other.w;
            temp.h = h - other.h;
            return temp;
        }
        
        // Return the reference to avoid copy
        Rect& operator<< (Rect& other) {
            return other;
        }
        
};


int main() {

    Rect myShape(1, 1);
    Rect otherShape(2, 2);
    Rect unknownShape;

    unknownShape = myShape + otherShape;

    std::cout << unknownShape.w << std::endl;
    std::cout << unknownShape.h << std::endl;
    std::cout << unknownShape.area() << std::endl;
    
    Rect& anomaliShape = (myShape << otherShape);
    std::cout << (&anomaliShape == &otherShape) << std::endl;
    
    


    return 0;
}