#include<iostream>

template <class T>
T sum(T a, T b) {
    T result;
    result = a + b;
    return result;
}

int main(int argc, char const *argv[]) {
    int a=2, b=2, c;
    c = sum<int>(a, b);
    std::cout << c << std::endl;
    return 0;
}
