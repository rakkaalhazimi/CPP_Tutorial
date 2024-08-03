#include<iostream>


int main() {
  
    char x, y;
  
    std::cout << "Insert any button" << std::endl;
    std::cin >> x >> y;
    
    std::cout << (&x == &y) << std::endl;
    
    return 0;
}