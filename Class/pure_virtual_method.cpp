#include<iostream>


class Car {
  
  public:
    // Tell the compiler that there is no 
    // definition of display().
    //
    // A NULL pointer is then entered in the Virtual Method Table
    // for pure virtual method.
    virtual void display() const = 0; 
};

class CarChild: public Car {
  public:
    void display();
};

void CarChild::display() {
  
}


int main() {
  
  return 0;
}