#define CLS (std::cout << "\033[2J")
#define LOCATE(z,s) (std::cout <<"\033["<< z <<';'<< s <<'H')

#include<iostream>


int main() {
    
    CLS;
    LOCATE(1, 25);
    
    return 0;
}