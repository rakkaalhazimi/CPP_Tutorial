// A set is a data structure that maintains a collection of elements. The basic
// operations of sets are element insertion, search and removal.


#include<bits/stdc++.h>
using namespace std;

int main() {

    // CREATION
    set<int> s;

    // INSERTION
    s.insert(3);
    s.insert(2);
    s.insert(5);
    cout << s.count(3) << "\n"; // 1
    cout << s.count(4) << "\n"; // 0

    // REMOVAL
    s.erase(3);
    s.insert(4);
    cout << s.count(3) << "\n"; // 0
    cout << s.count(4) << "\n"; // 1

    // ITERATION: not possible using s[]
    set<int> s1 = {2,5,6,8};
    cout << s1.size() << "\n"; // 4
    for (auto x : s1) {
        cout << x << "\n";
    }

    // MEMBERSHIP CHECK
    set<int> s2;
    s2.insert(5);
    s2.insert(5);
    s2.insert(5);
    cout << "Memberhsip check" << "\n";
    cout << s2.count(5) << "\n";

    // MULTI SET: can contain multiple instances of elements
    multiset<int> s3;
    s3.insert(5);
    s3.insert(5);
    s3.insert(5);
    cout << "Memberhsip check: multiset" << "\n";
    cout << s3.count(5) << "\n"; // 3

    // MULTI SET: remove all instances of an element
    s3.erase(5);
    cout << "Erase all: multiset" << "\n";
    cout << s3.count(5) << "\n"; // 0


    // MULTI SET: remove one instances of an element
    multiset<int> s4 = {5, 5, 5};
    s4.erase(s4.find(5));
    cout << "Erase one: multiset" << "\n";
    cout << s4.count(5) << "\n"; // 2
    
    
    // COMPARISON: check if two sets are similar
    set<int> set1{1, 2, 3};
    set<int> set2{3, 2, 1};
    
    if (set1 == set2)
    {
        cout << "Similar" << endl;
        
    } else 
    {
        cout << "Not Similar" << endl;
    }
    
    
    // ITERATION: iterate throught set
    set<int> ages{20, 21, 22, 23};
    for (set<int>::iterator iter = ages.begin(); iter != ages.end(); iter++)
    {
        cout << *iter << endl;
    }
    
    // FIND: check if item is inside set
    set<int> setCheck{1, 2, 3};
    int item = 4;
    bool isIn = setCheck.find(item) != setCheck.end();
    cout << "Membership check: Is item '" << item << "' inside set: " << isIn << endl;
    
    
    // FIND: check if the item inside a set is also inside another set
    set<int> setCheck1{1, 2, 3, 4};
    set<int> setCheck2{3, 4, 5, 6};
    
    cout << "Multiset Membership check" << endl;
    for (set<int>::iterator iter = setCheck1.begin(); iter != setCheck1.end(); iter++)
    {
        bool isIn = setCheck2.find(*iter) != setCheck2.end();
        cout << "Is item '" << *iter << "' inside set: " << isIn << endl;
    }
    

    return 0;
}