#include "Warehouse.h"
template<typename T>
Warehouse<T>::Warehouse() {
    _pItems = new std::vector<Box*>;
}
template <typename T>
Warehouse<T>::~Warehouse() {
    while( !_pItems->empty() ) {
        delete _pItems->back();
        _pItems->pop_back();
    }
    delete _pItems;
}
template <typename T>
void Warehouse<T>::store(const T ITEM) {
    _pItems->push_back( new T(ITEM) );
}
template<typename T>
T& Warehouse<T>::retrieve(const size_t ITEM_POS) const {
    return *(_pItems->at(ITEM_POS));
}
template <typename T>
size_t Warehouse<T>::getNumberOfItems() const {
    return _pItems->size();
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const Warehouse<T>& WH) {
    const size_t NUM_ITEMS = WH.getNumberOfItems();
    os << "Warehouse has " << NUM_ITEMS << " items (";
    for(size_t i = 0; i < NUM_ITEMS; i++) {
        os << WH.retrieve(i);
        if(i < NUM_ITEMS - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}