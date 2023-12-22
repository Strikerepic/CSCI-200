#include "Frame.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <ctime>
using namespace sf;
using namespace std;

Frame::Frame() {
    _throw1Pins = 0;
    _throw2Pins = 0;
    _wasSpare = false;
    _wasStrike = false;

    _totalFrameScore = 0;

}

void Frame::calcFrameScore() {
    _totalFrameScore = _throw1Pins + _throw2Pins;
    if(_throw1Pins == 10) {
        _wasStrike = true;
    } else if (_throw1Pins + _throw2Pins == 10) {
        _wasSpare = true;
    }
}

int Frame::getThrow1Pins() {
    return _throw1Pins;
}

int Frame::getThrow2Pins() {
    return _throw2Pins;
}

int Frame::getDrawnFrameHeight() {
    return _drawnFrameHeight;
}

int Frame::getDrawnFrameWidth() {
    return _drawnFrameWidth;
}

void Frame::setTotalFrameScore(int newTotal) {
    _totalFrameScore = newTotal;
}

int Frame::getFrameScore() {
    return _totalFrameScore;
}

bool Frame::getStrike() {
    return _wasStrike;
}

bool Frame::getSpare() {
    return _wasSpare;
}


void Frame::setFrameScore(int a, int b) {
    _throw1Pins = a;
    _throw2Pins = b;
    calcFrameScore();
}

void Frame::draw(sf::RenderTarget& window,int leftX, int topY) {
    
    //Setting all the Texts
    Font myFont;
    if( !myFont.loadFromFile( "assets/VeraMono.ttf" ) ) {
            cerr << "Couldn't Locate the type font from the data file." << endl;
            throw runtime_error("Could not find type font.");
    }
    Text throw1Text;
    throw1Text.setFont( myFont );
    Text throw2Text;
    throw2Text.setFont( myFont);
    Text combinedFrameScore;
    combinedFrameScore.setFont(myFont);
    _drawnFrameWidth = 120;
    _drawnFrameHeight = 110;
    RectangleShape backGround;
    backGround.setFillColor(Color::White);
    backGround.setSize(Vector2f(_drawnFrameWidth,_drawnFrameHeight));
    backGround.setPosition(leftX,topY);
    backGround.setOutlineColor(Color::Black);
    backGround.setOutlineThickness(1);
    window.draw(backGround);


    //Setting rectangles for the rolled pins to go
    RectangleShape box1;
    box1.setPosition(leftX+80,topY);
    box1.setSize(Vector2f(40.0f,40.0f));
    box1.setOutlineColor(Color::Black);
    box1.setOutlineThickness(1);
    window.draw(box1);

    RectangleShape box2;
    box2.setPosition(leftX+40,topY);
    box2.setSize(Vector2f(40.0f,40.0f));
    box2.setOutlineColor(Color::Black);
    box2.setOutlineThickness(1);
    window.draw(box2);

    
    //Displaying text for each Pin
    if(_wasStrike) {
        throw1Text.setString("X");
    } else if(_throw1Pins == 0) {
        throw1Text.setString("-");
    } else {
        throw1Text.setString(to_string(_throw1Pins));
    }
    throw1Text.setFillColor(Color::Black);
    throw1Text.setCharacterSize(32);

    if(_wasSpare) {
        throw2Text.setString("/");
    } else if (_throw2Pins == 0) {
        throw2Text.setString("-");
    } else {
        throw2Text.setString(to_string(_throw2Pins));
    }
    throw2Text.setFillColor(Color::Black);
    throw2Text.setCharacterSize(32);


    throw1Text.setPosition(leftX+50,topY);
    window.draw(throw1Text);

    throw2Text.setPosition(leftX+90,topY); 
    window.draw(throw2Text);

    combinedFrameScore.setString(to_string(_totalFrameScore));
    combinedFrameScore.setFillColor(Color::Black);
    combinedFrameScore.setCharacterSize(48);



    RectangleShape subRectForCentering;
    subRectForCentering.setSize(Vector2f(_drawnFrameWidth,70));
    subRectForCentering.setPosition(leftX,topY+40);
    subRectForCentering.setFillColor(Color::Red);
    combinedFrameScore.setOrigin(combinedFrameScore.getGlobalBounds().getSize() / 2.f + combinedFrameScore.getLocalBounds().getPosition());
    combinedFrameScore.setPosition(subRectForCentering.getPosition() + (subRectForCentering.getSize() / 2.f));


    window.draw(combinedFrameScore);    

    

}