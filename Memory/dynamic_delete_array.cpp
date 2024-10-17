#include<iostream>


int main() {
  // Dynamic array
  double *ptr_double_array = new double[10];
  
  // Delete dynamic array
  // if you use 'delete', it will only call
  // destructor of the first array index.
  delete[] ptr_double_array;
  
  return 0;
}