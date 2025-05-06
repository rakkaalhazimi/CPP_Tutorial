#include<iostream>
#include<regex>
#include<string>


int main(int argc, char const *argv[])
{
  std::string sample = "Rakka Alhazimi";
  std::regex selfRegex("rakka", std::regex_constants::ECMAScript | std::regex_constants::icase);
  std::smatch match;
  if (std::regex_search(sample, match, selfRegex))
  {
    std::cout << "Found" << std::endl;
    std::cout << match[1] << std::endl;
  }
  
  /* code */
  return 0;
}
