#include<iostream>
#include<typeinfo>



class Euro
{
  public:
    Euro(int) {};
    Euro(double) {};
};


int main() {
  
  Euro my(2),     // int to Euro
      your(3.1);  // double to Euro
      
  std::cout << typeid(my).name() << std::endl;
  std::cout << typeid(your).name() << std::endl;
  
  my = 1.0;         // Implicit conversion: double -> Euro
  your = 1;         // Implicit conversion: int -> Euro
  
  your = Euro(1.0); // Explicit conversion (consturctor style)
  my = (Euro)1;     // Explicit conversion (cast style)
  
  your = my;        // No conversion
  
  return 0;
}