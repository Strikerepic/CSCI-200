/* CLI and Makefiles
 *   Random Numbers
 *   Makefiles
 */

// input/output 
#include <iostream>



// standard library and time
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    //
    // Random Numbers
    //

    // Get intput for the range of values for random numbers
    int min , max;
    cout << "Enter a Min and a Max: ";
    cin >> min >> max;


    // seed the RNG - random number generator
    srand(time(0));
    rand();

    // Generate random numbers 

    cout << "A random number is: " << rand() << endl;
    cout << "A random number is: " << rand() << endl;

    
    // Generate random numbers within a range
    cout << "Random number within the range" << endl;
    double randomNumber = rand() % (max-min+1) + min;
    cout << "Random in range: " << randomNumber << endl;

    return 0;
}