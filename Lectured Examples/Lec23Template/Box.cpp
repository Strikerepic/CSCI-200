// Box.cpp​
#include "Box.h"
template<typename T> //The box itself if now templated so you need to
//Template typename T scope resolution to a Box<T> now
Box<T>::Box(const int SIZE) { 
  _size = SIZE;
  _pContent = nullptr;
  }

template<typename T>
int Box<T>::getBoxSize() const {
  return _size;
}


template<typename T>
void Box<T>::putIn(const T VAL) {
  if(_pContent == nullptr)
    _pContent = new T(VAL);
}



template<typename T>
T Box<T>::takeOut() {
  if( _pContent != nullptr ) {
    T val = *_pContent;
    delete _pContent; _pContent = nullptr; //Stops mem leak
    return val;
  } 
  return T(); //Change RETURN 0 --> to call default constructor 
}


// Still havent set up destructor