#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
    Node* left;
    Node* right;
    T value;


    /**
     * @brief Construct a new Tree Node object
     * 
     * @param pLeft left pointer to next tree node
     * @param pRight  right pointer to next tree node
     */
    Node(Node* pLeft, Node* pRight, T val);

    /**
     * @brief Construct a new Tree Node object
     * 
     * @param val 
     */
    Node(T val);

    /**
     * @brief Construct a new Node object Copy Constructor
     * 
     * @param Other 
     */
    Node(Node* Other);


    /**
     * @brief Construct a new Node object
     * 
     */
    Node();

};


template<typename T>
Node<T>::Node(Node* Other) {
    left = Other->left;
    right = Other->right;
    value = Other->value;

}


template<typename T>
Node<T>::Node(Node* pLeft, Node* pRight, T val) {
    left = pLeft;
    right = pRight;
    value = val;
}

template<typename T>
Node<T>::Node(T val) {
    value = val;
    right = nullptr;
    left = nullptr;
}

template<typename T>
Node<T>::Node() {
    left = nullptr;
    right = nullptr;

}



#endif