#include<iostream>


int addTwo(int& a, int& b) {
    a++;
    b++;
    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Value of b: " << b << std::endl;
    return a + b;
}


int main(int argc, char const *argv[]) {

    int a = 10;
    int b = 10;

    int c = addTwo(a, b);

    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Value of b: " << b << std::endl;

    return 0;
}
