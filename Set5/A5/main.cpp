/* CSCI 200: A5 - SFML: Polygon Land
 *
 * Author: Christian Brennan
 *
 * Description:
 *    Reads in a list of polygon data from a .dat file and
 *    draws an image comprised of those simple polygons.
 *    Can draw 3 types of triangles. and a Rhombus
 * 
 *    Help reviced: Google, Stackoverflow, W3schools
 * 
 */


#include "Coordinate.h"
#include "Polygon.h"
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




    // Take in file here-------------------------------------------File In Here---------------------------------------File In Here :)
    //Did not include polygons.dat because assignmnet said not to.
    ifstream fin("polygons.dat");

    fin.precision(16);

    //Check for eerr
    if(fin.fail()) {
        cerr << "Error occured when trying to read in the polygons.dat file";
        return -1;
    }
    char letterId;


    //Read in the file then display
    while(!fin.eof()) {

        fin >> letterId;

        if(letterId == 'E' || letterId == 'I' || letterId == 'S') {  //Check for triangle.
            double cord1 = 0;
            double cord2 = 0;
            double cord3 = 0;
            double cord4 = 0;
            double cord5 = 0;
            double cord6 = 0;
            double colorR = 0;
            double colorG = 0;
            double colorB = 0;
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
            if(letterId == 'E') { //If E read in
                EquilateralTriangle *e1 = new EquilateralTriangle();
                e1->setCoordinate(0,holder1);
                e1->setCoordinate(1,holder2);
                e1->setCoordinate(2,holder3);
                e1->setColor(Color(colorR,colorG,colorB));
                if(!(e1->validate())) {
                    cout << "polygon is invalid - " << letterId << " " << cord1 << " " << cord2 << " " << cord3 << " " << cord4 << " " << cord5 << " " << cord6 << " " << colorR << " " << colorG << " " << colorB << endl;
                } else {
                    theDrawList.push_back(e1);
                }
            } else if(letterId == 'I') { //I
                IsoscelesTriangle *e2 = new IsoscelesTriangle();
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
                ScaleneTriangle *e3 = new ScaleneTriangle();
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
            double cord1 = 0;
            double cord2 = 0;
            double cord3 = 0;
            double cord4 = 0;
            double cord5 = 0;
            double cord6 = 0;
            double cord7 = 0;
            double cord8 = 0;
            double colorR = 0;
            double colorG = 0;
            double colorB = 0;

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
            fin >> colorR;
            fin >> colorG;
            fin >> colorB;
            Rhombus *r1 = new Rhombus();
            r1->setCoordinate(0,holder1);
            r1->setCoordinate(1,holder2);
            r1->setCoordinate(2,holder3);
            r1->setCoordinate(3,holder4);
            r1->setColor(Color(colorR,colorG,colorB));

            if(!(r1->validate())) {
                cout << "polygon is invalid - " << letterId << " " << cord1 << " " << cord2 << " " << cord3 << " " << cord4 << " " << cord5 << " " << cord6 << " " << cord7 << " " << cord8 << " " << colorR << " " << colorG << " " << colorB << endl;
            } else {
                theDrawList.push_back(r1);
            }
        }


    }

    fin.clear();

    Event event;

    const int screenW = 640;
    const int screenH = 640;
    RenderWindow window( VideoMode(screenW, screenH), "A5 SFML" );
    while( window.isOpen() ) {
        window.clear( Color::Black );
        for(size_t i = 0; i < theDrawList.size(); i++) {
            theDrawList.at(i)->draw(window);
        }


        window.display();

    


     while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
    }

    //No memory leak :)
    for(size_t i = 0; i < theDrawList.size(); i++) {
        delete theDrawList.at(i);
        theDrawList.at(i) = nullptr;
    }

    return 0;
}

