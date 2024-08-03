#include<iostream>


int main() {
    
    int valid, *invalid = nullptr;
    
    if (invalid == nullptr)
    {
      std::cout << "null" << std::endl;
    }
    
    // Any valid memory address is not equal to 0;
    // Only null pointer is defined as 0;
    std::cout << valid << std::endl;
    std::cout << invalid << std::endl;
       
    return 0;
}