#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat() {
    cout << "Creating a Cat" << endl;
}

Cat::~Cat(){
    cout << "Destroying a Cat" << endl;
}

        
string Cat::meow() {
    return "Cat:: Meow Meow!";
}