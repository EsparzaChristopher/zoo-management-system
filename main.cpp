#include "Zoo.h"
#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include "iostream"
#include "string"

using namespace std;

// Global instance of Zoo
Zoo zoo;

// Function to display the user menu and handle user interactions
void userMenu() {
    bool running = true;  // Flag to control the loop
    int num;

    while (running) {
        // Display the user menu options
        cout << "-----User Menu-----\n";
        cout << "(1) Add an animal\n";
        cout << "(2) Remove an animal\n";
        cout << "(3) Display all animals\n";
        cout << "(4) Save animals to file\n";
        cout << "(5) Load animals from file\n";
        cout << "(6) Exit\n";
        cout << "Insert a number to make your decision: ";
        cin >> num;

        // Validate the user's choice
        if (num > 6 || num < 0) {
            cout << "Option not defined.\n";
            continue;  // Skip to the next iteration of the loop
        }

        // Switch statement for different menu options
        switch (num) {
            case 1: {
                // Add an animal
                string name, species;
                int age;
                cout << "Enter animal name: ";
                cin >> name;
                cout << "Enter animal species (Mammal/Bird/Reptile): ";
                cin >> species;
                cout << "Enter animal age: ";
                cin >> age;

                // Create a new animal based on the species
                Animal* newAnimal = nullptr;
                if (species == "Mammal") {
                    newAnimal = new Mammal(name, age, species);
                } else if (species == "Bird") {
                    newAnimal = new Bird(name, age, species);
                } else if (species == "Reptile") {
                    newAnimal = new Reptile(name, age, species);
                } else {
                    cout << "Invalid species! Please try again.\n";
                    break;  // Exit case 1 if invalid species
                }

                // Add the new animal to the zoo
                zoo.addAnimal(newAnimal);
                cout << name << " the " << species << " has been added to the zoo.\n";
                break;  // Exit case 1
            }
            case 2: {
                // Remove an animal by index
                int index;
                cout << "Enter the index of the animal to remove (0 - " << zoo.getNumAnimals() - 1 << "): ";
                cin >> index;

                // Remove the animal from the zoo
                zoo.removeAnimal(index);
                cout << "Animal removed from the zoo.\n";
                break;  // Exit case 2
            }
            case 3: {
                // Display all animals in the zoo
                zoo.displayAnimals();
                break;  // Exit case 3
            }
            case 4: {
                // Save animals to a file
                string filename1;
                cout << "Provide an output file name: ";
                cin >> filename1;
                zoo.saveToFile(filename1);
                break;  // Exit case 4
            }
            case 5: {
                // Load animals from a file
                string filename2;
                cout << "Provide an input file name: ";
                cin >> filename2;
                zoo.loadFromFile(filename2);
                break;  // Exit case 5
            }
            case 6: {
                // Exit the program
                cout << "Exiting the program. Goodbye!\n";
                running = false;  // Set running to false to break the loop
                break;  // Exit case 6
            }
        }
    }
}

int main() {
    // Start the user menu
    userMenu();
    return 0;  // Exit the program
}
