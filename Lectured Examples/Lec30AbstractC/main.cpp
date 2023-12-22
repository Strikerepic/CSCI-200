#include "Dog.h"
#include "Cat.h"
#include <string>
#include <iostream> 
#include <vector>

using namespace std;

// int add(int x, int y) {return x+y;}

int main() {

    // cout << "3+4=" << add(3,4) << endl;
    // cout << (void*)add << endl;
    // int (*pfMyFunc)(int, int) = &add;
    // cout << "2+3= " << (*pfMyFunc)(2,3) << endl;

         //Animal* john = new Animal(); 
        // john->setName("John");
        // cout << john->getName() << " says ";
        // john->speak();
        /*
            John has a virtual function meaning that we cannot create an object of type animal
            only the child classes exist, and they must override it in their implemntaiton.

            
        */
    Dog odie;
    odie.setName("Odie");
    odie.draw(); 


    // cout << odie.getName() << " says ";
    // odie.speak();

    Cat garfield;
    garfield.setName("Garfield");
    // cout << garfield.getName() << " says ";
    // garfield.speak();

    vector<Animal*> zoo = vector<Animal*>(2);
    zoo.at(0) = &odie;
    zoo.at(1) = &garfield;
    //zoo.at(0)->draw();
    //Doesnt work becuase zoo.at(0) returns Animal not dog, which does not have the IDrawable 
    //Not avaliable polymorphicly

    for (size_t i = 0; i < zoo.size(); i++) {
        cout << zoo.at(i)->getName() << " says ";
        zoo.at(i)->speak();

    }

     //delete john;
    // john = nullptr;

    return 0;
}