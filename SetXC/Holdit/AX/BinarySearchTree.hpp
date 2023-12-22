#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iomanip>
#include <iostream>
#include <stack>

#include "Node.hpp"

template<typename T>
class BinarySearchTree {
    public:
    /**
     * @brief Constructor that sets the root pointer to be null and set the size to be zero
     * 
     */
    BinarySearchTree();


    /**
     * @brief Copy Constructor that performs a deep copy of the other tree
     * 
     */
    BinarySearchTree(const BinarySearchTree& OTHER);

    /**
     * @brief Destructor that deallocates the entire tree, sets the root pointer to be null, sets the size to be zero
     * 
     */
    ~BinarySearchTree();


    /**
     * @brief Copy Assignment Operator that deallocates the existent tree (if any) then performs a deep copy of the other tree
     * 
     */
    BinarySearchTree& operator=(const BinarySearchTree& OTHER);



    /**
     * @brief inserts a node for the given VAL. If VAL is less than the root, recursively attempt to add to the left subtree. 
     * 
     * @param VAL  If VAL is greater or equal to the root, recursively attempt to add to the right subtree. Increments the size by one. (Note: We are not going to be implementing the balanced binary search tree.)
     */
    void insert(const T VAL);



    /**
     * @brief returns the current total number of nodes in the tree
     * 
     * @return int size of tree
     */
    int size() const;

    /**
     * @brief Recursively print the left subtree, then print the current node, then recursively print the right subtree.
     * 
     */
    void printInOrder();


    /**
     * @brief Create a New Node object
     * 
     * @param Data 
     * @return Node* 
     */
    Node<T>* createNewNode(T Data);
    void printBST(Node<T>* root, int depth = 0);
    Node<T>* getPNode();

    private:
    Node<T>* _pNodeRoot;
    int _size;

};

template<typename T>
Node<T>* BinarySearchTree<T>::getPNode() {
    return _pNodeRoot;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
    _pNodeRoot = nullptr;
    _size = 0;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
Node<T>* current = _pNodeRoot;
    std::stack<Node<T>*> stack;
    while(current != nullptr || !stack.empty()) {
        while(current != nullptr) {
        stack.push(current);
        current = current->left;
    }
    
    current = stack.top();
    stack.pop();

    Node<T>* temp =  current->right;

    delete current;

    current = temp;

    }
    _pNodeRoot = nullptr;
}




template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& OTHER) {
    if(OTHER._pNodeRoot == nullptr) {
        return;
    }

    _pNodeRoot =  new Node<T>(OTHER._pNodeRoot);

    _pNodeRoot->left = new Node<T>(OTHER._pNodeRoot->left);
    _pNodeRoot->right = new Node<T>(OTHER._pNodeRoot->right);

}


template<typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree& OTHER) {
    Node<T>* current = _pNodeRoot;
    std::stack<Node<T>*> stack;
    while(current != nullptr || !stack.empty()) {
        while(current != nullptr) {
        stack.push(current);
        current = current->left;
    }
    
    current = stack.top();
    stack.pop();

    Node<T>* temp =  current->right;

    delete current;

    current = temp;

    }
    _pNodeRoot = nullptr;





    _pNodeRoot =  new Node<T>(OTHER._pNodeRoot);

    _pNodeRoot->left = new Node<T>(OTHER._pNodeRoot->left);
    _pNodeRoot->right = new Node<T>(OTHER._pNodeRoot->right);


}

template<typename T>
void BinarySearchTree<T>::insert(const T VAL) {
    if(_pNodeRoot == nullptr) {
        _pNodeRoot = new Node<T>(VAL);
    } else {
        Node<T>* temp = _pNodeRoot;
        while(temp != nullptr) {
            if( (VAL <= temp->value) && (temp->left == nullptr)) { //Checks if the value is less than and node's left is null. Meaning that it will be insereted there on the left
                temp->left = new Node<T>(VAL);
                break;
            } else if(VAL <= temp->value) {  // Checks to move left. Not nullptr checked above
                temp = temp->left;
            } else if ( (VAL > temp->value) && (temp->right == nullptr)) {
                temp->right = new Node<T>(VAL);
                break;
            } else {
                temp = temp->right;
            }
        }
    }
    _size++;

}

template<typename T>
void BinarySearchTree<T>::printBST(Node<T>* root, int depth) {
const int INDENTATION = 4; // Number of spaces for each level of indentation

    if (root == nullptr) {
        return;
    }

    // In-order traversal with indentation
    printBST(root->right, depth + 1);

    for (int i = 0; i < depth * INDENTATION; ++i) {
        std::cout << " ";
    }

    std::cout << root->value << std::endl;

    printBST(root->left, depth + 1);
}


template<typename T>
void BinarySearchTree<T>::printInOrder() {
    
}






#endif