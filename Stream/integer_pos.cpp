// Reads integral decimal values and
// generates octal, decimal, and hexadecimal output.

#include <iostream>  // Declarations of cin, cout and manipulators oct, hex, ...

int main()
{
  int p = 1;
  int z = 0;
  int n = -1;
  std::cout << std::showpos   << p << '\t' << z << '\t' << n << '\n';
  std::cout << std::noshowpos << p << '\t' << z << '\t' << n << '\n';
  
  return 0;
}