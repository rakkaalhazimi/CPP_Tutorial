#include <iostream>
#include <string>

using namespace std;

int main() {
    // C O N S T A N T S
    int const BIRTH_YEAR = 1997;
    // BIRTH_YEAR = 1998 // Can't do this
    cout << BIRTH_YEAR << endl;

    // C A S T I N G
    cout << (int)3.14 << endl;
    cout << (double)3 / 2 << endl;

    return 0;
}