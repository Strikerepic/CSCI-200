#include "Zombie.h"
#include <iostream>

using namespace std;

const float* generatePiPrecision(const int NUM_DECIMALS) {
    if(NUM_DECIMALS == 0) {
        return new float(3.f);
    } else if(NUM_DECIMALS == 1) {
        return new float(3.1f);
    } else if(NUM_DECIMALS == 2) {
        return new float(3.14f);
    } else {
        return new float(22.f / 7.f); // sure, approximate it poorly​
    }
}

float* circle_area(const float * const P_PI, const float R) {
  return new float( *P_PI * R * R);
}

int main() {


    // const float * pPi = new float(3.14f); // Cannot chnage the value being pointed at. Can change pointer itself

    // float * const pPi = new float(3.14f); // Cannot change the pointer address but can change the value

    // const float * const P_PI0 = generatePiPrecision(0);
    // const float * const P_PI1 = generatePiPrecision(1);
    // const float * const P_PI2 = generatePiPrecision(2);
    // const float * const P_PI3 = generatePiPrecision(3);

    // float radius = 10.0f;
    // const float RADIUS  = 10.0f;
    // cout << "Area of a circle with radius 10:\n" 
    //      << *(circle_area(P_PI0, radius)) << " 0 digits of pi\n"
    //      << *(circle_area(P_PI1, RADIUS)) << " 1 digits of pi\n"
    //      << *(circle_area(P_PI2, 10)) << " 2 digits of pi\n"
    //      << *(circle_area(P_PI3, 10)) << " approximating pi\n";



    
    Zombie bill( "Bill" );
    Zombie* pTed = new Zombie( "Ted" );

    //Bill = Calle & Ted = Target
    bill.greet( pTed );

    //If a function is const. Everything all functions must also be const.

    return 0;
} 
