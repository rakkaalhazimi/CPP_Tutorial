#include<iostream>

int main(int argc, char const *argv[])
{
  size_t size = 0;
  int *a = (int *)std::malloc(size);
  
  if (a == NULL)
  {
    std::cout << "Pointer is null" << std::endl;
    exit(1);
  }
  
  a[0] = 999;
  a[1] = 999;
  
  // std::cout << "Size of variable is: " << sizeof(a) << std::endl;
  std::cout << "Value 1: " << a[0] << std::endl;
  std::cout << "Value 2: " << a[1] << std::endl;
  
  free(a);
  return 0;
}
