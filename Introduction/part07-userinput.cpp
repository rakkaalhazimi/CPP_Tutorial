#include <iostream>
#include <string>
using namespace std;

int main() {
    
    // U S E R   I N P U T
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Your name is " << name << endl;

    int num1, num2;
    cout << "Enter first num: ";
    cin >> num1;
    cout << "Enter second num: ";
    cin >> num2;
    cout << "Answer is " << num1 + num2;

    return 0;
}