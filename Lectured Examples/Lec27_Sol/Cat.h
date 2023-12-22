#ifndef CAT_H
#define CAT_H

#include "Animal.h"

#include <string>

class Cat : public Animal {
    public:
        Cat();
        ~Cat();

        std::string meow();

    private:

};
#endif