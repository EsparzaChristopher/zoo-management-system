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
Zoo:: Zoo(){
    numAnimals = 0;
    maxAnimals = 10;
    animals = new Animal*[maxAnimals];
}
Zoo :: ~Zoo(){
    for(int i = 0; i < numAnimals; i++){
        delete animals[i];
    }
    delete [] animals;
}
void Zoo :: resizeArray(){
    maxAnimals *= 2;
    Animal** newArray = new Animal*[maxAnimals];
    for(int i = 0; i < numAnimals; i++){
        newArray[i] = animals[i];
    }
    delete [] animals;
    animals = newArray;

}
void Zoo :: addAnimal(Animal* animal){
    if(numAnimals == maxAnimals){
        resizeArray();
    }
    animals[numAnimals] = animal;
    numAnimals++;
}
void Zoo :: removeAnimal(int index){
    if(index < 0 || index >= maxAnimals){
        cout << "\nInvalid Index\n";
        return;
    }
    delete animals[index];
    for(int i = index; i < numAnimals - 1;i++){
        animals[i] = animals[i+1];
    }
    numAnimals--;
    if(numAnimals < maxAnimals/2){
        maxAnimals /= 2;
        Animal** newArray = new Animal*[maxAnimals];
        for(int i = 0; i < numAnimals;i++){
            newArray[i] = animals[i];
        }
        delete [] animals;
        animals = newArray;
    }
    
    
}
void Zoo :: displayAnimals() const {
    if(numAnimals == 0) {
        cout << "\nThere are no animals in the zoo.\n";
    }
    for(int i = 0; i < numAnimals;i++){
        animals[i] -> displayInfo();
    }
}
void Zoo :: saveToFile(string& filename) const{
    ofstream outFile(filename);
    if(!outFile){
        cout << "\nFailed to open file\n";
        return;
    }
    for(int i = 0; i < numAnimals;i++){
        outFile << animals[i]-> getSpecies() << "\n";
        outFile << animals[i]-> getName() << "\n";
        outFile << animals[i]-> getAge() << "\n";
    }
    outFile.close();
    cout << "\nZoo data saved to file.\n";

}
void Zoo :: loadFromFile(string& filename){
    ifstream inFile(filename);
    if(!inFile){
        cout << "\nFailed to open file\n";
        return;
    }
    int age;
    string species, name;
    while(getline(inFile, species) && getline(inFile, name) && inFile >> age){
        inFile.ignore();
        Animal* newAnimal = nullptr;
        if(species == "Mammal"){
            newAnimal = new Mammal(name, age, species);
        }
        if(species == "Reptile"){
            newAnimal = new Reptile(name, age, species);
        }
        if(species == "Bird"){
            newAnimal = new Bird(name, age, species);
        }
        if(newAnimal){
            addAnimal(newAnimal);
        }
    }
    inFile.close();
    cout << "\nData loaded from file.\n";
}
int Zoo :: getNumAnimals() const{
    return numAnimals;
}