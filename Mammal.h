#include "Animal.h"

#ifndef MAMMAL_H
#define MAMMAL_H
using namespace std;
class Mammal : public Animal {
public:
void makeSound() const override;
void displayInfo() const override;
Mammal(string nName, int aAge, string sSpecies) : Animal(string nName, int aAge, string sSpecies) {}

Animal** Animals;
~Mammal(){}
private:
int maxAnimals, numAnimals;



};
#endif