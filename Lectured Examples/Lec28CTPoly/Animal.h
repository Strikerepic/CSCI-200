#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
    public:
        Animal();
        ~Animal();

        std::string getName();
        void setName(const std::string& N);
        virtual void speak(); //Virtual means that your planing to override it in the future.
        // Technically all fuctions are virtual by default. But it's good practice becuase we are being explicit becase we know
        // We are going to override speak

    private:
        std::string _name;
        double _height;
        double _weight;

};

#endif