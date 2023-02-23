#include<iostream>


int main() {

    // The concept of arrays is related to that of pointers. 
    // In fact, arrays work very much like pointers to their first elements, 
    // and, actually, an array can always be implicitly converted to the pointer of the proper type.
    
    int numbers[3] = {1, 2, 3};
    int *pointer = numbers;

    std::cout << "First element:" << std::endl;
    std::cout << *pointer << std::endl;

    pointer++;
    std::cout << "Second element:" << std::endl;
    std::cout << *pointer << std::endl;

    pointer++;
    std::cout << "Third element:" << std::endl;
    std::cout << *pointer << std::endl;

    return 0;

}