#include "IsoscelesTriangle.h"
#include "cmath"
using namespace std;
#include <iostream>




bool IsoscelesTriangle::validate() {
    bool flagError = true;


    if(numVert > 3) {
        flagError = false;
        return flagError;
    }

    double side1 = sqrt(   pow( coordArray[1].x - coordArray[0].x, 2) + pow( coordArray[1].y - coordArray[0].y, 2)     );
    double side2 = sqrt(   pow( coordArray[2].x - coordArray[1].x, 2) + pow( coordArray[2].y - coordArray[1].y, 2)     );
    double side3 = sqrt(   pow( coordArray[2].x - coordArray[0].x, 2) + pow( coordArray[2].y - coordArray[0].y, 2)     );



    //Check if not zero
    if(side1 == 0 || side2 == 0 || side3 == 0) {
        flagError = false;
    }


    //Triangle Ineq Therom
    if(!(side1 + side2 > side3)) {
        flagError = false;
    }
    if(!(side2 + side3 > side1)) {
        flagError = false;
    }
    if(!(side3 + side1 > side2)) {
        flagError = false;
    }


    //Check If Isosceles

    double THRESHOLD = 0.00000000003;

        // if ((fabs(side1 - side2) < THRESHOLD && fabs(side2 - side3) > THRESHOLD) ||
        // (fabs(side1 - side3) < THRESHOLD && fabs(side3 - side2) > THRESHOLD) ||
        // (fabs(side2 - side3) < THRESHOLD && fabs(side3 - side1) > THRESHOLD)) {
        //     } else {
        //         flagError = false;
        //     }


    if ((fabs(side1 - side2) < THRESHOLD) && (fabs(side2 - side3) > THRESHOLD)) {
        // Is ISO
    } else if ( (fabs(side1 - side3) < THRESHOLD) && (fabs(side1 - side2) > THRESHOLD)  ) {
        // Is ISO
    } else if (  (fabs(side2 - side3) < THRESHOLD) && (side2 != side1) ) {
        // Is ISO
    } else {
        // IS NOT ISO
        flagError = false;
    }




    return flagError;

}
