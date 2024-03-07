// On Linux
// g++ -o thread -pthread thread.cpp && ./thread

// On Windows
// cl /EHsc thread.cpp && .\thread.exe

#include<iostream>
#include<thread>


void countTo(int *n) {
    for (int i = 0 ; i < *n; i++) {
        std::cout << i << std::endl;
    }
}


int main() {

    int n = 10;

    std::thread event1(countTo, &n);
    std::thread event2(countTo, &n);

    event2.join();

    return 0;
}