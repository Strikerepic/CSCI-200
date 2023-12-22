#ifndef CAT_H
#define CAT_H

#include "Animal.h"

#include <string>

class Cat : public Animal {
    public:
        Cat();
        ~Cat();

        void speak() override;

    private:

};
#endif