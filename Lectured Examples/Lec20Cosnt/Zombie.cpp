#include "Zombie.h"
#include <iostream>
#include <string>

using namespace std;

Zombie::Zombie( const string N ) {
    _name = N;

}

string Zombie::getName() const {
    return _name;
}

void Zombie::greet ( const Zombie *pOTHER ) const {
    cout << "Hello " << pOTHER->getName() << endl;
    cout << "I am " << this->getName() << endl;
}
