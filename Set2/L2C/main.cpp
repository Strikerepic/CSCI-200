/* CSCI 200: Pass-by-Value & Pass-by-Pointer

 *
 * Author: Christian Brennan
 * 
 * Description: This code will take in cordinates polar or regular x-y
 * determined by the user. The code will then convert from either to polar
 * if starting with xy or go to xy if starting with polar.
 *
 * Help reviced: Stack-overflow and google
 */

#include <cstdlib>      // for rand(), srand()
#include <cmath>      //For math ya know beacuse you need it for trig stuff. Why am I even still typing this I should prob work on the code now
#define M_PI 3.14159265358979323846
#include <iostream>     // for cout, cin, endl etc.
#include "Conversions.h"

const double pi = M_PI;

using namespace std;

void cartesian_to_polar(double xCoordinate, double yCoordinate, double* radius, double* angle);
void polar_to_cartesian(double radius, double angle, double* xCoordinate, double* yCoordinate);



int main() {


    cout << "Type p if you have polar cordinates and wish to convert them to cartesian style." << endl << "Type anything else to convert from cartesian to polar. Enter choice: ";
    char option = 'a';
    double in1, in2;
    double* newCord1 = new double;
    double* newCord2 = new double;
    cin >> option;
    if(option == 'p'){
        cout << "Type radius then angle measure (In Radians & In decimal form): ";
        cin >> in1 >> in2;
        polar_to_cartesian(in1,in2,newCord1,newCord2);
        cout << "X: " << *newCord1 << endl << "Y:" << *newCord2 << endl;  
    } else {
        cout << "Type X-Cordinate then Y-Cordinate: ";
        cin >> in1 >> in2;
        cartesian_to_polar(in1,in2,newCord1,newCord2);
        cout << "Radius: " << *newCord1 << endl << "Angle (Radians): " << *newCord2 << endl;
    }



}
