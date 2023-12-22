#include "Warehouse.hpp"

#include "Box.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Made Warehouse H with 2 boxes" << endl;
  Warehouse<Box> warehouseH;
  warehouseH.store( Box(4) );
  warehouseH.store( Box(2) );
  cout << "H: " << warehouseH << endl;

  cout << endl << "Setting Box 0 to size 5" << endl;
  warehouseH.retrieve(0).setBoxSize(5);
  cout << "H: " << warehouseH << endl;

  cout << endl << "Made Warehouse C with 3 strings" << endl;
  Warehouse<string> warehouseC;
  warehouseC.store( "This" );
  warehouseC.store( "Is" );
  warehouseC.store( "template" );
  cout << "C: " << warehouseC << endl;

  cout << endl << "Manipulating strings 1 and 2" << endl;
  warehouseC.retrieve(1) = "is";
  warehouseC.retrieve(2) += "d.";
  cout << "C: " << warehouseC << endl;

  return 0;
}
