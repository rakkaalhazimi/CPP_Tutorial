#include<iostream>
#include<string>
#include<sstream>


int main(int argc, char const *argv[])
{
  std::string sentence = "hello how are you";
  std::stringstream stream;
  stream << "hello";
  
  std::cout << "Before clear" << std::endl;
  std::cout << stream.str() << std::endl;
  
  std::cout << std::endl;
  
  stream.str(std::string());
  stream.clear();
  std::cout << "After clear" << std::endl;
  std::cout << stream.str() << std::endl;
  
  
  return 0;
}
