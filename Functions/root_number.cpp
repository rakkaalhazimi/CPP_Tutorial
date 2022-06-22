#include<iostream>
#include<cmath>

int main(int argc, char const *argv[])
{
    float num;
    std::cout << "Enter number: ";
    std::cin >> num;

    std::cout << "The root of " << num << " is " << std::sqrt(num);

    return 0;
}
