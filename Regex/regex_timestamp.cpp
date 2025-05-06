#include<iostream>
#include<regex>
#include<string>


int main(int argc, char const *argv[])
{
  std::string sample = "participant-1733216501858.txt";
  std::regex selfRegex("[0-9]{10,13}", std::regex_constants::ECMAScript | std::regex_constants::icase);
  std::smatch match;
  uint64_t timestamp;
  if (std::regex_search(sample, match, selfRegex))
  {
    std::cout << "Found" << std::endl;
    std::cout << match[0] << std::endl;
    timestamp = std::strtoull(match[0].str().c_str(), NULL, 10);
    std::cout << timestamp << std::endl;
  }
  
  
  /* code */
  return 0;
}
