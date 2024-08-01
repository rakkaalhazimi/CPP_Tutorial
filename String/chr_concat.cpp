#include<iostream>
#include<cstring>
#include<string>


int main(int argc, char const *argv[])
{
  // Addition operator
  const char *name = "rakka";
  std::string firstName = name;
  std::string lastName = "alhazimi";
  
  std::cout << firstName + lastName << std::endl;
  
  // Pointer method
  const char *s1 = "rakka", *s2 = "alhazimi";
  char *s1_copy = new char[strlen(s1) + strlen(s2) + 1]; // One for null terminating char '/0'
  
  // Don't do this
  //
  // char *s1 = "rakka";
  // char *s2 = "alhazimi";
  // char *p = s1 + strlen(s1);
  // strcpy(p, s2);
  //
  // This will lead to segmentation fault, because we try to
  // write the read-only memory, memory beyond s1, which will lead to
  // undefined behavior.
  
  strcpy(s1_copy, s1);
  strcat(s1_copy, s2);
  
  std::cout << s1_copy << std::endl;
   
  return 0;
}
