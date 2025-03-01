#include<iostream>
#include<iomanip>


int main(int argc, char const *argv[])
{
  int width = 10;
  std::cout << "Current cout width is: " << std::cout.width() << std::endl;
  std::cout << "Width is " << width << std::setw(10) << "here" << std::endl;
  
  
  return 0;
}
