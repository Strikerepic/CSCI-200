#include "Dog.h"
#include "Cat.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    Animal john;
    john.setName("John");
    cout << john.getName() << " says ..." << endl;
    
    Dog odie;
    odie.setName("Odie");
    cout << odie.getName() << " says " << odie.bark() << endl;

    Cat garfield;
    garfield.setName("Garfield");
    cout << garfield.getName() << " says " << garfield.meow() << endl;
    return 0;
}