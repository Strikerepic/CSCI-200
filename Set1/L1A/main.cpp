/* CSCI 200: Lab L1A: Engineering Equations in C++ 
 *
 * Author: Christian Brennan
 *
 * Simply just implementing some equations in C++. We will prompt the user for
 * any non constant variables and solve using the equations that have been
 * implemented.
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath>


using namespace std;

// Define any constants below this comment.

const double pi = 3.14159265;
/*
* Equations To Implement:
* Ohms Law: I = V / R or V = IR
* Volume of a sphere : V = (4/3) * pi * r^3
*/


// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/

    cout << "Solving for current in Ohms Law:" << endl << "Enter the voltage: ";
    double volts = 0.0;  // Setup for getting the voltage. Same thing is done for resistance as well.
    cin >> volts;
    cout << "Enter the resistance: ";
    double resist = 0.0;
    cin >> resist;
    double current = volts / resist;
    cout << "The current is: " << current << endl;

    // Next is the volume of a sphere

    cout << "Solving for the volume of sphere:" << endl << "Enter the radius of the sphere:";
    double radius = 0.0;  // Sets up for taking in the value of the radius, that happens on the next line.
    cin >> radius;  
    double volume = (4.0/3) * pi * pow(radius,3);
    cout << "The volume of the sphere is: " << volume << endl;

  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}