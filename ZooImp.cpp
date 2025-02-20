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
//initialize a zoo
Zoo:: Zoo(){
    numAnimals = 0;
    maxAnimals = 10;
    animals = new Animal*[maxAnimals];
}
//deconstruct a zoo
Zoo :: ~Zoo(){
    for(int i = 0; i < numAnimals; i++){
        delete animals[i];
    }
    delete [] animals;
}
//resize the dynamic array to hold more or less animals.
//This will automatically take place if the animal count
//reaches less than half of the array size or the animal 
//count completely fills the array.
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
    //check if there is space to fit an animal.
    //If not, increase the array size before proceeding
    if(numAnimals == maxAnimals){
        resizeArray();
    }
    //add the animal and increase animal count
    animals[numAnimals] = animal;
    numAnimals++;
}
void Zoo :: removeAnimal(int index){
    //checks if a valid index was provided
    if(index < 0 || index >= maxAnimals){
        cout << "\nInvalid Index\n";
        return;
    }
    // deletes animal
    delete animals[index];
    //moves all animals above provided index back
    for(int i = index; i < numAnimals - 1;i++){
        animals[i] = animals[i+1];
    }
    numAnimals--;
    // if num animals is less than half the array size
    // resize the array
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
    //Essentially provides all info on every animal in the zoo
    if(numAnimals == 0) {
        cout << "\nThere are no animals in the zoo.\n";
    }
    for(int i = 0; i < numAnimals;i++){
        animals[i] -> displayInfo();
    }
}
void Zoo :: saveToFile(string& filename) const{
    ofstream outFile(filename);
    //checks if file exists
    if(!outFile){
        cout << "\nFailed to open file\n";
        return;
    }
    //outputs dynamic array into output file
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
    //checks if file exists
    if(!inFile){
        cout << "\nFailed to open file\n";
        return;
    }
    //takes in all info from an input file
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
    //return the number of animals
    return numAnimals;
}