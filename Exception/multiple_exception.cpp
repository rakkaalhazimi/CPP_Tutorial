#include<iostream>


class MathError {
  
  private:
    const char *message;
  
  public:
    MathError(const char *message): message(message) {}
    const char* getMessage() {return message;}
};

int division(int a, int b) 
{
  if (b == 0) 
  {
    // Try one of the throw statements below
    // throw MathError("Division by zero error!");
    throw "Division by zero error!";
  }
  return a / b;
}


int main() {
  
  int x = 1, y = 0;
  
  try 
  {
    int z = division(x, y);
  } 
  catch (const char *msg)
  {
    std::cout << "Message: " << msg << std::endl;
  }
  catch (MathError &error)
  {
    std::cout << "MathError: " << error.getMessage() << std::endl;
  }
  
  
  
  return 0;
}