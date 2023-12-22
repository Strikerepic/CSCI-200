#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "IDrawable.h"
#include <string> 

class Dog : public Animal, public IDrawable { //Dog inherits from animal and from IDrawable. Now we need to fix those abstract things
    public:
        Dog();
        ~Dog();
        
        void speak() override;

        void draw() override; // Providing our own implementation (In the cpp)

    private:
        
};
#endif