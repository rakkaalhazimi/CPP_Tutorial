// A dynamic array is an array whose size can be changed during the execution of
// the program. The most popular dynamic array in C++ is the vector structure,
// which can be used almost like an ordinary array

#include<bits/stdc++.h>
using namespace std;

int vector_() {
    // CREATE AND INDEXING
    vector<int> v;

    v.push_back(3); // [3]
    v.push_back(2); // [3,2]
    v.push_back(5); // [3,2,5]

    cout << v[0] << "\n"; // 3
    cout << v[1] << "\n"; // 2
    cout << v[2] << "\n"; // 5

    // ITERATION
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    for (auto i: v) {
        cout << i << "\n";
    }

    // INITIAL VECTOR
    vector<int> v1 = {2,4,2,5,1};

    // size 10, initial value 0
    vector<int> v2(10);

    // size 10, initial value 5
    vector<int> v3(10, 5);

    return 0;
}

// The string structure is also a dynamic array that can be used almost like
// a vector.

int string_() {

    string a = "hatti";
    string b = a + a;
    cout << b << "\n"; // hattihatti
    b[5] = 'v';
    cout << b << "\n"; // hattivatti
    string c = b.substr(3,4);
    cout << c << "\n"; // tiva

    return 0;
}


int main() {

    // vector_();
    string_();

    return 0;
}