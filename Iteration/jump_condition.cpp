#include<iostream>

int main(int argc, char const *argv[])
{

    int floors = 10;
    int current = 1;

    while (current <= floors)
    {
        
        std::cout << "Enter floor: " << current
                  << std::endl;

        if (current == 9)
        {
            goto end;
        }
        
        current++;
    }

    end:
        std::cout << "Danger don't enter floor 10th";

    return 0;
}
