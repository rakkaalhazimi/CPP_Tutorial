#include<iostream>

class Car {
  
  public:
    void display() {}
  
};

class CoolerCar: public Car {
  
  private:
    const char *name;
    
  public:
    CoolerCar(const char *name): name(name) {}
    void display()
    {
      std::cout << this->name << std::endl;
    }
};


int main() {
  
  // Upcast
  // convert object's type from lower tree to the upper tree
  CoolerCar myCar("cool car");
  Car *upperCar = static_cast<Car*>(&myCar);
  upperCar->display();
  
  // Downcast
  // convert object's type from upper tree to the lower tree
  Car *myOtherCar;
  CoolerCar *lowerCar = static_cast<CoolerCar*>(myOtherCar);
  lowerCar->display();
  
  
  return 0;
}