#include<iostream>
#include<fstream>
#include<thread>


uint64_t getFileSize(std::fstream &file)
{
  return file.tellg();
}

int main(int argc, char const *argv[])
{
  
  std::fstream textFile;
  textFile.open("test.txt", std::ios::app);
  textFile.seekg(0, std::ios::end);
  uint64_t fileSize = getFileSize(textFile);
  std::cout << fileSize << std::endl;
  textFile.close();
  
  return 0;
}
