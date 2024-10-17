#include<iostream>


int main() {
    int numbers[] = {1, 2, 3, 4};
    int *pointer1 = numbers;
    int *pointer2 = (numbers + 3);
    
    // Number of element between pointer2 and pointer1    
    std::cout << pointer2 - pointer1 << std::endl;
    
    return 0;
}