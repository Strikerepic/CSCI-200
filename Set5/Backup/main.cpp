#include "Polygon.h"
#include "Coordinate.h"
#include "Triangle.h"
#include "ScaleneTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "Rhombus.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using namespace sf;



int main() {

    vector<Polygon*> theDrawList;

    ifstream fin("polygons.dat");


    if(fin.fail()) {
        cerr << "Error occured when trying to read in the polygons.dat file";
        return -1;
    }
    char letterId;


    while(!fin.eof()) {
        fin >> letterId;
        if(letterId == 'E' || letterId == 'I' || letterId == 'S') {  //Check for triangle.
            int cord1 = 0;
            int cord2 = 0;
            int cord3 = 0;
            int cord4 = 0;
            int cord5 = 0;
            int cord6 = 0;
            int colorR = 0;
            int colorG = 0;
            int colorB = 0;
            fin >> cord1;
            fin >> cord2;
            Coordinate holder1(cord1,cord2);
            fin >> cord3;
            fin >> cord4;
            Coordinate holder2(cord3,cord4);
            fin >> cord5;
            fin >> cord6;
            Coordinate holder3(cord5,cord6);
            fin >> colorR;
            fin >> colorG;
            fin >> colorB;
            if(letterId == 'E') {
                EquilateralTriangle *e1;
                e1->setCoordinate(0,holder1);
                e1->setCoordinate(1,holder2);
                e1->setCoordinate(2,holder3);
                e1->setColor(Color(colorR,colorG,colorB));
                if(!(e1->validate())) {
                    cout << "polygon is invalid - " << letterId << " " << cord1 << " " << cord2 << " " << cord3 << " " << cord4 << " " << cord5 << " " << cord6 << " " << colorR << " " << colorG << " " << colorB << endl;
                } else {
                    theDrawList.push_back(e1);
                }
            } else if(letterId == 'I') {
                IsoscelesTriangle *e2;
                e2->setCoordinate(0,holder1);
                e2->setCoordinate(1,holder2);
                e2->setCoordinate(2,holder3);
                e2->setColor(Color(colorR,colorG,colorB));
                if(!(e2->validate())) {
                    cout << "polygon is invalid - " << letterId << " " << cord1 << " " << cord2 << " " << cord3 << " " << cord4 << " " << cord5 << " " << cord6 << " " << colorR << " " << colorG << " " << colorB << endl;
                } else {
                    theDrawList.push_back(e2);
                }
            }
            else {
                IsoscelesTriangle *e3;
                e3->setCoordinate(0,holder1);
                e3->setCoordinate(1,holder2);
                e3->setCoordinate(2,holder3);
                e3->setColor(Color(colorR,colorG,colorB));
                if(!(e3->validate())) {
                    cout << "polygon is invalid - " << letterId << " " << cord1 << " " << cord2 << " " << cord3 << " " << cord4 << " " << cord5 << " " << cord6 << " " << colorR << " " << colorG << " " << colorB << endl;
                } else {
                    theDrawList.push_back(e3);
                }
            }
        } else {
            int cord1 = 0;
            int cord2 = 0;
            int cord3 = 0;
            int cord4 = 0;
            int cord5 = 0;
            int cord6 = 0;
            int cord7 = 0;
            int cord8 = 0;
            int colorR = 0;
            int colorG = 0;
            int colorB = 0;

            fin >> cord1;
            fin >> cord2;
            Coordinate holder1(cord1,cord2);
            fin >> cord3;
            fin >> cord4;
            Coordinate holder2(cord3,cord4);
            fin >> cord5;
            fin >> cord6;
            Coordinate holder3(cord5,cord6);
            fin >> cord7;
            fin >> cord8;
            Coordinate holder4(cord7,cord8);

            Rhombus *r1;
            r1->setCoordinate(0,holder1);
            r1->setCoordinate(1,holder2);
            r1->setCoordinate(2,holder3);
            r1->setCoordinate(3,holder4);
            r1->setColor(Color(colorR,colorG,colorB));
        }
    }



    int screenW = 640;
    int screenH = 640;
    RenderWindow window( VideoMode(screenW, screenH), "Brug Momment" );
    while( window.isOpen() ) {
        window.clear( Color::Black );


        for(size_t i = 0; i < theDrawList.size(); i++) {
            theDrawList.at(i)->draw(window);
        }

        window.display();

    }
}

