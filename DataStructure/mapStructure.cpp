// A map is a generalized array that consists of key-value-pairs. While the keys in
// an ordinary array are always the consecutive integers 0,1,...,n−1, where n is
// the size of the array, the keys in a map can be of any data type and they do not
// have to be consecutive values.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // CREATION
    map<string, int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpsichord"] = 9;
    cout << m["banana"] << "\n"; // 3

    // If not found, new KEY will be created with default value
    map<string, int> m1;
    cout << m["aybabtu"] << "\n"; // 0

    // MEMBERSHIP CHECK
    if (m.count("aybabtu"))
    {
        // key exists
        cout << "Exist" << "\n";
    }

    // ITERATION: key, value pairs
    for (auto x : m) {
        cout << x.first << " " << x.second << "\n";
    }


    return 0;
}