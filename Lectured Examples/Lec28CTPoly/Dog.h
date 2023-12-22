#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include <string> 

class Dog : public Animal {
    public:
        Dog();
        ~Dog();
        
        void speak() override; //Using the override keyword after the function to indicate it's being overriden.
        //the OVERIDE KEYWORD is a requirement.

    private:
        
};
#endif