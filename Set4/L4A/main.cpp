/* CSCI 200: Lab 4A - Inventory Management
 *
 * Author: Christian Brennan
 *
 * Description:
 *   Override the big 3 on the warehouse. Create a copy constructor, Copy assignment operator, and Destructor.
 * 
 *    Help reviced: Google, And Office Hours help from a T.A. (Forgot Name. He had a super cool mullet) On 10/23
 * 
 */


#include "Warehouse.h"

#include <iostream>
using namespace std;

void print_warehouse(Warehouse wh) {
  cout << "Function warehouse: " << wh << endl;
}

int main() {
    cout << "Made Warehouse H with 2 boxes" << endl;
    Warehouse warehouseH;
    warehouseH.storeInBox(4);
    warehouseH.storeInBox(2);
    cout << "H: " << warehouseH << endl;

    cout << endl << "Made Warehouse C with 1 box" << endl;
    Warehouse warehouseC;
    warehouseC.storeInBox(3);
    cout << "C: " << warehouseC << endl;

    cout << endl << "Using copy assignment operator to copy from H to C, both have 2 boxes" << endl;
    warehouseC = warehouseH;
    cout << "H: " << warehouseH << endl;
    cout << "C: " << warehouseC << endl;

    cout << endl << "Adding to H, H has 3 and C has 2" << endl;
    warehouseH.storeInBox(3);
    cout << "H: " << warehouseH << endl;
    cout << "C: " << warehouseC << endl;

    cout << endl << "Adding to C, H has 3 and C has 3" << endl;
    warehouseC.storeInBox(7);
    cout << "H: " << warehouseH << endl;
    cout << "C: " << warehouseC << endl;

    cout << endl << "Changing H Box 1 from size 2 to size 15" << endl;
    warehouseH.getBox(1)->setBoxSize(15);
    cout << "H: " << warehouseH << endl;
    cout << "C: " << warehouseC << endl;

    cout << endl << "Using copy constructor to make D from H, both have 3 boxes" << endl;
    Warehouse warehouseD( warehouseH );
    cout << "H: " << warehouseH << endl;
    cout << "C: " << warehouseC << endl;
    cout << "D: " << warehouseD << endl;

    cout << endl << "Adding to H, H has 4 and D has 3" << endl;
    warehouseH.storeInBox(5);
    cout << "H: " << warehouseH << endl;
    cout << "C: " << warehouseC << endl;
    cout << "D: " << warehouseD << endl;

    cout << endl << "Adding to HD H has 4 and D has 4" << endl;
    warehouseD.storeInBox(6);
    cout << "H: " << warehouseH << endl;
    cout << "C: " << warehouseC << endl;
    cout << "D: " << warehouseD << endl;

    cout << endl << "Changing H Box 2 from size 3 to size 25" << endl;
    warehouseH.getBox(2)->setBoxSize(25);
    cout << "H: " << warehouseH << endl;
    cout << "C: " << warehouseC << endl;
    cout << "D: " << warehouseD << endl;

    cout << endl << "Passing objects to function by value to print (copy constructor and destructor implicitly called)" << endl;
    print_warehouse(warehouseH);
    print_warehouse(warehouseC);
    print_warehouse(warehouseD);

    return 0;
}
