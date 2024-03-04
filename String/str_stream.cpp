#include<iostream>
#include<sstream>

int main(int argc, char const *argv[])
{
  
  std::stringstream fullName;
  const char *firstName = "rakka";
  const char *lastName = "alhazimi";
  
  fullName << firstName << " " << lastName;
  
  std::cout << fullName.str();
  
  return 0;
}
