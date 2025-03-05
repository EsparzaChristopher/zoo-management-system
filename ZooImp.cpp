#include "Mammal.h"
#include "Reptile.h"
#include "Bird.h"
#include "Animal.h"
#include "Zoo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Constructor for initializing a zoo
Zoo::Zoo() {
    numAnimals = 0;        // Initial number of animals is 0
    maxAnimals = 10;       // Set initial maximum capacity of animals to 10
    animals = new Animal*[maxAnimals];  // Dynamically allocate memory for the animals array
}

// Destructor for cleaning up the zoo
Zoo::~Zoo() {
    // Delete each individual animal in the zoo
    for(int i = 0; i < numAnimals; i++) {
        delete animals[i];
    }
    // Deallocate the animals array
    delete [] animals;
}

// Resize the array to accommodate more or fewer animals as needed
// Automatically doubles the size if the zoo is full, or halves it when there's more space than needed
void Zoo::resizeArray() {
    maxAnimals *= 2;  // Double the capacity of the zoo
    Animal** newArray = new Animal*[maxAnimals];  // Create a new array with the larger size

    // Copy the animals from the old array to the new array
    for(int i = 0; i < numAnimals; i++) {
        newArray[i] = animals[i];
    }

    // Clean up the old animals array
    delete [] animals;

    // Point the `animals` pointer to the new array
    animals = newArray;
}

// Add a new animal to the zoo
void Zoo::addAnimal(Animal* animal) {
    // Check if there is space for a new animal
    // If there is no space, resize the array
    if(numAnimals == maxAnimals) {
        resizeArray();
    }
    
    // Add the new animal to the array and increment the animal count
    animals[numAnimals] = animal;
    numAnimals++;
}

// Remove an animal by index from the zoo
void Zoo::removeAnimal(int index) {
    // Check if the index is valid
    if(index < 0 || index >= numAnimals) {
        cout << "\nInvalid Index\n";
        return;
    }

    // Delete the animal at the specified index
    delete animals[index];

    // Shift all animals after the removed one to fill the gap
    for(int i = index; i < numAnimals - 1; i++) {
        animals[i] = animals[i+1];
    }

    // Decrease the number of animals in the zoo
    numAnimals--;

    // If the number of animals is less than half the array size, shrink the array
    if(numAnimals < maxAnimals / 2) {
        maxAnimals /= 2;
        Animal** newArray = new Animal*[maxAnimals];

        // Copy the remaining animals to the new array
        for(int i = 0; i < numAnimals; i++) {
            newArray[i] = animals[i];
        }

        // Deallocate the old array
        delete [] animals;

        // Point to the new array
        animals = newArray;
    }
}

// Display information for all animals in the zoo
void Zoo::displayAnimals() const {
    // Check if there are no animals
    if(numAnimals == 0) {
        cout << "\nThere are no animals in the zoo.\n";
    }

    // Loop through all animals and display their information
    for(int i = 0; i < numAnimals; i++) {
        animals[i]->displayInfo();  // Call the displayInfo method of each animal
    }
}

// Save the zoo's animal data to a file
void Zoo::saveToFile(string& filename) const {
    ofstream outFile(filename);  // Open the output file

    // Check if the file opened successfully
    if(!outFile) {
        cout << "\nFailed to open file\n";
        return;
    }

    // Write each animal's species, name, and age to the file
    for(int i = 0; i < numAnimals; i++) {
        outFile << animals[i]->getSpecies() << "\n";  // Write species
        outFile << animals[i]->getName() << "\n";     // Write name
        outFile << animals[i]->getAge() << "\n";      // Write age
    }

    outFile.close();  // Close the file
    cout << "\nZoo data saved to file.\n";
}

// Load the zoo's animal data from a file
void Zoo::loadFromFile(string& filename) {
    ifstream inFile(filename);  // Open the input file

    // Check if the file opened successfully
    if(!inFile) {
        cout << "\nFailed to open file\n";
        return;
    }

    // Read animal data from the file and create corresponding animal objects
    int age;
    string species, name;

    // Read species, name, and age for each animal from the file
    while(getline(inFile, species) && getline(inFile, name) && inFile >> age) {
        inFile.ignore();  // Skip the newline character after reading age

        Animal* newAnimal = nullptr;

        // Create an animal object based on the species read from the file
        if(species == "Mammal") {
            newAnimal = new Mammal(name, age, species);
        } else if(species == "Reptile") {
            newAnimal = new Reptile(name, age, species);
        } else if(species == "Bird") {
            newAnimal = new Bird(name, age, species);
        }

        // If the animal was created successfully, add it to the zoo
        if(newAnimal) {
            addAnimal(newAnimal);
        }
    }

    inFile.close();  // Close the file
    cout << "\nData loaded from file.\n";
}

// Get the current number of animals in the zoo
int Zoo::getNumAnimals() const {
    return numAnimals;  // Return the number of animals in the zoo
}
