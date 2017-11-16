#include <iostream>
#include <string>

using namespace std;

class Animal{
  protected:
    string name;

  public:
    
    void set_name(string name_param)
    { 
      name=name_param;
    }

    virtual string get_animal_name()
    { 
      return name;
    }

    virtual void make_noise() = 0;
};

class Dog: public Animal {
  public:
    void make_noise()
    {
      cout << "The " << name <<" goes Woof Woof" << '\n';  		
	}
};

class Bird: public Animal {
  public:
    void make_noise()
    {
      cout << "The " << name <<" goes Cheep Cheep" << '\n';  		
	}
};

int main () {
  Dog dog;
  Bird bird;
  
  Animal *animal1 = &dog;
  Animal *animal2 = &bird;
  
  animal1->set_name("Dog");
  animal2->set_name("Bird");
 
  animal1->make_noise();
  animal2->make_noise();
  
  return 0;
}