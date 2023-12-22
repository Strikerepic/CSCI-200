
#include "FinalFrame.h"
#include "Frame.h"
#include <iostream>

using namespace sf;
using namespace std;




FinalFrame::FinalFrame() {
    _throw1Pins = 0;
    _throw2Pins = 0;
    _throw3Pins = 0;
    _wasSpare = false;
    _wasStrike = false;

    _totalFrameScore = 0;

}

int FinalFrame::getFrameScore() {
    return _totalFrameScore;
}

FinalFrame::FinalFrame(int a, int b, int c) {
    _throw1Pins = a;
    _throw2Pins = b;
    _throw3Pins = c;
    calcFrameScore();
}

void FinalFrame::calcFrameScore() {
    _totalFrameScore = _throw1Pins + _throw2Pins + _throw3Pins;
    if(_throw1Pins == 10) {
        _wasStrike = true;
    }
}

void FinalFrame::draw(sf::RenderTarget& window,int leftX, int topY) {

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
    Text throw3Text;
    throw3Text.setFont( myFont );
    Text combinedFrameScore;
    combinedFrameScore.setFont(myFont);

    RectangleShape backGround;
    backGround.setFillColor(Color::White);
    _drawnFrameWidth = 120;
    _drawnFrameHeight = 110;
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


    RectangleShape box3;
    box3.setPosition(leftX,topY);
    box3.setSize(Vector2f(40.0f,40.0f));
    box3.setOutlineColor(Color::Black);
    box3.setOutlineThickness(1);
    window.draw(box3);



    
    //Displaying text for each Pin
    if(_throw1Pins == 10) {
        throw1Text.setString("X");
    } else if(_throw1Pins == 0) {
        throw1Text.setString("-");
    } else {
        throw1Text.setString(to_string(_throw1Pins));
    }

    throw1Text.setFillColor(Color::Black);
    throw1Text.setCharacterSize(32);

    if(_throw1Pins + _throw2Pins >= 10) {
        throw2Text.setString("/");
    }
    if (_throw2Pins == 10) {
        throw2Text.setString("X");
    } else {
        throw2Text.setString(to_string(_throw2Pins));
    }

    if(_throw2Pins == 0) {
        throw2Text.setString("-");
    }

    throw2Text.setFillColor(Color::Black);
    throw2Text.setCharacterSize(32);


    if (_throw3Pins == 0) {
        throw3Text.setString("-");
    } else if (_throw3Pins == 10) {
        throw3Text.setString("X");
    } else {
        throw3Text.setString(to_string(_throw3Pins));
    }

    throw3Text.setFillColor(Color::Black);
    throw3Text.setCharacterSize(32);

    throw1Text.setPosition(leftX+10,topY);
    window.draw(throw1Text);

    throw2Text.setPosition(leftX+50,topY);
    window.draw(throw2Text);

    throw3Text.setPosition(leftX+90,topY);
    window.draw(throw3Text);

    

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