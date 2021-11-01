#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    // V E C T O R S: Dynamic version of arrays
    vector<string> friends;
    friends.push_back("Jim");                       // Push element into vector
    friends.push_back("Michael");
    friends.push_back("Angela");
    friends.insert(friends.begin() + 1, "Kevin");   // Insert element of specific location
                                                    // .begin() is a pointer to specify the beginning of vector

    friends.erase(friends.begin() + 1);
    cout << friends.at(0) << endl;
    cout << friends.at(1) << endl;
    cout << friends.at(2) << endl;
    cout << friends.size();
    
    return 0;
}