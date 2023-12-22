
#include "Rhombus.h"
#include "cmath"

using namespace std;



bool Rhombus::validate() {

    double side1 = sqrt(   pow( coordArray[1].x - coordArray[0].x, 2) + pow( coordArray[1].y - coordArray[0].y, 2)     );
    double side2 = sqrt(   pow( coordArray[2].x - coordArray[1].x, 2) + pow( coordArray[2].y - coordArray[1].y, 2)     );
    double side3 = sqrt(   pow( coordArray[3].x - coordArray[2].x, 2) + pow( coordArray[3].y - coordArray[2].y, 2)     );
    double side4 = sqrt(   pow( coordArray[0].x - coordArray[3].x, 2) + pow( coordArray[0].y - coordArray[3].y, 2)     );


    if(side1 == side2 && side2==side3 && side3 == side4) {
        return true;
    }
    return false;


};