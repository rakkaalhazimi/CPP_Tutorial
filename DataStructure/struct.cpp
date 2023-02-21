#include<iostream>
#include<string>
#include<sstream>


struct Waifu {
    std::string name;
    std::string reason;
} myWef[3];


int main(int argc, char const *argv[])
{
    std::string strMem;

    for (int i=0; i < 3; i++) {
        std::cout << "Enter your waifu name: ";
        std::getline(std::cin, myWef[i].name);

        std::cout << "Why she is your waifu?: ";
        std::getline(std::cin, myWef[i].reason);

        std::cout << std::endl;
    }

    for (int i=0; i < 3; i++) {
        std::cout << "Your waifu is: " << myWef[i].name << std::endl;
        std::cout << "The reason is: " << myWef[i].reason << std::endl;

        std::cout << std::endl;
    }

    return 0;
}
