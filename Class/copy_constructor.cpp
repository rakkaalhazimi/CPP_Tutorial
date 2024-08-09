#include<iostream>


class Account {
  private:
    const char *name;
    int age;
  public:
    Account(const char *name, int age): name(name), age(age) {}
    const char* getName() {
      return this->name;
    }
};


int main() {
  
  Account tenyom("Tenyom", 3);
  // Constructor method
  Account tenyomCopyConstructor(tenyom);
  // Assignment method
  Account tenyomCopyAssignment = tenyom;
  
  std::cout << "Tenyom name: " << tenyom.getName() << std::endl;
  std::cout << "Copy Constructor tenyom name: " << tenyomCopyConstructor.getName() << std::endl;
  std::cout << "Copy Assignment tenyom name: " << tenyomCopyAssignment.getName() << std::endl;
  
  return 0;
}