#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
virtual void makeSound() const = 0;
virtual void displayInfo() const = 0;
Animal(string nName, int aAge, string sSpecies)s : name(nName), age(aAge), species(sSpecies){}
virtual ~Animal() {}

private:
string name, species;
int age;
};
