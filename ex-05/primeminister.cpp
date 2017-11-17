#include <iostream>
#include <string>
using namespace std;

class Primeminister
{
    int age;
	string name;
	
  public:
    Primeminister(string pm_name, int pm_age)
    {
        name = pm_name;
		age = pm_age;
    }
    
	int get_age()
    {
        return age;
    }
	
	void birthday()
    {
        age++;
    }
	
	void make_announcement(string speech){
	  cout << name << " said: " << speech << '\n';
	}
};

void day1(void)
{
  Primeminister *pm_john = new Primeminister("John", 23);
  pm_john->make_announcement("I shall be resigning. Mary will take over!");
  delete pm_john;
}

void day2(void)
{
  Primeminister *pm_mary = new Primeminister("Mary", 64);
  pm_mary->make_announcement("I am your new Prime Minister.");
  delete pm_mary;
}

int main()
{
  day1();
  day2();
}