#include<iostream>

int main(int argc, char const *argv[])
{
    

    int current_weapon = 0;

    switch (current_weapon) 
    {
        case 0:
            std::cout << "Your weapon is sword";
            break;

        case 1:
            std::cout << "Your weapon is bow";
            break;

        case 2:
            std::cout << "Your weapon is axe";
            break;
    }

    return 0;
}
