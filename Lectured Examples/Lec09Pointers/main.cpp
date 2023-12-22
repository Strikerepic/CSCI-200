/* CSCI 200: Lecture 09 Function Examples
 *
 * Author: Dr. Jeffrey Paone
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     Class!
 *
 * Starter code used to work through separate function declaration & definition
 */

#include "add_functions.h"

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to the Fancy Five Function Calculator!" << endl;
    
    // prompt the user to enter two numeric values for our calculator
    double *pFirstValue = new double;  // carves out data on the free store enough for a double
    double *pSecondValue = new double;
    cout << "Enter two double values: ";
    cin >> *pFirstValue >> *pSecondValue;  //Defrence the pointer so data is stored the data where its pointing. Not overwritting the pointer memmory address
    double stackFirst = *pFirstValue;
    cout << endl << "The results are...::drum roll::..." << endl << endl;

    // run each equation and display result
    cout << fixed << setprecision(3) << right;
    print_equation(stackFirst, '+', *pSecondValue, add(stackFirst, *pSecondValue));
    print_equation(*pFirstValue, '-', *pSecondValue, sub(*pFirstValue, *pSecondValue));
    print_equation(*pFirstValue, '*', *pSecondValue, mult(*pFirstValue, *pSecondValue));
    print_equation(*pFirstValue, '/', *pSecondValue, div(*pFirstValue, *pSecondValue));
    print_equation(*pFirstValue, '%', *pSecondValue, mod(*pFirstValue, *pSecondValue));

    cout << endl << "Run this program again to do some more math!" << endl;
    return 0;
}
