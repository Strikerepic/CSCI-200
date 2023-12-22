// Lecture 33 - Dyanmic Arrays, Pointer Arithmetic and Growing/Shrinking arrays
#include <iostream>
using namespace std;


int main() {
    // Previously - Variable declared in free store
    double* pMyDub = new double(5.67);      // double in free store set to value of 5.67
    delete pMyDub;                          // don't forget to clean up the memory!
    pMyDub = nullptr;

    // Last lecture - Static Arrays - size must be known at compile time
    int a[] = {0,1,2}; // array size 3 with initial values
    const int NUM_DUBS = 4;
    double b[NUM_DUBS]; // array size 4 with unitialized storage
    cout << "b array with unitialized value: " << b[0] << endl << endl;

    // cout << "Out of range stuffs" << b[1000000] << endl;  //Program just balls out and ends abnormally
    // Dynamic arrays in free store


    int numStudents;
 
    cout << "Number of student grades to enter: ";
    cin >> numStudents;

    int* pCWIDArr = new int[numStudents];
    double* pGradeArr = new double[numStudents]; //These 2 only work because they're on the free store and size is
    //Determined at runtime
    double* pCurrentGrade = pGradeArr; //Set it to the begining of the array

    for(int i = 0; i < numStudents; i++) {
        cout << "Enter CWID & Grade: ";
        cin >> pCWIDArr[i] >> *pCurrentGrade;
        pCurrentGrade++;
        // OR *(pCurrentGrade + i);
    }
    
    // Print the values using array notation and pointer math
    cout << "Student grades" << endl;
    
    // Resize a Dynamic Array
        // 1. Create new array of correct size
        // 2. Copy existing elements to new array

        // 3. Delete existing array
        // 4. Assign pointer of new array to existing array


    // Free up the storage when it is no longer needed

    return 0;
}

