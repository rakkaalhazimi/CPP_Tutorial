#include<iostream>
#include<string>


int main() {
    
    std::string header = "Please enter your text to be reversed.",
                lines(50, '_');
    std::string userInput, line;
    
    std::cout << header << std::endl
              << lines << std::endl;
    
    while (true)
    {
      std::getline(std::cin, line);
      if (line.length() == 0)
      {
        break;
      }
      userInput = line + '\n' + userInput;
    }
    std::cout << "Your text is: " << std::endl
              << userInput << std::endl;
    
    return 0;
}