#include "Mammal.h"
#include "Reptile.h"
#include "Bird.h"
#include "Animal.h"

#ifndef ZOO_H
#define ZOO_H
class  Zoo{
public:
Zoo();
~Zoo();
 void addAnimal(Animal* animal);
 void removeAnimal(int index); 
 void displayAnimals() const;
 void saveToFile(string& filename) const;
 void loadFromFile(string& filename);
 int getNumAnimals() const;
 private:
Animal** animals;
int numAnimals, maxAnimals;
void resizeArray();
};
#endif