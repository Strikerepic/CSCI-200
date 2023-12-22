#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class Array final : public IList<T> {
public:
    Array();
    ~Array();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;

private:
    int _size;
    T* _pArray;
};

//---------------------------------------------------------

template<typename T>
Array<T>::Array() {
    // set size to zero
    _size = 0;
    _pArray = new T[_size];
    // set array to be a nullptr
    _pArray = nullptr;
}

template<typename T>
Array<T>::~Array() {
    // deallocate current array
    delete[] _pArray;
    
}

template<typename T>
int Array<T>::size() const { 
    return _size;
}

template<typename T>
T Array<T>::get(const int POS) const {
    // if POS is out of range, throw std::out_of_range exception
    if(POS >= _size) {
        throw std::out_of_range("To Big");
    }

    if(POS < 0) {
        throw std::out_of_range("To Small");
    }

    if(_size == 0) {
        throw std::out_of_range("No Arr");
    }
    
    // return value at POS within array
    return _pArray[POS];
}

template<typename T>
void Array<T>::set(const int POS, const T VALUE) {
    // if POS is out of range, throw std::out_of_range exception
    if(POS >= _size) {
        throw std::out_of_range("To Big");
    }

    if(POS < 0) {
        throw std::out_of_range("To Small");
    }

    // set VALUE at POS within array   
    if(_size == 0) {
        T *tempArr = new T[1];
        tempArr[1] = VALUE;
        _pArray = tempArr;
    } else {
        _pArray[POS] = VALUE; 
    }

}

template<typename T>
void Array<T>::insert(const int POS, const T VALUE) {
    if(_size == 0) {
        _pArray = new T[1];
    }
    int a = POS;
    // if POS is before zero, clamp to zero
    if(a <= 0) {
        a = 0;
    }
    // if POS is after size, clamp to size
    if(a > _size) {
        a = _size;
    }

    // create new array of size + 1
    T *tempArr = new T[_size+1];

    // copy elements 0 to POS from old array to new array
    for(int i = 0; i < a; i++) {
        tempArr[i] = _pArray[i];
    }
    // set element at POS in new array to VALUE
    tempArr[a] = VALUE;
    // copy elements POS to size from old array to new array
    for(int i = a; i < _size; i++) {
        tempArr[i+1] = _pArray[i];
    }
    // delete old array
    delete _pArray;
    // set old array to be new array
    _pArray = tempArr;
    // increment size
    _size++;

}

template<typename T>
void Array<T>::remove(const int POS) {
    // if array is empty, throw std::out_of_range exception
    if(_size <= 0) {
        throw std::out_of_range("Arr is empty");
    }
    // if POS is before zero, clamp to zero
    int a = POS;
    if(a < 0) {
        a = 0;
    }
    // if POS is after size, clamp to size - 1
    if(a >= _size) {
        a = _size - 1;
    }
    // create new array of size - 1
    T *tempArr = new T[_size-1];
    // copy elements from 0 to POS from old array to  new array
    for(int i = 0; i < a ; i++) {
        tempArr[i] = _pArray[i];
    }
    // copy elements from POS to size - 1 from old array to new array
    for(int i = a; i < _size - 1; i++) {
        tempArr[i] = _pArray[i + 1];
    }
    // delete old array
    delete[] _pArray;
    // set old array to be new array
    _pArray = tempArr;
    // decrement size
    _size--;
}

template<typename T>
T Array<T>::min() const {
    // if array is empty, throw std::out_of_range exception
    if(_size <= 0) {
        throw std::out_of_range("Arr is 0");
    }
    // find minimum value within array
    T min = _pArray[0];
    for(int i = 0; i < _size; i++) {
        if(_pArray[i] < min) {
            min  = _pArray[i];
        }
    }
    
    // return min value
    return min;
}

template<typename T>
T Array<T>::max() const {
    // if array is empty, throw std::out_of_range exception
    if(_size <= 0) {
        throw std::out_of_range("Arr is 0");
    }
    // find maximum value within array
    T max = _pArray[0];
    for(int i = 0; i < _size; i++) {
        if(_pArray[i] > max) {
            max  = _pArray[i];
        }
    }
    // return max value
    return max;
}

template<typename T>
int Array<T>::find(const T VALUE) const {
    if(_size < 0) {
        throw std::out_of_range("Size to small");
    }
    // search for first occurrence of VALUE
    for(int i = 0; i < _size; i++) {
        if(_pArray[i] == VALUE) {
            return i;
        }
    }
    // return index of first occurrence if found
        //Done above
    // otherwise return -1
    return -1;
}

#endif//ARRAY_H