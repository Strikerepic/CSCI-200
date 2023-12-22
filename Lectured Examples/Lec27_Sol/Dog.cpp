#include "Dog.h"
#include <iostream>
using namespace std;

Dog::Dog() {
    cout << "Creating a Dog" << endl;
}

Dog::~Dog(){
    cout << "Destroying a Dog" << endl;
}
        
string Dog::bark() {
    return "Dog:: Woof Woof!";

}