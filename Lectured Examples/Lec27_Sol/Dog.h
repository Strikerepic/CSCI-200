#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include <string> 

class Dog : public Animal {
    public:
        Dog();
        ~Dog();
        
        std::string bark();

    private:
        
};
#endif