#include "Dog.h"
#include <iostream>
using namespace std;

Dog::Dog() {
    cout << "Creating a Dog" << endl;
}

Dog::~Dog(){
    cout << "Destroying a Dog" << endl;
}
        
void Dog::speak() {
    cout << "Woof! Woof!" << endl;
} //Nothing special here!