#include <iostream>
#include <set>
#include <sstream>
#include <string>


void compareFiles(std::string main, std::string target)
{
    std::set<std::string> mainFiles, targetFiles;
    std::stringstream mainStream(main), targetStream(target);
    std::string mainLine, targetLine;
    
    while (mainStream >> mainLine)
    {
      std::cout << mainLine << std::endl;
      mainFiles.insert(mainLine);
    }
    
    while (targetStream >> targetLine)
    {
      std::cout << targetLine << std::endl;
      targetFiles.insert(targetLine);
    }
    
    if (mainFiles == targetFiles)
    {
      std::cout << "Similar" << std::endl;
      
    } else 
    {
      std::cout << "Not Similar" << std::endl;
    }
    
}

int main(int argc, char const *argv[])
{
  std::string main, target;
  main = "hello how are you";
  target = "hello how are you";
  
  compareFiles(main, target);  
  
  
  return 0;
}
