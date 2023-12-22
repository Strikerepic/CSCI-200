
#include "ScaleneTriangle.h"
#include "cmath"


using namespace std;



bool ScaleneTriangle::validate() {
    bool flagError = false;


    if(numVert > 3) {
        flagError = false;
        return true;
    }

    double distZtoO = sqrt(   pow( coordArray[1].x - coordArray[0].x, 2) + pow( coordArray[1].y - coordArray[0].y, 2)     );
    double distOtoT = sqrt(   pow( coordArray[2].x - coordArray[1].x, 2) + pow( coordArray[2].y - coordArray[1].y, 2)     );
    double distTto0 = sqrt(   pow( coordArray[2].x - coordArray[0].x, 2) + pow( coordArray[2].y - coordArray[0].y, 2)     );



    //Check if not zero
    if(distZtoO == 0 || distOtoT == 0 || distTto0 == 0) {
        flagError = false;
    }



    //Check triangle Inequality Theorem
    if(distZtoO + distOtoT > distTto0) {
    } else {
        flagError = false;
    }
    if(distOtoT + distTto0 > distZtoO) {
    } else {
        flagError = false;
    }
    if(distTto0 + distZtoO > distOtoT) {
    } else {
        flagError = false;
    }
    //Check If Scalene
    if(distZtoO == distOtoT || distZtoO == distTto0) {
        flagError = false;
    }
    if(distOtoT == distTto0 || distOtoT == distZtoO) {
        flagError = false;
    }
    if(distTto0 == distZtoO || distTto0 == distOtoT) {
        flagError = false;
    }

    return flagError;

}