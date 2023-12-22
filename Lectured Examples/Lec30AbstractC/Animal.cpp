#include "Animal.h"

#include <iostream>
using namespace std;

Animal::Animal() {
    cout << "Creating an Animal" << endl;
    _name = "Animal";
    _height = 1;
    _weight = 1;
}

Animal::~Animal() {
    cout << "Destroying an Animal" << endl;
}

string Animal::getName() {
    return _name;
}

void Animal::setName(const string& N) {
    _name = N;
    return;
}


