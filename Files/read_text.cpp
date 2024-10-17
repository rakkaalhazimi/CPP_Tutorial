#include<iostream>
#include<fstream>


int main(int argc, char const *argv[])
{
  std::ifstream textFile("test.txt");
  std::string line;
  
  if (textFile.is_open())
  {
    while (getline(textFile, line))
    {
      std::cout << line << std::endl;
    }
  }

  return 0;
}
