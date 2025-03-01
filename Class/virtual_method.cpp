#include<iostream>


class Car {
  
  public:
    virtual void display() const {}
};


class CoolerCar: public Car {
  
  private:
    const char *name;
  
  public:
    CoolerCar(const char* name): name(name) {}
    void display() const {
      std::cout << this->name << std::endl;
    }
};

int main() {
  
  CoolerCar myCoolCar("cool");
  myCoolCar.display();
  
  return 0;
}