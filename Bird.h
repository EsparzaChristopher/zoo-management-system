#include "Animal.h"

// Class for birds, derived from Animal
#ifndef BIRD_H
#define BIRD_H

using namespace std;

class Bird : public Animal {
public:
    // Override makeSound() to provide a bird-specific sound
    void makeSound() const override {
        cout << "Bird Noise!" << endl;
    }

    // Override displayInfo() to display bird-specific information
    void displayInfo() const override {
        cout << "Name: " << name 
             << "\nAge: " << age 
             << "\nSpecies: " << species << endl;
    }

    // Constructor to initialize Bird with name, age, and species
    Bird(string nName, int aAge, string sSpecies)
        : Animal(nName, aAge, sSpecies) {}

    // Destructor
    ~Bird() {}

};

#endif  // BIRD_H
