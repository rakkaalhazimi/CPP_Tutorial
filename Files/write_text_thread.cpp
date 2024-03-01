#include<iostream>
#include<fstream>
#include<thread>


void writeFile() {
  std::ofstream textFile;
  textFile.open("test.txt", std::ios::app);
  textFile << "Writing to this file" << std::endl;
  textFile.close();
}


int main(int argc, char const *argv[])
{
  
  std::thread first(writeFile);
  
  first.join();
  
  return 0;
}
