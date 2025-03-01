// Reads integral decimal values and
// generates octal, decimal, and hexadecimal output.

#include <iostream>  // Declarations of cin, cout and manipulators oct, hex, ...

int main()
{
  int number = 10;
  std::cout << std::uppercase // for hex-digits
            << " octal \t decimal \t hexadecimal\n"
            << std::oct << number << " \t "
            << std::dec << number << " \t "
            << std::hex << number << std::endl;
  
  return 0;
}