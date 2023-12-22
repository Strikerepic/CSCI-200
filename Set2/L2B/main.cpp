/* CSCI 200: Pointers: Addresses & Values
 *
 * Author: Christian Brennan
 *
 * Description:
 *  The goal of this lab is to gain familiarity with using the
 *  concepts of pointers and addresses. Complete the following 
 *  steps inside your main(). This lab will only be working with
 *  pointers on the stack.
 * 
 *  Help reviced: Stack-overflow and google
 *
 */

#include <cstdlib>      // for rand(), srand()
#include <ctime>        // for time()
#include <iostream>     // for cout, cin, endl etc.
using namespace std;


int main() {
    //1-8
    int iNum1 = 4, iNum2 = 5;

    int* pINum1 = nullptr;
    int* pINum2 = nullptr;

    pINum1 = &iNum1;

    pINum2 = &iNum2;

    cout << "Printing the address of iNum1 twice using different ways: Using the pointer addy: " << pINum1 << " Now the direct addy of iNum1" << &iNum1 << endl; 

    cout << "Printing the address of iNum2 twice using different ways: Using the pointer addy: " << pINum2 << " Now the direct addy of iNum1" << &iNum2 << endl; 

    cout << "Printing the value of iNum1 by using the pointer: " << *pINum1 << endl;

    cout << "Printing the value of iNum2 by using the pointer: " << *pINum2 << endl;

    //9-11
    iNum1 = 6;
    cout << "iNum1 is " << iNum1 << endl;
    cout << "iNum1 using pointer is " << *pINum1 << endl;

    //12-13
    *pINum1 = 7;
    cout << "iNum1 after derefenced pointer changed val " << iNum1 << endl;

    //14-19
    pINum2 = pINum1;
    cout << "Addy of pINum2" << pINum2 << endl;
    cout << "Val of pINum2" << *pINum2 << endl;

    *pINum2 = 8;

    cout << "Print using pINum1 " << *pINum1 << endl;
    cout << "Print using pInum2 " << *pINum2 << endl;
    cout << "Print using iNum1" << iNum1 << endl;

    cout << "Printing iNum2 " << iNum2 << endl;

    //20-27

    double* pDNum = nullptr;
    // pDNum = &iNum1;
    // The error message that i get is that you cannot convert assignment to int* (Int pointer) to double* (Double pointer)
    //pINum1 = pDNum;'
    // The error message states that I cannot convert type double pointer to type int pointer. Cannot convert

    double dNum = 14.25;
    pDNum = &dNum;

    cout << "Address of dNum is: " << pDNum << " Value of pDNum is " << *pDNum << endl;

    *pDNum = *pINum1; //Says it works

    cout << "Value of dnum using dNum " << dNum << " Now using pDNum " << *pDNum << endl;






    return 0;
}