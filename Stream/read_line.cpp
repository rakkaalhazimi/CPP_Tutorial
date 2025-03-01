#include<iostream>
#include<sstream>
#include<string>


int main() {
    
    // std::string lines = "hello my name is cpp \n I am very happy";
    std::stringstream lines;
    lines << "I am first" << std::endl
          << "Second'o!" << std::endl;
          
    std::string text;
    
    std::getline(lines, text);
    // std::cout << "Your text is: " << text << std::endl;
    std::cout << "Your first line is: " << text << std::endl;
    
    std::getline(lines, text);
    // std::cout << "Your text is: " << text << std::endl;
    std::cout << "Your second line is: " << text << std::endl;
    
    return 0;
}