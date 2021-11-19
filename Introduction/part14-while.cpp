#include <iostream>
#include <string>
using namespace std;


int main() {

    // W H I L E  L O O P S
    int index = 1;

    while (index < 5) {
        cout << index << endl;
        index++;
    }
    
    do {
        cout << index << endl;
        index++;
    }
    while (index < 1);


    return 0;
}