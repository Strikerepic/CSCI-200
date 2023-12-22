#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class LinkedList final : public IList<T> {
public:
    LinkedList();
    ~LinkedList();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;

private: 
    struct Node {
        T value;
        Node* pNext;
        Node* pPrev;
    };

    Node* _pHead;
    Node* _pTail;
    int _size;
};

//---------------------------------------------------------

template<typename T>
LinkedList<T>::LinkedList() {
  // set size to zero
  _size = 0;
  // set head to be a nullptr
  _pHead = nullptr;
  // set tail to be a nullptr
  _pTail = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    // remove each node in the list
    Node *current = _pHead;
    
    while(current != nullptr) {
        Node* toDel = current;
        current = current->pNext;
        delete toDel;
    }
    
}

template<typename T>
int LinkedList<T>::size() const {
    return _size;
}




template<typename T>
T LinkedList<T>::get(const int POS) const {
    // if POS is out of range, throw std::out_of_range exception
    if(POS >= _size) {
        throw std::out_of_range("Postion is greater than the size");
    }
    if(POS < 0 ) {
        throw std::out_of_range("Postion is less than 0");
    }

    // set current node to head
    Node* current = _pHead;
    int counter = 0;
    // advance current node to POS
    while(counter < POS && current->pNext != nullptr) {
        counter++;
        current = current->pNext;
    }
    // return value of current node
    return current->value;
}

template<typename T>
void LinkedList<T>::set(const int POS, const T VALUE) {
  // if POS is out of range, throw std::out_of_range exception
    if(POS >= _size) {
        throw std::out_of_range("Postion is greater than the size");
    }

    if(POS < 0) {
        throw std::out_of_range("Postion is less than 0");
    }

    if(_pHead == nullptr) {
        throw std::out_of_range("Head is null");
    }

    
  // set current node to head
    Node* current = _pHead;
    int counter = 0;

  // advance current node to POS
    while (counter < POS && current->pNext != nullptr) {
        counter++;
        current = current->pNext;
    }
    current->value = VALUE;
  // set value of current node   
  
}

template<typename T>
void LinkedList<T>::insert(const int POS, const T VALUE) {
    // clamp newPos between 0 and _size
    int newPos = std::max(0, std::min(POS, _size));

    // create pointer to new node
    Node *theNewOne = new Node;
    // set value to be VALUE
    theNewOne->value = VALUE;
    // set previous pointer to nullptr
    theNewOne->pPrev = nullptr;
    // set next pointer to nullptr
    theNewOne->pNext = nullptr;

    // if list is currently empty
    if (_size == 0) {
        // set head and tail to new node
        _pHead = theNewOne;
        _pTail = theNewOne;
    } else {
        // if position is before head
        if (newPos == 0) {
            // set new node next to be head
            theNewOne->pNext = _pHead;
            // set head previous to be new node
            _pHead->pPrev = theNewOne;
            // set head to be new node
            _pHead = theNewOne;
        } else if (newPos == _size) {  // position is after tail
            // set new node previous to be tail
            theNewOne->pPrev = _pTail;
            // set tail next to be new node
            _pTail->pNext = theNewOne;
            // set tail to be new node
            _pTail = theNewOne;
        } else {
            // set current node to head
            Node *current = _pHead;
            // advance current node to pos
            for (int i = 0; i < newPos; i++) {
                current = current->pNext;
            }
            // link new node into current list
            theNewOne->pNext = current;
            theNewOne->pPrev = current->pPrev;
            current->pPrev = theNewOne;

            // If the new node is not inserted at the beginning, update the previous node's next pointer.
            if (theNewOne->pPrev != nullptr) {
                theNewOne->pPrev->pNext = theNewOne;
            }
        }
    }
    // increment size
    _size++;
}

template<typename T>
void LinkedList<T>::remove(const int POS) {
    // Clamp newPos between 0 and _size-1
    int otherPos = std::max(0, std::min(POS, _size - 1));

    // If the list is empty, throw an exception
    if (_size == 0) {
        throw std::out_of_range("Position is greater than the size");
    }

    // If the list has one element
    if (_size == 1) {
        // Set node to delete to head
        Node *toDelPointer = _pHead;
        // Set head and tail to be nullptr
        _pHead = nullptr;
        _pTail = nullptr;
        delete toDelPointer;
    } else {
        // If deleting head
        if (otherPos == 0) {
            // Set node to delete to head
            Node *toDelHead = _pHead;
            // Advance head to next
            _pHead = _pHead->pNext;
            // If the new head exists, set its previous to nullptr
            if (_pHead != nullptr) {
                _pHead->pPrev = nullptr;
            }
            delete toDelHead;
        } else if (otherPos == _size - 1) {  // If deleting tail
            // Set node to delete to tail
            Node *toDelTail = _pTail;
            // Step tail to previous
            _pTail = _pTail->pPrev;
            // Set tail next to nullptr
            _pTail->pNext = nullptr;
            delete toDelTail;
        } else{  // If deleting in the middle
            // Set current node to head
            Node *currentNode = _pHead;
            int counter = 0;
            // Advance current node to the position
            while(counter < otherPos-1 && currentNode != nullptr) {
                counter++;
                currentNode = currentNode->pNext;
            }
            // Set node to delete to the current node's next
            Node *nodeToDel = currentNode->pNext;
            currentNode->pNext = currentNode->pNext->pNext;
            currentNode->pNext->pPrev = currentNode;

            delete nodeToDel;
        }
    }

    // Decrement size
    _size--;
}

template<typename T>
T LinkedList<T>::min() const {
    // if list is empty, throw std::out_of_range exception
    if (_size == 0) {
        throw std::out_of_range("List size is 0");
    }

    Node *current = _pHead;
    T min = _pHead->value;

    // find minimum value within list
    while (current != nullptr) {
        if (current->value < min) {
            min = current->value;
        }
        current = current->pNext;
    }

    // return min value
    return min;
}

template<typename T>
T LinkedList<T>::max() const {
    // if list is empty, throw std::out_of_range exception
    if (_size == 0) {
        throw std::out_of_range("List size is 0");
    }

    Node *current = _pHead;
    T max = _pHead->value;

    // find maximum value within list
    while (current != nullptr) {
        if (current->value > max) {
            max = current->value;
        }
        current = current->pNext;
    }

    // return max value
    return max;
}



template<typename T>
int LinkedList<T>::find(const T VALUE) const {
    // search for first occurrence of VALUE
    
    // return index of first occurrence if found
    Node *current = _pHead;
    int counter = 0;

    while (current != nullptr) {

        if (current->value == VALUE) {
            return counter;  // Return the node if found
        }
        current = current->pNext;
        counter++;
    }
    
    // otherwise return -1
    return -1;
}

#endif//LINKED_LIST_H
