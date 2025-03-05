#include <iostream>
#include <string>
using namespace std;

// Abstract class for animals
#ifndef ANIMAL_H
#define ANIMAL_H

// Base class Animal
class Animal {
public:
    // Pure virtual function to make sound, to be implemented by derived classes
    virtual void makeSound() const = 0;

    // Pure virtual function to display information, to be implemented by derived classes
    virtual void displayInfo() const = 0;

    // Constructor to initialize name, age, and species
    Animal(string nName, int aAge, string sSpecies)
        : name(nName), age(aAge), species(sSpecies) {}

    // Getter for the name of the animal
    string getName() const {
        return name;
    }

    // Getter for the species of the animal
    string getSpecies() const {
        return species;
    }

    // Getter for the age of the animal
    int getAge() {
        return age;
    }

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Animal() {}

protected:
    // Member variables: name, species, and age
    string name, species;
    int age;
};

#endif  // ANIMAL_H
