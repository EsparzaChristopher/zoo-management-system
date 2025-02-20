#include "Zoo.h"
#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include "iostream"
#include "string"
using namespace std;
Zoo zoo;
void userMenu(){
    bool running = true;
    int num;
    while(running) {
        //this allows the user to pick an option
        //they will then be able to execute the option
        //by providing the necessary info
    cout << "-----User Menu-----\n";
    cout << "(1) Add an animal\n";
    cout << "(2) Remove an animal\n";
    cout << "(3) Display all animals\n";
    cout << "(4) Save animals to file\n";
    cout << "(5) Load animals from file\n";
    cout << "(6) Exit\n";
    cout << "Insert a number to make your decision: ";
    cin >> num;
    if(num > 6 || num < 0){
        cout << "Option not defined.\n";
        return;
    }
switch (num) {
    case 1: {
    string name, species;
    int age;
    cout << "Enter animal name: ";
    cin >> name;
    cout << "Enter animal species (Mammal/Bird/Reptile): ";
    cin >> species;
    cout << "Enter animal age: ";
    cin >> age;
    Animal* newAnimal = nullptr;
    if (species == "Mammal") {
        newAnimal = new Mammal(name, age, species);
    } else if (species == "Bird") {
        newAnimal = new Bird(name, age, species);
    } else if (species == "Reptile") {
        newAnimal = new Reptile(name, age, species);
    } else {
        cout << "Invalid species! Please try again.\n";
        break;
    }
    zoo.addAnimal(newAnimal);
    cout << name << " the " << species << " has been added to the zoo.\n";
    break;
}
case 2: {
    int index;
    cout << "Enter the index of the animal to remove (0 - " << zoo.getNumAnimals() - 1 << "): ";
    cin >> index;
    zoo.removeAnimal(index);
    cout << "Animal removed from the zoo.\n";
    break;
}
case 3: {
    zoo.displayAnimals();
    break;
}
case 4: {
    string filename1;
    cout << "Provide an output file name: ";
    cin >> filename1;
    zoo.saveToFile(filename1);
    break;
}
case 5: {
    string filename2;
    cout << "Provide an input file name: ";
    cin >> filename2;
    zoo.loadFromFile(filename2);
    break;
}
case 6: {
    cout << "Exiting the program. Goodbye!\n";
    running = false;
    break;
}
}
    }
}
int main(){
    userMenu();
    return 0;
}