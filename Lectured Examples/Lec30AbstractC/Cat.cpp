#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat() {
    cout << "Creating a Cat" << endl;
}

Cat::~Cat(){
    cout << "Destroying a Cat" << endl;
}

void Cat::speak() {
    cout << "Meow Meow!" << endl;
}