#include "Conversions.h"


#include <cmath>
#define M_PI 3.14159265358979323846
const double PI = M_PI;
#include <iostream>

using namespace std;


void polar_to_cartesian(double radius, double angle, double* xCoordinate, double* yCoordinate) {
    cout << angle << endl;
    *xCoordinate = radius*cos(angle);
    *yCoordinate = radius*sin(angle);
    return;
}

void cartesian_to_polar(double xCoordinate, double yCoordinate, double* radius, double* angle) {
    *radius = sqrt( pow(xCoordinate,2) + pow(yCoordinate,2));
    if(xCoordinate < 0 && yCoordinate < 0) { // Third quad
        *angle = PI + atan((yCoordinate/xCoordinate));
    } else if (xCoordinate < 0 && yCoordinate == 0) { // On the x-axis between 2 & 3
        *angle = PI;
    } else if (xCoordinate < 0 && yCoordinate >= 0) { // Second quad
        *angle = PI + (atan((yCoordinate/xCoordinate)));
    } else if (xCoordinate == 0 && yCoordinate < 0 ) {
        *angle = PI*3/2;
    } else {
    *angle = atan((yCoordinate/xCoordinate));
    }

}