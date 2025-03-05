#include "Mammal.h"
#include "Reptile.h"
#include "Bird.h"
#include "Animal.h"

#ifndef ZOO_H
#define ZOO_H

// Class for Zoo to store and manage all animals
class Zoo {
public:
    // Constructor to initialize the zoo with no animals
    Zoo();

    // Destructor to clean up dynamically allocated memory for animals
    ~Zoo();

    // Add an animal to the zoo
    void addAnimal(Animal* animal);

    // Remove an animal by index
    void removeAnimal(int index);

    // Display all animals in the zoo
    void displayAnimals() const;

    // Save the zoo's animals to a file
    void saveToFile(string& filename) const;

    // Load animals from a file into the zoo
    void loadFromFile(string& filename);

    // Get the current number of animals in the zoo
    int getNumAnimals() const;

private:
    // Dynamic array to hold pointers to Animal objects
    Animal** animals;

    // Number of animals currently in the zoo
    int numAnimals;

    // Maximum capacity of the animal array
    int maxAnimals;

    // Resize the array when more space is needed
    void resizeArray();
};

#endif  // ZOO_H
