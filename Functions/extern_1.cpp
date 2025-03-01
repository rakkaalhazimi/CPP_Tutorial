#include<iostream>
#include "extern_2.cpp"

// Extern tell the compiler that the function is defined somewhere
// outside this file

// You can omit the 'extern' keyword.
// Function belong to extern storage class by default.
extern void foo(void);
// void foo(void);

int main() {
    
    foo();
    
    return 0;
}