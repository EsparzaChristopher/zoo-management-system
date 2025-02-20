Project Title: Zoo Management System (Using Dynamic Arrays)
Objective:
Students will build a Zoo Management System using C++ that demonstrates:

Pointers and Dynamic Memory Management – Using new and delete for object creation and deletion.
Classes and Inheritance – Base class Animal and derived classes like Mammal, Bird, and Reptile.
Virtual Functions and Polymorphism – Overriding functions to display different behaviors for different animal types.
Abstract Classes – Making Animal an abstract class with at least one pure virtual function.
File I/O – Saving and loading animals from a file.
Dynamic Arrays – Manually handling memory allocation for an expandable array of Animal*.
Project Requirements
1. Class Design
Abstract Base Class: Animal
Attributes: name, age, species
Pure virtual functions:
virtual void makeSound() const = 0;
virtual void displayInfo() const = 0;
 
Derived Classes: Mammal, Bird, Reptile
Implement unique makeSound() behaviors.
2. Dynamic Array for Storage
Use a dynamically allocated array (Animal** animals) to store animals.
Maintain a count (numAnimals) and capacity (maxAnimals).
Implement a resize function to expand the array when needed.
3. File I/O
Save the list of animals to a file (zoo_data.txt).
Load existing data on startup.
4. User Menu
1. Add an animal
2. Remove an animal
3. Display all animals
4. Save animals to file
5. Load animals from file
6. Exit
Implementation Plan
Files Needed
Animal.h – Abstract class
Mammal.h / Bird.h / Reptile.h – Derived classes
Zoo.h – Manages dynamic array of Animal*
main.cpp – User menu and file operations
Rubric (100 Points)
Criteria

Description

Points

Class Design

Inheritance, virtual functions, and abstract class implementation

20

Dynamic Memory Management

Proper use of new and delete without leaks

20

Polymorphism

Overridden methods work correctly

15

Dynamic Array Management

Expandable array for animals, correct resizing

15

File I/O

Implements saving and loading

15

Code Quality

Follows best practices, well-commented

10

User Interface

Functional menu system

5

Stretch Goals (Extra Credit)
Allow searching for animals by name.
Implement sorting animals alphabetically.
Add a feature where animals “roam” and “make sounds” at random intervals.