/* CSCI 200: Complex Vector Math!
 *
 * Author: Christian Brennan
 *
 * Description:
 *    This program will rotate a point using complex numbers. It will take in
 *    either an angle and a point  or a vector and a point and rotate the point
 *    accordingly.
 * 
 *    Help reviced: Stack-overflow and google
 * 
 */

#include <cmath>       // maths
#include <iostream>     // for cout, cin, endl etc.
#include "vectorMath.h"  //Functions in vector_math.cpp this includes the header for the function protos.
using namespace std;


int main () {
    float* cordInX = new float; //Any inputed
    float* cordInY = new float; //Any inputed

    float* angleIn = new float; // any ins float;

    float* vecInX = new float; // More code that does stuff. IDK I'm tired I dont want to comment this part
    float* vecInY = new float;

    float* vecInXNorm = new float; //More stuff that does things
    float* vecInYNorm = new float; //Another vectory quant. to hold the normalized vector.


    float* thePointX = new float;  //This is THE point. The one after all the rotations
    float* thePointY = new float;

    char userIn = ' ';
   
    

while(userIn != 'q') {
    cout << "1: Enter Point" << endl << "2: Rotate point by angle" << endl << "3: Rotate point by vector" << endl << "q: Quit" << endl;
    cout << "Menu option: ";
    cin >> userIn;
    if(userIn == '1') {
        point_input(cordInX,cordInY);
    } else if (userIn == '2') {
        angle_input(angleIn);
        cout << *angleIn << endl;
        angle_to_vector(angleIn,vecInX,vecInY);


        vector_normalize(vecInX,vecInY,vecInXNorm,vecInYNorm);


        rotate_point_by_vector(*cordInX,*cordInY,*vecInXNorm,*vecInYNorm,thePointX,thePointY);


        *cordInX = *thePointX;
        *cordInY = *thePointY;


    } else if (userIn == '3') {
        vector_input(vecInX,vecInY);
        vector_normalize(vecInX,vecInY,vecInXNorm,vecInYNorm);
        rotate_point_by_vector(*cordInX,*cordInY,*vecInXNorm,*vecInYNorm,thePointX,thePointY);

        *cordInX = *thePointX;
        *cordInY = *thePointY;
    } else if (userIn == 'q') {
        break;
    } else {
        cout << endl << "Ay I'm not in the mood today pal. Thats NOT ONE OF THE OPTIONS!" << endl << endl;
    }

    cout << "The current location of the point is now at (" << *cordInX << ", " << *cordInY << ")" << endl;


}
cout << "Cheese is just a loaf of milk. Goodbye!" << endl;


return 0;
}
