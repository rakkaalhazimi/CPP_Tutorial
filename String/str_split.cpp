#include <iostream>
#include <sstream>

// A quick way to split strings separated via spaces or line-break.
void simple_tokenizer(std::string s)
{
  std::stringstream ss(s);
  std::string word;
  while (ss >> word)
  {
    std::cout << word << std::endl;
  }
}

// A quick way to split strings separated via any character
// delimiter.
void adv_tokenizer(std::string s, char del)
{
  std::stringstream ss(s);
  std::string word;
  while (!ss.eof())
  {
    std::getline(ss, word, del);
    std::cout << word << std::endl;
  }
}

int main(int argc, char const *argv[])
{

  std::string a = "How do you do!";
  std::string b = "How$do$you$do!";
  // Takes only space separated C++ strings.
  simple_tokenizer(a);
  std::cout << std::endl;
  adv_tokenizer(b, '$');
  std::cout << std::endl;
  return 0;
}
