#include<iostream>
#include<string>


class Waifu 
{
  std::string name;
  
  public: 
    Waifu(std::string name = "test"): name(name) {}
  
  void greet() 
  {
    std::cout << "Hello my name is " << this->name << std::endl;
  }
  
};


int main(int argc, char const *argv[])
{
  
  // 1. Default Constructor
  
  // Automatic Storage Object Duration / Static Initialization
  Waifu lappland;
  // Dynamic Storage Duration / Dynamic Initialization
  Waifu *lappland = new Waifu();
  
  
  // 2. Through Parameterized Constructor
  
  // Static Initialization
  Waifu lappland("lappland");
  Waifu lappland = Waifu("lappland");
  
  // Dynamic Initialization
  Waifu *lappland = new Waifu("lappland");
  
  
  
  // 3. Copy Constructor
  
  // Static Initialization
  Waifu lappland;
  
  Waifu coolerLappland = lappland;
  // or
  Waifu coolerLappland(lappland);
  
  
  // Dynamic Initialization
  Waifu *lappland = new Waifu();
  Waifu *coolerLappland = new Waifu(lappland);
  
  
  return 0;
}
