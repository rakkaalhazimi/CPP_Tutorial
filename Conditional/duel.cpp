#include<iostream>

int main(int argc, char const *argv[])
{
    bool isWin;

    int yourPower, enemyPower;

    std::cout << "Your power level: ";
    std::cin >> yourPower;

    std::cout << "Enemy power level: ";
    std::cin >> enemyPower;

    int powerDiff = yourPower - enemyPower;

    if (yourPower > enemyPower) 
        std::cout << "You have " 
                  << powerDiff 
                  << " more power, you win !";

    else 
        std::cout << "You have " 
                  << powerDiff 
                  << " less power, you lose !";

    return 0;
}
