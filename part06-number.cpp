#include <iostream>
#include <string>
using namespace std;

int main() {
    
    // N U M B E R S

    cout << 2 * 3 << endl;      // Basic Arithmetic: +, -, *, /
    cout << 10 % 3 << endl;     // Modulo operations: Remainder of 10 / 3
    cout << 1 + 2 * 3 << endl;  // Order of operations
    cout << 10 / 3.0 << endl;   // int vs doubles: returns double

    int num = 10;
    num += 100;                 // +=, -=, /=, *=
    cout << num << endl;

    num++                       // Increment
    cout << num << endl;
    
    return 0;
}