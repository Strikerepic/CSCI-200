#include "Node.hpp"
#include "BinarySearchTree.hpp"
#include <iostream>

using namespace std;

int main() {
    BinarySearchTree<int> theSearch;


    theSearch.insert(10);

    theSearch.insert(1);

    theSearch.insert(20);

    theSearch.printBST(theSearch.getPNode(),0);


    BinarySearchTree<int> theOtherSearch(theSearch);

    theOtherSearch.printBST(theOtherSearch.getPNode(),0);
    cout << "I mean ok";


    theSearch.printInOrder();



    
}