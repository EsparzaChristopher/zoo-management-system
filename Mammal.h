#include "Animal.h"

#ifndef MAMMAL_H
#define MAMMAL_H

// Class for mammals, derived from Animal
using namespace std;

class Mammal : public Animal {
public:
    // Override makeSound() to provide a mammal-specific sound
    void makeSound() const override {
        cout << "Mammal Noise!" << endl;
    }

    // Override displayInfo() to display mammal-specific information
    void displayInfo() const override {
        cout << "Name: " << name 
             << "\nAge: " << age 
             << "\nSpecies: " << species << endl;
    }

    // Constructor to initialize Mammal with name, age, and species
    Mammal(string nName, int aAge, string sSpecies)
        : Animal(nName, aAge, sSpecies) {}

    // Destructor
    ~Mammal() {}

};

#endif  // MAMMAL_H
