#include<iostream>
#include<filesystem>
#include<string>


int main() {
  
  std::filesystem::path DIRECTORY{"dir"};
  std::string volume = "12345";
  std::string filename = "test.txt";
  // std::filesystem::path targetPath = path.replace_extension
  std::filesystem::path filepath = DIRECTORY / volume / filename;
  std::string name = filepath.filename();
  
  
  std::cout << filepath.string() << std::endl;
  std::cout << name << std::endl;
  
  return 0;
}