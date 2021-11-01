#include <iostream> // allow you to pring and get information from user
#include <string>   // allow you to work with string

using namespace std;  // we can use all the things inside "std"

int main() {

    /*
    Names are case-sensitive and may begin with:
        letters, _
    After, may include
        letters, numbers, _
    Convention says
        Start with a lowercase word, then additional words are capitalized
        ex. myFirstVariable
    */
    string name = "Mike";    // string of characters, not primitive
    char testGrade = 'A';    // single 8-bit character.

    // you can make them unsigned by adding "unsigned" prefix
    short age0 = 10;         // atleast 16-bits signed integer
    unsigned int age1 = 20;  // atleast 16-bits signed integer (not smaller than short)
    long age2 = 30;          // atleast 32-bits signed integer
    long long age3 = 40;     // atleast 64-bits signed integer

    float gpa0 = 2.5f;       // single percision floating point
    double gpa1 = 3.5;       // double-precision floating point
    long double gpa2 = 3.5;  // extended-precision floating point

    bool isTall;             // 1 bit -> true/false
    isTall = true;

    name = "John";

    string lastname = "alhazimi";

    cout << "Your name is " << name << endl;
    cout << "My number: " << isTall << endl;
    cout << "My last name: " << lastname << endl;

    return 0;
}
