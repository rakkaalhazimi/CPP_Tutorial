// Outputs three random numbers
#include <iostream> // Declaration of cin and cout
#include <cstdlib>  // Prototypes of srand(), rand():
                    // void srand( unsigned int seed );
                    // int rand( void );

int main()
{
  unsigned int seed;
  int z1, z2, z3;
  std::cout << " --- Random Numbers --- \n"
       << std::endl;
  std::cout << "To initialize the random number generator, "
       << "\n please enter an integer value: ";
       
  std::cin >> seed; // Input an integer
  srand(seed);      // and use it as argument for a
                    // new sequence of random numbers.
              
  // Without explicit declaration of srand(...), it will be srand(1) all the time.
  
  z1 = rand(); // Compute three random numbers, range from 0 - 32767.
  z2 = rand();
  z3 = rand();
  std::cout << "\nThree random numbers: "
       << z1 << " " << z2 << " " << z3 << std::endl;
  return 0;
}