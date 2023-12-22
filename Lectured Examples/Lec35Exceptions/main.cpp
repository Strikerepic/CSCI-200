#include <iostream>
#include <vector>
#include <stdexcept>  // THE STANDARD

using namespace std;

void badArray();
void tryCatch();
void throwException(int i);

int main() {

    // 1. Accessing elements outside of an array -- undefined results
   // badArray();

    // 2. Do bounds checking in your code and throw an exeption.
    throwException(1);
    cout << "After the throw Exception with valid position" << endl;
    throwException(100);
    cout << "After the throw Exception with out of range position" << endl;

    // 3. Using try/catch to catch exceptions and add your own message
    // tryCatch();

    // 4. Using try/catch in the main to catch an exception thrown by a function
    // while (true) {
    //     try {
    //         cout << "Enter value to get: ";
    //         int x;
    //         cin >> x;
    //         throwException(x); // valid values 0-4
    //         cout << "Good Choice!" << endl;
    //         break;
    //     } catch (out_of_range oore) {  // throwException will throw oore if out of range
    //         cout << "Oops out of range, try again" << endl;
    //     } 
    // }
    return 0;
}

void throwException(int i) {
    // Check for bounds in your code and throw an exception
    vector<int> v = {0,1,2,3,4};

    // Check the input value to see if it is out of range
    if ( i < 0 || i >= (int)v.size()) {
        string msg = "Error in throwException accessing element " + to_string(i) +
                     " and size of vector is " + to_string(v.size());
        throw out_of_range(msg);
    } else {
        cout << "Success! " << v.at(i) << endl;
    }

    return;
}

void tryCatch() {
    // Try and catch an exception
    vector<int> myVec = {0,1,2,3,4}; // has 5 elements​

    try {
        // Loop through the values in the vector in a try/catch block
        for (unsigned int i = 0; i <= myVec.size(); i++) {
            cout << "Element is " << myVec.at(i) << endl;;
        }
    } catch(...) {
        cout << "Error handled processing myVec" << endl;
    }

    return;
}

void badArray() {
    int var1 = 999, var2 = 999;
    int array[10];

    cout << &var1 << " " << var1 << endl; 
    cout << &var2 << " " << var2 << endl; 
    cout << array << endl;                

    // Change the loopEnd variable to 15 or 10000 and see the results
    int loopStart = -100000000000, loopEnd = 12;
    for(int i = loopStart; i <= loopEnd; i++) {
        array[i] = i;
        cout << &array[i] << " " << array[i] << endl;
    }
    cout << "Exited the for loop" << endl;
    cout << "var1 should be 999 and is: " << var1 << endl;                 
    cout << "var2 should be 999 and is: " << var2 << endl; 

    return;
}