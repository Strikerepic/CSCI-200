#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Box.h"

#include <ostream>
#include <vector>

/**
 * @brief takes in sized things and puts them into boxes.  stores
 * all the boxes internally
 * 
 */

template <typename T>
class Warehouse {
public:
    /**
     * @brief Construct a new Warehouse object with
     * no boxes by default
     * 
     */
    Warehouse();
    /**
     * @brief puts the item into a Box of given size
     * @param SIZE size of the cube shaped box to store
     */
    void storeInBox(const T thing);
    /**
     * @brief Get the Box object at given position within the list
     * @param BOX_POS position within the list to retrieve
     * @return Box* pointer to the corresponding Box object
     */
    T* getBox(const int BOX_POS) const;
    /**
     * @brief Get the Number Of Boxes object
     * 
     * @return int 
     */
    int getNumberOfBoxes() const;


    /**
     * @brief This will perfrom the deep copy
     * 
     * @param otherW the RHS part of the statment
     * @return Warehouse with the new memory spots
     */
    Warehouse& operator=(const Warehouse& otherW);

    
    /**
     * @brief Construct a new Warehouse object
     * 
     * @param otherWa This the other warehouse object
     */
    Warehouse(Warehouse &otherWa);

    /**
     * @brief Construct a new Warehouse object
     * 
     * @param otherWa This the other warehouse object
     */

    ~Warehouse();

private:
    /**
     * @brief holds a list of pointers to Boxes
     * 
     */
    std::vector<T*>* _pBoxen;
};

template <typename T>
std::ostream& operator<<(std::ostream&, const Warehouse<T>&);

#endif//WAREHOUSE_H


