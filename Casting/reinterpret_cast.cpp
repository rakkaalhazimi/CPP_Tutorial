#include<iostream>


int main() {
  
  float myFloat = 3.14;
  // Read float byte and treat them as integer
  int myInt = *reinterpret_cast<int*>(&myFloat);
  // Read float bytes and treat them as char
  char myChar = *reinterpret_cast<char*>(&myFloat);
  
  std::cout << myInt << std::endl;
  std::cout << myChar << std::endl;
   
  return 0;
}