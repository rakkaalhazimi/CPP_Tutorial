#include<iostream>
#include<iomanip>


int main(int argc, char const *argv[])
{   
    // The number of rows and columns in the table
    int size; 
    std::cout << "Please enter the table size: ";
    std::cin >> size;


    // Print indent
    std::cout << "    ";

    // Print columns
    int column = 1;
    while (column <= size) 
    {
        std::cout << std::setw(4) << column;
        column++;
    }
    std::cout << std::endl;


    // Print indent
    std::cout << "   +";

    // Print line separation
    column = 1;
    while (column <= size) 
    {
        std::cout << std::setw(2) << "----";
        column++;
    }
    std::cout << std::endl;

    // Print number products
    int row = 1;
    while (row <= size) {
        int column = 1;
        std::cout << std::setw(2) << row << " |";
        while (column <= size)
        {
            std::cout << std::setw(4) << row * column;
            column++;
        }
        std::cout << std::endl;
        row++;

    }




    return 0;
}
