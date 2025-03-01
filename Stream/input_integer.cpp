#include<iostream>


int main() {
    // Type 123FF <return>
    // 123 is saved in i, but FF is stored in read buffer
    
    int i;
    std::cout << "Please type 123FF: ";
    std::cin >> i;
    std::cout << "Your number is: " << i << std::endl;
    
    return 0;
}