#include "Animal.h"

// Class for reptiles, derived from Animal
#ifndef REPTILE_H
#define REPTILE_H

using namespace std;

class Reptile : public Animal {
public:
    // Override makeSound() to provide a reptile-specific sound
    void makeSound() const override {
        cout << "Reptile Noise!" << endl;
    }

    // Override displayInfo() to display reptile-specific information
    void displayInfo() const override {
        cout << "Name: " << name 
             << "\nAge: " << age 
             << "\nSpecies: " << species << endl;
    }

    // Constructor to initialize Reptile with name, age, and species
    Reptile(string nName, int aAge, string sSpecies)
        : Animal(nName, aAge, sSpecies) {}

    // Destructor
    ~Reptile() {}

};

#endif  // REPTILE_H
