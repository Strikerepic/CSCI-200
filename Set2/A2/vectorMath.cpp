#include "vectorMath.h"
#include <cmath>


#define M_PI 3.14159265358979323846
const double PI = M_PI;
#include <iostream>



using namespace std;

void angle_input(float* pAngle) {
    cout << "Enter specified angle in RADIAN DECIMAL FORM: ";
    double userIn = 0;
    cin >> userIn;
    *pAngle = userIn;
    cout << "Angle set to: " << *pAngle << endl;
}

void point_input(float* xCord, float* yCord) {
    cout << "Enter X-Cordinate then Y-Cordinate: ";
    double userInX = 0;
    double userInY = 0;
    cin >> userInX;
    cin >> userInY;

    *xCord = userInX;
    *yCord = userInY;
    cout << "Cordinates set to   X: " << *xCord << " Y: " << *yCord << endl;  
    return;
}

void vector_input(float* vecX, float* vecY){
    cout << "Enter vector-x then vector-y cordinates: ";
    double userInX, userInY;
    cin >> userInX;
    cin >> userInY;
    *vecX = userInX;
    *vecY = userInY;
    cout << "Vector set to: " << "< " << *vecX <<", " << *vecY << ">" << endl;
    return;
}


void polar_to_cartesian(float radius, float angle, float* xCoordinate, float* yCoordinate) {
    cout << angle << endl;
    *xCoordinate = radius*cos(angle);
    *yCoordinate = radius*sin(angle);
    return;
}

void angle_to_vector(float* angleIn, float* vecX, float* vecY) {
    polar_to_cartesian(1, *angleIn,vecX,vecY);        //This shit converts because radius = 1  also = unit circle
}   

void vector_normalize(float* vecX, float* vecY, float* normVecX, float* normVecY){
    double vecMag = sqrt(pow(*vecX,2) + pow(*vecY,2));
    *normVecX = *vecX/vecMag;
    *normVecY = *vecY/vecMag;
    return;
}



void cartesian_to_polar(double xCoordinate, double yCoordinate, double* radius, double* angle) {
    *radius = sqrt( pow(xCoordinate,2) + pow(yCoordinate,2));
    if(xCoordinate < 0 && yCoordinate < 0) { // Third quad
        *angle = PI + atan((yCoordinate/xCoordinate));
    } else if (xCoordinate < 0 && yCoordinate == 0) {
        *angle = PI;
    } else if (xCoordinate < 0 && yCoordinate >= 0) { // Second quad
        *angle = PI + (atan((yCoordinate/xCoordinate)));
    } else if (xCoordinate == 0 && yCoordinate < 0 ) {
        *angle = PI*3/2;
    } else {
    *angle = atan((yCoordinate/xCoordinate));
    }

}


float vector_to_angle(float vecX, float vecY) {
    double* angle = new double;
    double* radius = new double;
    cartesian_to_polar(vecX,vecY,angle,radius);
    delete radius;
    double ang = *angle;
    delete angle;
    return ang;
}

void rotate_point_by_vector(float inputX, float inputY, float vecInX, float vecInY, float* rotatedX, float* rotatedY) {
    *rotatedX = ((inputX * vecInX)-(inputY*vecInY));
    *rotatedY = ((inputX*vecInY) + (inputY*vecInX));
}

