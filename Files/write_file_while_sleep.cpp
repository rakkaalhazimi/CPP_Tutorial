#include<iostream>
#include<fstream>

#ifdef _WIN32
  #include<windows.h>
#endif

#ifdef linux
  #include<unistd.h>
#endif


int main(int argc, char const *argv[])
{
  
  std::ofstream textFile("sleep.txt", std::ios::app);
  
  return 0;
}
