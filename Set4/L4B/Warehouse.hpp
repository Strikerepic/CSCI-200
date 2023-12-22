#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Box.h"

#include <ostream>
#include <vector>

/**
 * @brief takes in things and puts them into a list.  stores all the items internally
 */

template <typename T>
class Warehouse {
public:
    /**
     * @brief Construct a new Warehouse object with no items by default
     */
    Warehouse();
    /**
     * @brief Don't allow a Warehouse to be copied
     */
    Warehouse(const Warehouse&) = delete;
    /**
     * @brief Don't allow a Warehouse to be copied
     */
    Warehouse& operator=(const Warehouse&) = delete;
    /**
     * @brief Destroy the Warehouse object
     */
    ~Warehouse();

    /**
     * @brief puts the item into the warhouse
     * @param ITEM item to store
     */
    void store(const T ITEM);

    /**
     * @brief Get the item at given position with the warehouse
     * @param ITEM_POS position to retrieve
     * @return Box& corresponding item
     */
    T& retrieve(const size_t ITEM_POS) const;

    /**
     * @brief Get the Number Of items
     * @return int 
     */
    size_t getNumberOfItems() const;
private:
    /**
     * @brief holds a list of pointers to Boxes
     * 
     */
    std::vector<T*>* _pItems;
};

template <typename T>
std::ostream& operator<<(std::ostream&, const Warehouse<T>&);



template<typename T>
Warehouse<T>::Warehouse() {
    _pItems = new std::vector<T*>;
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


#endif//WAREHOUSE_H