
#include "ScaleneTriangle.h"
#include "cmath"
#include <iostream>


using namespace std;



bool ScaleneTriangle::validate() {
    bool flagError = true;

    if(numVert > 3) {
        flagError = false;
        return flagError;
    }

    double distZtoO = sqrt(   pow( coordArray[1].x - coordArray[0].x, 2) + pow( coordArray[1].y - coordArray[0].y, 2)     );
    double distOtoT = sqrt(   pow( coordArray[2].x - coordArray[1].x, 2) + pow( coordArray[2].y - coordArray[1].y, 2)     );
    double distTto0 = sqrt(   pow( coordArray[2].x - coordArray[0].x, 2) + pow( coordArray[2].y - coordArray[0].y, 2)     );

   //  cout << distZtoO;

    //Check if not zero
    if(distZtoO == 0 || distOtoT == 0 || distTto0 == 0) {
        flagError = false;
        // cout << "Dist Zero Error";
    }



    //Check triangle Inequality Theorem
    if(!(distZtoO + distOtoT > distTto0)) {
        flagError = false;
        // cout << "Tri Ineq Error 1";
    }
    if(!(distOtoT + distTto0 > distZtoO)) {
        flagError = false;
        // cout << "Tri Ineq Error 2";
    }
    if(!(distTto0 + distZtoO > distOtoT)) {
        flagError = false;
        // cout << "Tri Ineq Error 3";
    }


    double THRESHOLD = 0.001;
    //Check If Scalene
    if (fabs(distZtoO - distOtoT) < THRESHOLD || fabs(distZtoO - distTto0) < THRESHOLD) {
        flagError = false;
        // cout << "Tri Scal check 1" << endl;
    }

    if (fabs(distOtoT - distTto0) < THRESHOLD || fabs(distOtoT - distZtoO) < THRESHOLD) {
        flagError = false;
        // cout << "Tri Scal check 2" << endl;
    }

    if (fabs(distTto0 - distZtoO) < THRESHOLD || fabs(distTto0 - distOtoT) < THRESHOLD) {
        flagError = false;
        // cout << "Tri Scal check 3" << endl;
    }

    return flagError;

}