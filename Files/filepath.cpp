#include<iostream>
#include<filesystem>


int main() {
  
  std::filesystem::path path = "rakka.txt";
  std::filesystem::path ext = ".test";
  // std::filesystem::path targetPath = path.replace_extension
  std::filesystem::path target = path;
  
  
  std::cout << path.string() << std::endl;
  std::cout << path << std::endl;
  std::cout << target.replace_extension(ext) << std::endl;
  
  return 0;
}