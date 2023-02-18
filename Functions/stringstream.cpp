#include<iostream>
#include<sstream>
#include<string>
#include <typeinfo>


int main(int argc, char const *argv[])
{
    std::string mystr;
    float price = 0;
    int quantity = 0;

    std::cout << "Enter price: ";
    std::getline(std::cin, mystr);              // Stream input to mystr
    std::stringstream(mystr) >> price;          // Stream mystr to price (while also convert the type)
    
    // std::cout << "Type of " << typeid(mystr).name();

    std::cout << "Enter quantity: ";
    std::getline(std::cin, mystr);
    std::stringstream(mystr) >> quantity;

    std::cout << "Total is: " << price * quantity;

    return 0;
}
