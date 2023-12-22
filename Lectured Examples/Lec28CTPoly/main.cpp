#include "Dog.h"
#include "Cat.h"
#include <string>
#include <iostream>

using namespace std;

//Boom function
int add(int x, int y) {
    return x+y;
}

int main() {

    cout << "3+4 = " << add(3,4) << endl;
    cout << (void*)add << "Returns the address of the function" << endl;


    int (*pfMyFunction)(int,int) = &add;


    cout << "2+3 = " << (*pfMyFunction)(2,3) << endl; //De-Refrenced Explicic function call
    cout << "1+2 = " << pfMyFunction(1,2) << endl; // Implicit function call. Auto de-ref.

    //By doing this impicit or explicit call we are able to prevent a deadly diamond of death problem
    // by saying I only want this function called rather than it figureing it out
    // And running into an error trying to find which function it want to call 





    Animal john;
    john.setName("John");
    cout << john.getName() << " says";
    john.speak();
    
    Dog odie;
    odie.setName("Odie");
    cout << odie.getName() << " says ";
    odie.speak();  

    Cat garfield;
    garfield.setName("Garfield");
    cout << garfield.getName() << " says " << garfield.meow() << endl;
    return 0;
}