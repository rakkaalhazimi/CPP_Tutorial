// Many functions in the C++ standard library operate with iterators. An iterator
// is a variable that points to an element in a data structure

// The often used iterators begin and end define a range that contains all elements in a data structure.
// The iterator begin points to the first element in the data structure,
// and the iterator end points to the position after the last element.

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v = {2, 4, 1, 3};
    // WORKING WITH RANGES
    // Sort vector
    sort(v.begin(), v.end());

    // Reverse vector
    reverse(v.begin(), v.end());

    // Random shuffle
    random_shuffle(v.begin(), v.end());

    // SET ITERATORS
    set<int> s = {2, 3};

    // Create set iterator
    set<int>::iterator it = s.begin();
    // or
    auto it1 = s.begin();

    // The element to which an iterator points can be accessed using the * symbol. For
    // example, the following code prints the first element in the set:
    cout << *it1 << "\n";

    // Move iterators forward and backwards
    cout << "Move the element forward"
         << "\n";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << "\n";
    }

    // Get largest element
    cout << "Largest Element"
         << "\n";
    auto it2 = s.end();
    it2--;
    cout << *it2 << "\n";

    // Returns an iterator that points to an element whose
    // value is x.
    cout << "Find x in set"
         << "\n";
    int x = 3;
    auto it3 = s.find(x);
    if (it3 == s.end())
    {
        // x is not found, then return s.end()
        cout << "x is not found"
             << "\n";
    }
    else
    {
        cout << "found x"
             << "\n";
    }


    //  Finds the element nearest to x
    cout << "Find nearest element"
             << "\n";
    auto it4 = s.lower_bound(x);
    cout << *it4 << "\n";

    if (it4 == s.begin())
    {
        cout << "x is near the start" << "\n";
        cout << *it4 << "\n";
    }

    else if (it4 == s.end())
    {
        it--;
        cout << "x is near the end" << "\n";
        cout << *it4 << "\n";
    }

    else
    {
        int a = *it4;
        it4--;
        int b = *it4;
        cout << "x is in the middle" << "\n";
        if (x - b < a - x)
            cout << b << "\n";
        else
            cout << a << "\n";
    }

        return 0;
    }