/* Iteration - Loops
 *   Postfix/Prefix operators
 *   While loops
 *   Do-While loops
 *   For loops
 *   Scope
 */

#include <iostream>
using namespace std;

int main() {

    // postfix and prefix operators
    int x = 1;
    int y = 0;
    y = x++;
    cout << "x = " << x << "  y = " << y << endl;
    y = ++x;
    cout << "x = " << x << "  y = " << y << endl;

    // // While loop
    // // choice is the variable that controls the loop
    // char choice = ' '; // initial value is a blank
    // while (choice != 'x' && choice != 'X') { // stopping condition is x or X
    //     cout << "Enter a letter: ";
    //     cin >> choice;  // loop body reads choice input from keyboard
    // }
    
    // // Do while loop
    // int sensorInput = 0;
    // int mask = 17;  //10001
    // do {
    //     cout << "Enter sensor input: ";
    //     cin >> sensorInput;
    //     cout << (sensorInput & mask) << endl;
    // } while( (sensorInput & mask) != mask);
    // cout << "Sensor 0 and 4 are turned on" << endl;

    // // For loop
    // int val = 0, factorial = 1;
    // cout << "Let's calculate a factorial" << endl;
    // cout << "Factorial of what number? ";
    // cin >> val;
    // for (int i = 1;  i<=val; i++) {
    //     factorial *= i;
    // }
    // // val and factorial are declared outside the loop {} so still in scope
    // cout << val << "! is " << factorial << endl;
    // i is scoped to the for loop and is out of scope now
    // cout << i << endl; 
    
    return 0;
}