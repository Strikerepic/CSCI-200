/* CSCI 200: Lab 4C - SFML: Bob Ross
 *
 * Author: Christian Brennan
 *
 * Description:
 *   Got familar with the SFML API and make a meme board with a bunch of custom memes that I made for this class. I tried really
 *   hard to make the memes funny. Prof Scholten laughed at them too!
 * 
 */



#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>     //for using the function sleep
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    
    srand(time(0));
    // create a window
    int screenW = 900;
    int screenH = 900;
    RenderWindow window( VideoMode(screenW, screenH), "SFML Test" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;


    Font myFont;
        if( !myFont.loadFromFile( "data/arial.ttf" ) ) {
            cerr << "Couldn't Locate the Arial type font from the data file." << endl;
            return -1;
        }

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
         window.clear( Color::Black );
        /////////////////////////////////////
        // BEGIN DRAWING HERE

        for(int i = 0; i < screenW; i+= screenH/20) {
            int rando = ((rand()/screenH))-85;
            for(int j = rando; j < screenW; j+= screenW/28) {
                CircleShape triangle(5,3);
                triangle.setPosition( Vector2f(i,j));
                if( j%3 == 0) {
                    triangle.setFillColor(Color::Blue);
                } else if (j%5 == 0) {
                    triangle.setFillColor(Color::Red); 
                } else if (j%7 == 0) {
                    triangle.setFillColor(Color::Green); 
                } else {
                    triangle.setFillColor(Color::White);
                }
                window.draw(triangle);
            }
            
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(12));
        
        

        RectangleShape memeBoard;

        memeBoard.setSize( Vector2f((screenW/7)*5, (screenH/7)*5 ));
        memeBoard.setPosition(screenW/7,screenH/7);
        memeBoard.setFillColor( Color(202,164,114));
        memeBoard.setOutlineThickness(5);
        memeBoard.setOutlineColor(Color(102,51,0));

        RectangleShape titlePart;


        titlePart.setSize( Vector2f((screenW/10)*5, (screenH/20) ));
        titlePart.setPosition(((screenW/10)*5)/2,screenH/20);
        titlePart.setFillColor( Color(202,164,114,200));
        titlePart.setOutlineThickness(5);
        titlePart.setOutlineColor(Color(102,51,0));

        // place in drawing section
        Text label;
        label.setFont( myFont );
        label.setString( "CSCI-200 Memes (Please I want XC)" );
        label.setPosition( screenW-620, screenH/15);
        label.setFillColor( Color::White );
        label.setCharacterSize(24);


        Texture angymeme;
        if(!(angymeme.loadFromFile("data\\DogMeme.png"))) {
            cerr << "Couldn't Find the DogMeme.png file needed to load the memes into the Render Window. Program will now end" << endl;
            return -1;
        }

        Sprite spriteAngy(angymeme);
        spriteAngy.setScale(Vector2f(0.4,0.4));
        spriteAngy.setPosition(175,190);




        Texture what;
        if(!(what.loadFromFile("data\\LeastMeme.jpg"))) {
            cerr << "Couldn't Find the LeastMeme.png file needed to load the memes into the Render Window." << endl << " PNG should be in the data folder. With the data folder being in the same director as this program. Program will now end" << endl;
            return -1;
        }

        Sprite spritewhat(what);
        spritewhat.setScale(Vector2f(0.3,0.3));
        spritewhat.setPosition(450,160);



        Texture point;
        if(!(point.loadFromFile("data\\PointerMeme3.jpg"))) {
            cerr << "Couldn't Find the PointerMeme3.jpg file needed to load the memes into the Render Window." << endl << "JPG should be in the data folder. With the data folder being in the same director as this program. Program will now end" << endl;
            return -1;
        }

        Sprite spritepoint(point);
        spritepoint.setScale(Vector2f(0.2,0.2));
        spritepoint.setPosition(430,420);
        

       




        
        // place any draw commands here to display in the window
        window.draw(memeBoard);
        window.draw(titlePart);
        window.draw( label ); 
        window.draw(spriteAngy);
        window.draw(spritewhat);
        window.draw(spritepoint);

        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}
