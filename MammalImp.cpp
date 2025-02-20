#include "Mammal.h"
using namespace std;
void Mammal :: makeSound() const override 
{
    cout << "Mammal Noise!" << endl;
}
void Mammal :: displayInfo() const override
{
    cout<< "Name: " << endl;
}