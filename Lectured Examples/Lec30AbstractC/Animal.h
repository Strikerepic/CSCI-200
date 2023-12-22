#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
    public:
        Animal();
        virtual ~Animal();

        std::string getName();
        void setName(const std::string& N);

        virtual void speak() = 0; // now a pure virual function. & Were not going to provide an implementation 
        //Any child classes must override this function for a valid complile.

    private:
        std::string _name;
        double _height;
        double _weight;

};

#endif