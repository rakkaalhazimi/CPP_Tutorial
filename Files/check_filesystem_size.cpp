#include<iostream>
#include<filesystem>


int main() {
  
  
  std::string filename = "check_filesystem_size.cpp";
  // Check if .pcm file is empty
  std::uintmax_t filesize = std::filesystem::file_size(filename);
  
  std::cout << "File size:" << filesize << std::endl;
        
  if (filesize == 0) {
    std::cout << "File is empty" << std::endl;
  }
  
  return 0;
}