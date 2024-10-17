#include<iostream>


int main() {
  double width = 23.78;
  double* ptrWidth = &width;
  double* ptrLength = new double(32.54);
  double* ptrArea = new double;
  
  *ptrArea = *ptrWidth * *ptrLength;
  
  
  delete ptrLength; // Error: object is still in use
  
  std::cout << "\nWidth : " << *ptrWidth
            << "\nLength : " << *ptrLength
            << "\nArea : " << *ptrArea << std::endl;
            
  // To free storage:
  delete ptrWidth;    // Error: The object has not been dynamically reserved
  delete ptrLength;   // ok
  delete ptrArea;     // ok
  
  delete ptrLength; // Deleting pointer twice might lead to undefined behavior.
  
  return 0;
}