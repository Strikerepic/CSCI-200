#include "Warehouse.h"
#include <iostream>

using namespace std;


Warehouse::Warehouse() {
    _pBoxen = new vector<Box*>;
}

void Warehouse::storeInBox(const int SIZE) {
    _pBoxen->push_back( new Box(SIZE) );
}

Box* Warehouse::getBox(const int BOX_POS) const {
    return _pBoxen->at(BOX_POS);
}

int Warehouse::getNumberOfBoxes() const {
    return _pBoxen->size();
}

std::ostream& operator<<(ostream& os, const Warehouse& WH) {
    os << "Warehouse has " << WH.getNumberOfBoxes() << " boxes (";
    for(int i = 0; i < WH.getNumberOfBoxes(); i++) {
        os << WH.getBox(i)->getBoxSize();
        if(i < WH.getNumberOfBoxes() - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}





Warehouse& Warehouse::operator= (const Warehouse& OTHERW) {
    if (this == &OTHERW) {return *this; }

    for(int i = 0; i < this->getNumberOfBoxes(); i++ ) {
        delete _pBoxen->at(i);
    }

    _pBoxen->clear();


    for(int i = 0; i < OTHERW.getNumberOfBoxes(); i++) {
        this->storeInBox( OTHERW.getBox(i)->getBoxSize());
    }
    return *this;
}




Warehouse::Warehouse(Warehouse& otherWa) {

    _pBoxen = new vector<Box*>(otherWa.getNumberOfBoxes()); // Set _pBoxen's size to be the same otherWa to reduce time-C.

    for(int i =0 ; i < otherWa.getNumberOfBoxes(); i++ ) {
        Box *a = new Box(otherWa.getBox(i)->getBoxSize());
        _pBoxen->at(i) = a;
    }

}



Warehouse::~Warehouse() {
    for(int i = 0; i < this->getNumberOfBoxes(); i++ ) {
        delete _pBoxen->at(i);
    }
    delete _pBoxen;
}

















