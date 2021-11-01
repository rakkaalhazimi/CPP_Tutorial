#include <iostream>
#include <string>
using namespace std;

int main() {

    // S T R I N G S

    string greet = "Hello World!";

    cout << greet.length() << endl;     // Length of string
    cout << greet[0] << endl;           // First index of string
    cout << greet.find("llo") << endl;  // Find substring, return index
    cout << greet.substr(2) << endl;    // Get substring starting from index 3
    cout << greet.substr(1, 3) << endl; // Get substring from index 2 to index 4

    return 0;
}