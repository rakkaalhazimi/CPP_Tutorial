#include<iostream>

int main(int argc, char const *argv[])
{

    int num;

    std::cout << "Please enter your number: ";
    std::cin >> num;

    if (num % 2 == 0) std::cout << "Even";
    else std::cout << "Odd";

    return 0;
}
