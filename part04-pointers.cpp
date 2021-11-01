#include <iostream>
#include <string>
using namespace std;


int main() {
    // P O I N T E R S : use for access memory address
    int num = 10;
    cout << &num << endl;   // Prefix "&" on variable will give you the memory address where it's stored

    int *pNum = &num;       // You can store the memory address with pointer by using "*" prefix
                            // you need to specify "int" because the memory address is a int type.

    cout << pNum << endl;   // This'll print the memory address
    cout << *pNum << endl;  // This'll print the value (dereference)

    return 0;
}