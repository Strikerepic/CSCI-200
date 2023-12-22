#ifndef BOX_H
#define BOX_H
// Box.h​


template<typename T> //Template the whole fuckin class
//Take out data types THAT YOU WANT and replace with T
class Box {

public: 

    Box(const int SIZE);

    int getBoxSize() const;

    void putIn(const T); //This function must change

    T takeOut(); //This function must change

private: 

    int _size;

    T* _pContent;

};
#endif