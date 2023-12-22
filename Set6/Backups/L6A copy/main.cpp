#include <iostream>
using namespace std;

#include "test_suite.h"

#include "Array.hpp"
#include "LinkedList.hpp"

int main() {

    int numTestsToRun;
    while(true) {
        cout << "How many tests do you wish to run? (Enter an integer, negative value will run all tests): ";
        cin >> numTestsToRun;
        if(!cin.fail()) break;

        cin.clear();
        char badChar = ' ';
        do { badChar = cin.get(); } while(badChar != '\n');
    }
    if(numTestsToRun < 0) numTestsToRun = 9999;

    if(numTestsToRun > 0) {
        int listType;
        while(true) {
            cout << "Which list do you wish to test? 1 - Array 2 - LinkedList: ";
            cin >> listType;
            if(!cin.fail()) break;

            cin.clear();
            char badChar = ' ';
            do { badChar = cin.get(); } while(badChar != '\n');
        }
        if(listType != 1 && listType != 2) listType = 1;

        IList<int> *pList = nullptr;
        if(listType == 1) pList = new Array<int>();
        else if(listType == 2) pList = new LinkedList<int>();

        cout << "Testing your member functions..." << endl << endl;
        if( run_all_tests(pList, numTestsToRun) ) {
            cout << "ALL TESTS PASSED!" << endl;
        } else {
            cout << "Not all tests are passing, errors remain..." << endl;
        }
    }

    cout << endl << "Running stress tests..." << endl;
    run_stress_tests();
    cout << "...stress tests complete" << endl;

    return 0;
}