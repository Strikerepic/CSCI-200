/* Debugging
 * Compiler errors
 * cout
 * DEBUG compiler directive
 * gdb
 */
#include <iostream>
using namespace std;

int main() {
    // Variables
    char ans = 'n';
    int fact=0, prod=1;

    // Arithmetic Errors  
    cout << "Factorials!" << endl;  
    cout << "Factorial of " << fact << " is " << prod << endl;
    cout << "Calculate the factorial of a number: ";
    cin >> fact;
    for (int i = 1; i < fact; i++) {
        // Multiply i into the product and increment
        prod = prod * i;
        cout << i << "  " << prod << endl;
    }
    cout << fact << "! is equal to " << prod << endl;

    // Looping errors
    // Keeping looping until we get there!
    cout << "Let's play 'Are we there yet' !" << endl;
    while (ans != 'y'); {
        cout << "Are we there yet (y/n)? ";
        cin >> ans;
    }

    return 0;
}
