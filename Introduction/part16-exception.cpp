#include <iostream>
#include <string>
using namespace std;

double division (int a, int b) {
    if (b == 0) {
        throw "Division by zero error!";
    }
    return (a/b);
}


int main() {

    // E X C E P T I O N  C A T C H I N G

    try {
        division(10, 0);
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}