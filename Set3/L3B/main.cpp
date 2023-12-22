/* CSCI 200: Strings Test Suite
 *
 * Author: Christian Brennan
 *
 * Description:
 *    A breif dive and learning the string API for strings in c++.
 *    introduces "unit testing" as a mechanism for exploring the string API.
 * 
 *    Help reviced: Google, Stack-Overflow, and the C++ docs for the string API.
 * 
 */


#include <iostream>

#include "test_suite.h"

int main() {

    std::cout << "Testing your functions..." << std::endl << std::endl;
    if( run_all_tests() ) {
        std::cout << "ALL TESTS PASSED!" << std::endl;
    } else {
        std::cout << "Not all tests are passing, errors remain..." << std::endl;
    }

    return 0;
}