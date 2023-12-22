#include <iostream>
using namespace std;



#include "Array.hpp"
#include "LinkedList.hpp"
#include <limits>

int main(){

    Array<int> *pList = new Array<int>();
    LinkedList<int> *pLL = new LinkedList<int>();

    pList->insert(0,4);
    pList->insert(1,3);
    pList->insert(2,8);
    pList->insert(3,1);
    pList->insert(4,5);
    pList->insert(5,9);
    pList->insert(6,7);
    pList->insert(7,2);
    pList->insert(8,6);


    pLL->insert(0,4);
    pLL->insert(1,3);
    pLL->insert(2,8);
    pLL->insert(3,1);
    pLL->insert(4,5);
    pLL->insert(5,9);
    pLL->insert(6,7);
    pLL->insert(7,2);
    pLL->insert(8,6);

    cout << "Array: " << endl;
    cout << "Unsorted List: " ;
    for(int i = 0; i < pList->size(); i++) {
        cout << pList->get(i) << " ";
    }
    cout << endl;
    pList->sort();
    cout << "Sorted List: " ;
    for(int i = 0; i < pList->size(); i++) {
        cout << pList->get(i) << " ";
    }

    cout<< endl;




    cout << "LL: " << endl;
    cout << "Unsorted List: " ;
    for(int i = 0; i < pLL->size(); i++) {
        cout << pLL->get(i) << " ";
    }
    cout << endl;
    pLL->sort();
    cout << "Sorted List: " ;
    for(int i = 0; i < pLL->size(); i++) {
        cout << pLL->get(i) << " ";
    }


    cout << endl << endl;

    cout << "Which implementation do you want? " << endl << "(1): Binary"<<endl<<"(2): Linear: ";
    int userImpl;

    do {
        std::cin >> userImpl;

        if(std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while(true);


    int numInts = 0;
    int smallest = 0;
    int largest = 0;
    int whatFind = 0;
    cout << "Enter number of ints in random list: ";

    do {
        std::cin >> numInts;

        if(std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while(true);

    cout << "Smallest number in randomly generated range?: ";
    do {
        std::cin >> smallest;

        if(std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while(true);

    cout << "Largest num in the range: ";
    do {
        std::cin >> largest;

        if(std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while(true);


    cout << "What num to search for: ";
    do {
        std::cin >> whatFind;

        if(std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while(true);





    if(userImpl == 1) {
        Array<int> yes;
        for(int i = 0; i < numInts; i++) {
            yes.insert(i, (rand()%(largest-smallest+1)+smallest)   );
        }

        cout << "Unsorted: " << endl;
        for(int i = 0; i < numInts; i++) {
            cout << yes.get(i) << " ";
        }
        cout << "Sorted: " << endl;
        yes.sort();
        for(int i = 0; i < numInts; i++) {
            cout << yes.get(i) << " ";
        }
        cout << "Found @ " << yes.search(whatFind);

    } else if (userImpl == 2) {
        LinkedList<int> yes;
        for(int i = 0; i < numInts; i++) {
            yes.insert(i, (rand()%(largest-smallest+1)+smallest)   );
        }

        cout << "Unsorted: " << endl;
        for(int i = 0; i < numInts; i++) {
            cout << yes.get(i) << " ";
        }
        cout << "Sorted: " << endl;
        yes.sort();
        for(int i = 0; i < numInts; i++) {
            cout << yes.get(i) << " ";
        }

        cout << "Found @ " << yes.search(whatFind);

    } else {
        cout << "You entered an option that doesn't work. Goodbye";
        return -1;
    }



    









    return 0;
}