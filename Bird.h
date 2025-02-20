#include "Animal.h"

#ifndef BIRD_H
#define BIRD_H
using namespace std;
class Bird : public Animal {
public:
void makeSound() const override
{
    cout << "Bird Noise!" << endl;
}
void displayInfo() const override
{
  cout << "Name: "<< name << "\nAge: " << age << "\nSpecies: " << species << endl;
}
Bird(string nName, int aAge, string sSpecies) : Animal(nName,aAge,sSpecies) {}
~Bird(){}
};
#endif