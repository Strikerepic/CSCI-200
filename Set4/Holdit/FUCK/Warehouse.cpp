#include "Warehouse.h"
#include <iostream>

using namespace std;

template<typename T>
Warehouse<T>::Warehouse() {
    _pBoxen = new vector<T*>;
}


template<typename T>
void Warehouse<T>::storeInBox(const T thing) {
    _pBoxen->push_back( new T(thing) );
}

template<typename T>
T* Warehouse<T>::getBox(const int BOX_POS) const {
    return _pBoxen->at(BOX_POS);
}

template<typename T>
int Warehouse<T>::getNumberOfBoxes() const {
    return _pBoxen->size();
}

template<typename T>
std::ostream& operator<<(ostream& os, const Warehouse<T>& WH) {
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




template<typename T>
Warehouse<T>& Warehouse<T>::operator= (const Warehouse<T>& OTHERW) {
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



template<typename T>
Warehouse<T>::Warehouse(Warehouse<T>& otherWa) {

    _pBoxen = new vector<Box*>(otherWa.getNumberOfBoxes()); // Set _pBoxen's size to be the same otherWa to reduce time-C.

    for(int i =0 ; i < otherWa.getNumberOfBoxes(); i++ ) {
        Box *a = new Box(otherWa.getBox(i)->getBoxSize());
        _pBoxen->at(i) = a;
    }

}


template<typename T>
Warehouse<T>::~Warehouse() {
    for(int i = 0; i < this->getNumberOfBoxes(); i++ ) {
        delete _pBoxen->at(i);
    }
    delete _pBoxen;
}


