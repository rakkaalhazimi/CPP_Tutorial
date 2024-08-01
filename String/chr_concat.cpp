#include<iostream>
#include<cstring>
#include<string>


int main(int argc, char const *argv[])
{
  // Addition operator
  const char *name = "rakka";
  std::string firstName = name;
  std::string lastName = "alhazimi";
  
  std::cout << firstName + lastName;
  
  
  // Pointer method
  char *s1 = "rakka", *s2 = "alhazimi";
  char *p = s1 + strlen(s1);
  
  strcpy(p, s2);
  
  std::cout << s1 << std::endl;
  
  
  return 0;
}
