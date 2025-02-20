#include "Animal.h"
//class for reptiles
#ifndef REPTILE_H
#define REPTILE_H
using namespace std;
class Reptile : public Animal {
public:
void makeSound() const override
{
    cout << "Reptile Noise!" << endl;
}
void displayInfo() const override
{
  cout << "Name: "<< name << "\nAge: " << age << "\nSpecies: " << species << endl;
}
Reptile(string nName, int aAge, string sSpecies) : Animal(nName,aAge,sSpecies) {}
~Reptile(){}
};
#endif