#include<iostream>

int main(int argc, char const *argv[]) {

    // regular
    char seq[] = "abcde";
    std::cout << seq << std::endl;

    // point at first element
    const char *seqPtr = "abcde";
    std::cout << *(seqPtr + 1) << std::endl; // get 2nd element of char

    return 0;
}
