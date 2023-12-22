/* Lecture 16 - Collections
 * Vectors - STL templated list
 * Strings - list of characters
 */

#include <iostream>
// Add includes for the collections being used in your 
#include <vector>
#include <string>




using namespace std;

const int CLASS_SIZE = 5;

int main() {
    cout << "Collections - Vectors and Strings \n\n";

    // Declare a vector specifying the data type for the list
    vector<bool> truefalse;

    vector<int> classCWIDs(CLASS_SIZE);
    vector<double> classScores(CLASS_SIZE, 100.0);
    // Delcare a string / Declare and initialize a string

    // Declare and initialize a vector, size is CLASS_SIZE and all are set to the same value


    int cwid;
    string name;
    for (int i = 0; i < CLASS_SIZE; i++) {
        // Get CWID
        cout << "Enter CWID: ";
        cin >> cwid;

        // Get first name
        cout << "Enter First Name: ";
        cin >> name;

        // add elements to back of list and grow the list

        classCWIDs.push_back(cwid);

        // Set the element at a position

    }

    // Display CWIDs and Grades
    for (int i = 0; i < CLASS_SIZE; i++) {
        cout << "CWID: " << classCWIDs.at(i) << " Name: " << " grade is " << classScores.at(i) <<  endl;
    }

    // Element access is protected -- Access element 9


    return 0;
}