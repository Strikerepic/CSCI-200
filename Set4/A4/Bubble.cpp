#include "Bubble.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

Bubble::Bubble() {
    _xDir = 0;
    _yDir = 0;
    _ballRadius = 15;
    _theCircle.setRadius(_ballRadius);

}

Bubble::Bubble(double xDir, double yDir) {
    _ballRadius = 15;
    _theCircle.setRadius(_ballRadius);
    _xDir = xDir;
    _yDir = yDir;
    
}

Bubble::Bubble(double xDir, double yDir, int xCord, int yCord) {
    _ballRadius = 15;
    _theCircle.setRadius(_ballRadius);
    _xDir = xDir;
    _yDir = yDir;
    _theCircle.setPosition( Vector2f(xCord,yCord));

}


Bubble::Bubble(double xDir, double yDir, int xStart, int yStart, Color ballColor, int ballRadius) {
    _ballRadius = ballRadius;
    _theCircle.setRadius(_ballRadius);
    _xDir = xDir;
    _yDir = yDir;
    _theCircle.setPosition( Vector2f(xStart,yStart));
    _theCircle.setFillColor(ballColor);
    _theCircle.setRadius(_ballRadius);
}


void Bubble::draw(RenderWindow &window) {
    window.draw(_theCircle);
}

double Bubble::getXDir() {
    return _xDir;
}

double Bubble::getYDir() {
    return _yDir;
}


void Bubble::updatePosition(int windowW, int windowH) {
    Vector2f current = _theCircle.getPosition();
    //Check for width bondary excpetions. Only way to reach is due to y so invert it.

    if(current.x + (_ballRadius*2) > windowW) {
        _xDir = _xDir * -1;
    }

    if(current.x < 0) {
        _xDir = _xDir * -1;
    }

    if(current.y + (_ballRadius*2) > windowH) {
        _yDir = _yDir * -1;
    }

    if(current.y < 0) {
        _yDir = _yDir * -1;
    }

    current.x = current.x + _xDir;
    current.y = current.y + _yDir;
    _theCircle.setPosition(current);
}

