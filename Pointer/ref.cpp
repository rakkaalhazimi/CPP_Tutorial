#include<iostream>


int main() {
    
    float x = 10.7F;
    
    float &rx = x;    // rx is reference of x (use the same memory)
    float *px = &x;   // px is the pointer of x
    
    std::cout << px << std::endl;
    std::cout << (&rx == px) << std::endl;  // pointer of rx and px are same
    
    return 0;
}