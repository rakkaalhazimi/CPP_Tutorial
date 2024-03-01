#include<iostream>
#include<fstream>
#include<thread>



int main(int argc, char const *argv[])
{
  
  std::ofstream textFile;
  textFile.open("test.txt", std::ios::app);
  textFile << "Writing to this file" << std::endl;
  textFile.close();
  
  return 0;
}
