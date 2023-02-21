#include<iostream>

int main(int argc, char const *argv[])
{   
    int num = 0;

    std::cout << *&num << std::endl;
    return 0;
}
