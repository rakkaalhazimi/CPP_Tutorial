#include<iostream>
#include<ctime>

#define gettime std::time(0)


int main() {

    std::cout << "Current epoch time is: " << gettime << std::endl;

    return 0;
}