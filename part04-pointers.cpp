#include <iostream>
#include <string>
using namespace std;


int main() {
    // P O I N T E R S : use for access memory adress
    int num = 10;
    cout << &num << endl;  // prefix "&" on variable will give you the memory address

    int *pNum = &num;

    cout << pNum;

    return 0;
}