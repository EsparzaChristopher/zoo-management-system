#include <iostream>
#include <string>
using namespace std;
//Abstract class for animals
#ifndef ANIMAL_H
#define ANIMAL_H
class Animal {
public:
virtual void makeSound() const = 0;
virtual void displayInfo() const = 0;
Animal(string nName, int aAge, string sSpecies) : name(nName), age(aAge), species(sSpecies){}
string getName() const {
    return name;
}
string getSpecies() const {
    return species;
}
int getAge(){
    return age;
}
virtual ~Animal() {}
string name, species;
int age;
};
#endif