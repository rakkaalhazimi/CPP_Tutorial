#include<iostream>
#include<fstream>


int main() {
    
  std::ifstream myFile;
  
  if (!myFile) {} // Read or Write error occurs
  
  if (myFile.eof()) {} // At the end-of-file
  
    
  return 0;
}