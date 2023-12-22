#include "Box.hpp" //Now must include the .hpp file


#include <iostream>

using namespace std;

int main() { 

    // Create a Box
    Box<int> b1(1); //Where you actually plug in the data type everything else should work the same without issue
    b1.putIn(1);
    cout << "Box b1 has size " << b1.getBoxSize() << endl;
    cout << "Taking out of box b1:  " << b1.takeOut() << endl;
    cout << "After removing box b1: " << b1.takeOut() << endl;

    return 0;
} 

//If you complie with just .h .cpp main.cpp it wont work


