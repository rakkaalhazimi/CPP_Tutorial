#include<iostream>


class Euro 
{
  private:
    long number;
  public:
    Euro(double x): number(x) {};
    // Convert Euro to double
    operator double() const
    {
      return (double)number/100.0;
    }
};


int main() {
  
  Euro my(3.0);
  double x = 1.0;
  
  x = (double)my;           // Explicit conversion, Euro -> double
  x = my;                   // Implicit conversion, Euro -> double
  x = my.operator double(); // also possible 
  
  int y = my;               // Euro -> double -> int
  
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  
  return 0;
}