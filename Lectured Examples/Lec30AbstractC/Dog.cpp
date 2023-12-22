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
    cout << "Woof Woof!" << endl;
 }




 void Dog::draw() {
    cout << "Draw a cartoon dog. The implementation would go here" << endl;
 }