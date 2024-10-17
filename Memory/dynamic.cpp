#include<iostream>


int main() {
  
  // Dynamic object
  double *ptr_double = new double;
  
  // Dynamic array
  double *ptr_double_array = new double[10];
  
  std::cout << ptr_double << std::endl;
  std::cout << ptr_double_array << std::endl;
  
  
  return 0;
}