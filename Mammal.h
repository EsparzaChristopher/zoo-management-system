#include "Animal.h"

#ifndef MAMMAL_H
#define MAMMAL_H
//class for mammals
using namespace std;
class Mammal : public Animal {
public:
void makeSound() const override
{
    cout << "Mammal Noise!" << endl;
}
void displayInfo() const override
{
  cout << "Name: "<< name << "\nAge: " << age << "\nSpecies: " << species << endl;
}
Mammal(string nName, int aAge, string sSpecies) : Animal(nName,aAge,sSpecies) {}
~Mammal(){}
};
#endif