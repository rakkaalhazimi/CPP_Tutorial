#include<iostream>


int main(int argc, char const *argv[]) {
    // Dynamic memory is allocated using operator new. 
    // new is followed by a data type specifier and, 
    // if a sequence of more than one element is required, 
    // the number of these within brackets []. 
    // 
    // It returns a pointer to the beginning of the new block of memory allocated.
    
    int *foo;
    foo = new int[5];
    for (int i=0; i < 5; i++) {
        std::cout << &foo[i] << std::endl;
    }

    // Returned pointer is the first element of array.
    // By using 'new' keyword, you can access the next element with (++array) or the equivalent.
    std::cout << "First element is: " << std::endl;
    std::cout << foo << std::endl;
    std::cout << "Second element is element: " << std::endl;
    std::cout << ++foo << std::endl;
    return 0;
}
