#include "Polygon.h"
#include "Coordinate.h"


using namespace sf;
using namespace std;



Polygon::Polygon() {
    theColor = Color(Color::White);
    numVert = 0;
    coordArray = new Coordinate[numVert]; 

}

Polygon::~Polygon() {
    delete coordArray;
}


void Polygon::setColor(const sf::Color color) {
    theColor = color;
}

void Polygon::setCoordinate(int idx, Coordinate coord) {
    coordArray = new Coordinate[numVert];
    coordArray[idx] = coord;
}

void Polygon::draw(sf::RenderTarget& window) {
    ConvexShape convex;
    convex.setPointCount(numVert);
    for(int i = 0; i < numVert; i++) {
        convex.setPoint(i, Vector2f(coordArray[i].x, coordArray[i].y));
    }
    window.draw(convex);
}




