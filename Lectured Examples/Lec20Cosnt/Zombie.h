#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
    public:
        Zombie( const std::string N );
        std::string getName() const;
        void greet( const Zombie * pOTHER ) const;

    private:
        std::string _name;
};

#endif
