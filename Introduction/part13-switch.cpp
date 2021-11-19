#include <iostream>
#include <string>
using namespace std;


int main() {

    // S W I T C H  S T A T E M E N T S
    int myGrade = 'A';
    switch(myGrade) {
        case 'A':
            cout << "You pass" << endl;
            break;
        
        case 'B':
            cout << "You fail" << endl;
            break;

        default:
            cout << "Invalid grade" << endl;
    }


    return 0;
}